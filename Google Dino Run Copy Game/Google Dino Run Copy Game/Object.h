#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>

class Object {
public:
    float x, y; // 물체 위치 (미터 단위, 좌측 하단 기준)
    float size; // 한 변의 길이 (미터 단위)
    float borderThickness; // 테두리 두께 (미터 단위)

    Object(float xpos, float ypos, float s, float border)
        : x(xpos), y(ypos), size(s), borderThickness(border) {}

    void Draw() const;
};

void Object::Draw() const {
    // OpenGL을 이용한 물체 그리기 코드 (예시)
    glBegin(GL_QUADS);

    // 플레이어 (빨간색 정사각형)
    glColor3ub(255, 0, 0); // 빨간색
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);

    // 플레이어 테두리 (검정색 테두리)
    glColor3ub(255, 0, 0); // 검정색
    glVertex2f(x - borderThickness, y - borderThickness);
    glVertex2f(x + size + borderThickness, y - borderThickness);
    glVertex2f(x + size + borderThickness, y + size + borderThickness);
    glVertex2f(x - borderThickness, y + size + borderThickness);

    glEnd();
}

#endif // OBJECT_H
