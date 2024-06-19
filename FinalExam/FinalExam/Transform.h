#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GLFW/glfw3.h>

// ȭ���� ������ ũ��� OpenGL ��ǥ�踦 ��ȯ�ϴ� �Լ�
float screenToGL(float screenCoord, float screenSize) {
    return (2.0f * screenCoord) / screenSize - 1.0f;
}

class ObstacleTransform {
public:
    float x, y; // OpenGL ��ǥ�迡���� ��ġ
    float width, height; // OpenGL ��ǥ�迡���� ũ��
    float speed; // ��ֹ��� �ӵ�

    ObstacleTransform(float x, float y, float width, float height, float speed)
        : x(x), y(y), width(width), height(height), speed(speed) {}

    void update(float deltaTime) {
        // ��ֹ� �̵�
        x -= speed * deltaTime;

        // ��ֹ��� ȭ�� ���� ���� �Ѿ�� ������ ������ �̵���Ŵ (��Ȱ��)
        if (x + width / 2 < -1.0f) {
            x = 1.0f + width / 2;
        }
    }

    void draw() {
        // �ʷϻ� �簢�� �׸���
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
