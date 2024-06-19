#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GLFW/glfw3.h>

// 화면의 물리적 크기와 OpenGL 좌표계를 변환하는 함수
float screenToGL(float screenCoord, float screenSize) {
    return (2.0f * screenCoord) / screenSize - 1.0f;
}

class ObstacleTransform {
public:
    float x, y; // OpenGL 좌표계에서의 위치
    float width, height; // OpenGL 좌표계에서의 크기
    float speed; // 장애물의 속도

    ObstacleTransform(float x, float y, float width, float height, float speed)
        : x(x), y(y), width(width), height(height), speed(speed) {}

    void update(float deltaTime) {
        // 장애물 이동
        x -= speed * deltaTime;

        // 장애물이 화면 왼쪽 끝을 넘어가면 오른쪽 끝으로 이동시킴 (재활용)
        if (x + width / 2 < -1.0f) {
            x = 1.0f + width / 2;
        }
    }

    void draw() {
        // 초록색 사각형 그리기
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x - width / 2, y - height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x - width / 2, y + height / 2);
        glEnd();
    }
};

#endif // TRANSFORM_H
