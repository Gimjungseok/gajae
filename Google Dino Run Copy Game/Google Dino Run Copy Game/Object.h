#include <GLFW/glfw3.h>

class Player {
private:
    float size; // ���簢�� �� ���� ���� (meter)
    float borderThickness; // �׵θ� �β� (meter)

public:
    Player(float size_cm, float border_thickness_cm) {
        size = size_cm / 100.0f; // cm�� meter�� ��ȯ
        borderThickness = border_thickness_cm / 100.0f; // cm�� meter�� ��ȯ
    }

    void draw() const {
        // Draw filled red square (player)
        glColor3ub(255, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(-size / 2, -size / 2);
        glVertex2f(size / 2, -size / 2);
        glVertex2f(size / 2, size / 2);
        glVertex2f(-size / 2, size / 2);
        glEnd();

        // Draw border
        glColor3ub(0, 0, 0); // black border color
        glLineWidth(borderThickness);
        glBegin(GL_LINE_LOOP);
        glVertex2f(-size / 2, -size / 2);
        glVertex2f(size / 2, -size / 2);
        glVertex2f(size / 2, size / 2);
        glVertex2f(-size / 2, size / 2);
        glEnd();
    }
};
class Ground {
private:
    float heightFromGround; // �ٴ����κ����� ���� (meter)

public:
    Ground(float height_from_ground_cm) {
        heightFromGround = height_from_ground_cm / 100.0f; // cm�� meter�� ��ȯ
    }

    void draw() const {
        // Draw ground
        glColor3ub(255, 200, 15); // Ȳ�� (R:255, G:200, B:15)
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -heightFromGround); // ���� �Ʒ�
        glVertex2f(1.0f, -heightFromGround); // ������ �Ʒ�
        glVertex2f(1.0f, -1.0f); // ������ ��
        glVertex2f(-1.0f, -1.0f); // ���� ��
        glEnd();
    }
};
class Obstacle {
private:
    float width; // ���� ���� (meter)
    float height; // ���� ���� (meter)

public:
    Obstacle(float width_cm, float height_cm) {
        width = width_cm / 100.0f; // cm�� meter�� ��ȯ
        height = height_cm / 100.0f; // cm�� meter�� ��ȯ
    }

    void draw(float x_position) const {
        // Draw obstacle (green color)
        glColor3ub(0, 255, 0); // ��� (R:0, G:255, B:0)
        glBegin(GL_QUADS);
        glVertex2f(x_position - width / 2, -1.0f); // ���� �Ʒ�
        glVertex2f(x_position + width / 2, -1.0f); // ������ �Ʒ�
        glVertex2f(x_position + width / 2, -1.0f + height); // ������ ��
        glVertex2f(x_position - width / 2, -1.0f + height); // ���� ��
        glEnd();
    }
};