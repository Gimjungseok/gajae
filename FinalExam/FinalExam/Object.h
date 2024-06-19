#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>
extern GLFWwindow* window; // �ܺο��� ���ǵ� GLFW ������ ������

float playerX = 0.0f;
float playerY = -0.75f; // �ʱ� ��ġ (����� ����� ��ġ)
float playerSize = 0.1f; // �÷��̾� ũ��
float jumpSpeed = 5.0f;  // ���� �ӵ� m/s
float gravity = 9.81f;   // �߷� ���ӵ� m/s^2
bool isJumping = false;  // ���� ������ ����

void drawSquare();
void drawGround(float screenWidth, float screenHeight);
void drawRectangles(float screenWidth, float screenHeight);
bool checkCollision(float obstacleX, float obstacleY, float obstacleWidth, float obstacleHeight);

void drawSquare() {
    glLineWidth(3.0f);

    // ������ �׵θ�
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(playerX - playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY + playerSize / 2.0f);
    glVertex2f(playerX - playerSize / 2.0f, playerY + playerSize / 2.0f);
    glEnd();

    // ������ ���簢��
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(playerX - playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY + playerSize / 2.0f);
    glVertex2f(playerX - playerSize / 2.0f, playerY + playerSize / 2.0f);
    glEnd();

    // �߷� ����
    if (!isJumping && playerY > -0.75f) {
        float deltaTime = 1.0f / 60.0f; // �����Ӵ� �ð�
        float deltaY = gravity * deltaTime;
        if (playerY - deltaY > -0.75f) {
            playerY -= deltaY;
        }
        else {
            playerY = -0.75f;
        }
    }

    // ���� ó��
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !isJumping) {
        isJumping = true;
    }

    if (isJumping) {
        float deltaTime = 1.0f / 60.0f; // �����Ӵ� �ð�
        float deltaY = jumpSpeed * deltaTime;
        if (playerY + deltaY < 0.75f) {
            playerY += deltaY;
        }
        else {
            playerY = 0.75f;
            isJumping = false;
        }
    }
}
void drawGround(float screenWidth, float screenHeight) {
    float groundHeight = 100.0f / screenHeight * 2.0f; // Normalized device coordinates

    // ���� ���� ���� (R:255, G:200, B:15)
    glColor3f(1.0f, 0.78f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f + groundHeight);
    glVertex2f(-1.0f, -1.0f + groundHeight);
    glEnd();
}
void drawRectangles(float screenWidth, float screenHeight) {
    float rect1Width = 50.0f / screenWidth * 2.0f;  // Normalized device coordinates
    float rect1Height = 100.0f / screenHeight * 2.0f;
    float rect2Width = 50.0f / screenWidth * 2.0f;
    float rect2Height = 300.0f / screenHeight * 2.0f;

    // �ʷϻ� �簢����
    glColor3f(0.0f, 1.0f, 0.0f);

    // ù ��° �簢��
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f + rect1Width, -0.5f);
    glVertex2f(-0.5f + rect1Width, -0.5f + rect1Height);
    glVertex2f(-0.5f, -0.5f + rect1Height);
    glEnd();

    // �� ��° �簢��
    glBegin(GL_QUADS);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f + rect2Width, -0.5f);
    glVertex2f(0.5f + rect2Width, -0.5f + rect2Height);
    glVertex2f(0.5f, -0.5f + rect2Height);
    glEnd();
}
class Obstacle {
public:
    float x, y;
    float width, height;
    float speed;

    Obstacle(float startX, float obstacleWidth, float obstacleHeight, float obstacleSpeed)
        : x(startX), y(-0.715f + obstacleHeight / 2.0f), width(obstacleWidth), height(obstacleHeight), speed(obstacleSpeed) {}

    void update(float deltaTime) {
        // ��ֹ� �̵�
        x -= speed * deltaTime;

        // ȭ�� ������ ����� ȭ�� ���������� ���ġ
        if (x + width < -1.0f) {
            x = 1.0f;
        }
    }

    void draw() const {
        glColor3f(0.0f, 1.0f, 0.0f); // �ʷϻ�
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }

    bool isOffscreen() const {
        return x > 1.0f; // ȭ�� ������ ����� ����
    }
};
// �浹 �˻� �Լ� (��ֹ����� �浹 �˻�)
bool checkCollision(float obstacleX, float obstacleY, float obstacleWidth, float obstacleHeight) {
    // �÷��̾��� �浹 �ڽ� ũ��� ��ġ
    float playerLeft = playerX - playerSize / 2.0f;
    float playerRight = playerX + playerSize / 2.0f;
    float playerTop = playerY + playerSize / 2.0f;
    float playerBottom = playerY - playerSize / 2.0f;

    // ��ֹ��� �浹 �ڽ� ũ��� ��ġ
    float obstacleLeft = obstacleX - obstacleWidth / 2.0f;
    float obstacleRight = obstacleX + obstacleWidth / 2.0f;
    float obstacleTop = obstacleY + obstacleHeight / 2.0f;
    float obstacleBottom = obstacleY - obstacleHeight / 2.0f;

    // �浹 ���� �˻�
    if (playerRight >= obstacleLeft && playerLeft <= obstacleRight &&
        playerTop >= obstacleBottom && playerBottom <= obstacleTop) {
        return true;
    }
    return false;
}

#endif OBJECT_H