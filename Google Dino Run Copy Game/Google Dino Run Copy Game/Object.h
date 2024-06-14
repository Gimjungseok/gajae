#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>

class Object {
public:
    float x, y; // ��ü ��ġ (���� ����, ���� �ϴ� ����)
    float size; // �� ���� ���� (���� ����)
    float borderThickness; // �׵θ� �β� (���� ����)

    Object(float xpos, float ypos, float s, float border)
        : x(xpos), y(ypos), size(s), borderThickness(border) {}

    void Draw() const;
};

void Object::Draw() const {
    // OpenGL�� �̿��� ��ü �׸��� �ڵ� (����)
    glBegin(GL_QUADS);

    // �÷��̾� (������ ���簢��)
    glColor3ub(255, 0, 0); // ������
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);

    // �÷��̾� �׵θ� (������ �׵θ�)
    glColor3ub(255, 0, 0); // ������
    glVertex2f(x - borderThickness, y - borderThickness);
    glVertex2f(x + size + borderThickness, y - borderThickness);
    glVertex2f(x + size + borderThickness, y + size + borderThickness);
    glVertex2f(x - borderThickness, y + size + borderThickness);

    glEnd();
}

#endif // OBJECT_H
