#include <GLFW/glfw3.h>

class Player {
private:
    float size; // 정사각형 한 변의 길이 (meter)
    float borderThickness; // 테두리 두께 (meter)

public:
    Player(float size_cm, float border_thickness_cm) {
        size = size_cm / 100.0f; // cm를 meter로 변환
        borderThickness = border_thickness_cm / 100.0f; // cm를 meter로 변환
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
    float heightFromGround; // 바닥으로부터의 높이 (meter)

public:
    Ground(float height_from_ground_cm) {
        heightFromGround = height_from_ground_cm / 100.0f; // cm를 meter로 변환
    }

    void draw() const {
        // Draw ground
        glColor3ub(255, 200, 15); // 황색 (R:255, G:200, B:15)
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -heightFromGround); // 왼쪽 아래
        glVertex2f(1.0f, -heightFromGround); // 오른쪽 아래
        glVertex2f(1.0f, -1.0f); // 오른쪽 위
        glVertex2f(-1.0f, -1.0f); // 왼쪽 위
        glEnd();
    }
};
class Obstacle {
private:
    float width; // 가로 길이 (meter)
    float height; // 세로 길이 (meter)

public:
    Obstacle(float width_cm, float height_cm) {
        width = width_cm / 100.0f; // cm를 meter로 변환
        height = height_cm / 100.0f; // cm를 meter로 변환
    }

    void draw(float x_position) const {
        // Draw obstacle (green color)
        glColor3ub(0, 255, 0); // 녹색 (R:0, G:255, B:0)
        glBegin(GL_QUADS);
        glVertex2f(x_position - width / 2, -1.0f); // 왼쪽 아래
        glVertex2f(x_position + width / 2, -1.0f); // 오른쪽 아래
        glVertex2f(x_position + width / 2, -1.0f + height); // 오른쪽 위
        glVertex2f(x_position - width / 2, -1.0f + height); // 왼쪽 위
        glEnd();
    }
};