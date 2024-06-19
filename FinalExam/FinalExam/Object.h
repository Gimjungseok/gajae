#ifndef OBJECT_H
#define OBJECT_H
GLFWwindow* window;

#include <GLFW/glfw3.h>
float playerX = 0.0f;
float playerY = -0.61f; // 초기 위치 (지면과 가까운 위치)
float playerSize = 0.1f; // 플레이어 크기
float jumpSpeed = 2.0f;  // 점프 속도 m/s
float gravity = 1.0f;   // 중력 가속도 m/s^2
bool isJumping = false;  // 점프 중인지 여부
float jumpStartY = 0.0f;
float maxJumpHeight = 0.5f; // 최대 점프 높이

void drawSquare();
void drawGround(float screenWidth, float screenHeight);
void drawRectangles(float screenWidth, float screenHeight);
bool checkCollision(float obstacleX, float obstacleY, float obstacleWidth, float obstacleHeight);

void drawSquare() {
    glLineWidth(3.0f);

    // 검은색 테두리
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(playerX - playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY + playerSize / 2.0f);
    glVertex2f(playerX - playerSize / 2.0f, playerY + playerSize / 2.0f);
    glEnd();

    // 빨간색 정사각형
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(playerX - playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY - playerSize / 2.0f);
    glVertex2f(playerX + playerSize / 2.0f, playerY + playerSize / 2.0f);
    glVertex2f(playerX - playerSize / 2.0f, playerY + playerSize / 2.0f);
    glEnd();

    // 중력 적용
    if (!isJumping && playerY > -0.61f) {
        float deltaTime = 1.0f / 60.0f; // 프레임당 시간
        float deltaY = gravity * deltaTime;
        if (playerY - deltaY > -0.61f) {
            playerY -= deltaY;
        }
        else {
            playerY = -0.61f;
        }
    }

    // 점프 처리
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !isJumping) {
        isJumping = true;
        jumpStartY = playerY; // 현재 위치에서 점프 시작
    }

    if (isJumping) {
        float deltaTime = 1.0f / 60.0f; // 프레임당 시간
        float deltaY = jumpSpeed * deltaTime;
        if (playerY + deltaY < jumpStartY + maxJumpHeight) { // 최대 점프 높이까지 점프
            playerY += deltaY;
        }
        else {
            playerY = jumpStartY + maxJumpHeight; // 최대 높이에 도달하면 멈춤
            isJumping = false; // 점프 종료
        }
    }
}

void drawGround(float screenWidth, float screenHeight) {
    float groundHeight = 100.0f / screenHeight * 2.0f; // Normalized device coordinates

    // 지면 색깔 설정 (R:255, G:200, B:15)
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

    // 초록색 사각형들
    glColor3f(0.0f, 1.0f, 0.0f);

    // 첫 번째 사각형
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f + rect1Width, -0.5f);
    glVertex2f(-0.5f + rect1Width, -0.5f + rect1Height);
    glVertex2f(-0.5f, -0.5f + rect1Height);
    glEnd();

    // 두 번째 사각형
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
        // 장애물 이동
        x -= 1 * deltaTime;

        // 화면 왼쪽을 벗어나면 화면 오른쪽으로 재배치
        if (x + width < -1.0f) {
            x = 0.5f;
        }
    }

    void draw() const {
        glColor3f(0.0f, 1.0f, 0.0f); // 초록색
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }

    bool isOffscreen() const {
        return x > 1.0f; // 화면 왼쪽을 벗어나면 삭제
    }

    // 플레이어와의 충돌 검사
    bool checkCollisionWithPlayer() const {
        // 플레이어의 충돌 박스 크기와 위치
        float playerLeft = playerX - playerSize / 2.0f;
        float playerRight = playerX + playerSize / 2.0f;
        float playerTop = playerY + playerSize / 2.0f;
        float playerBottom = playerY - playerSize / 2.0f;

        // 장애물의 충돌 박스 크기와 위치
        float obstacleLeft = x - width / 2.0f;
        float obstacleRight = x + width / 2.0f;
        float obstacleTop = y + height / 2.0f;
        float obstacleBottom = y - height / 2.0f;

        // 충돌 여부 검사
        if (playerRight >= obstacleLeft && playerLeft <= obstacleRight &&
            playerTop >= obstacleBottom && playerBottom <= obstacleTop) {
            return true;
        }
        return false;
    }
};

#endif // OBJECT_H