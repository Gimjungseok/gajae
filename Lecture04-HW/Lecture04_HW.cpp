//������ ������Ʈ��: Lecture04_HW
//idle : ȭ��� ���������� clear
//���콺 ������ KeyDown�ϸ� : ������
//���콺 ������ KeyUp�ϸ� : ���󺹱�
//���콺 ���� KeyDown�ϸ� : ���
//���콺 ���� KeyUp�ϸ� : ���󺹱�
//���콺 ������ KeyDown�ϰ� �巡�� ���̸� : �Ķ���
//���콺 ���� KeyDown�ϰ� �巡�� ���̸� : ����Ÿ��

//https://www.glfw.org/
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
bool isRightButtonDown = false;
bool isLeftButtonDown = false;
bool isDraggingRight = false;
bool isDraggingLeft = false;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        if (action == GLFW_PRESS) {
            isRightButtonDown = true;
            isDraggingRight = true;
        }
        else if (action == GLFW_RELEASE) {
            isRightButtonDown = false;
            isDraggingRight = false;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            isLeftButtonDown = true;
            isDraggingLeft = true;
        }
        else if (action == GLFW_RELEASE) {
            isLeftButtonDown = false;
            isDraggingLeft = false;
        }
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (isRightButtonDown) {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // ������
    }
    else if (isLeftButtonDown) {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // �ʷϻ�
    }
    else {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ������
    }

    if (isDraggingRight) {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �Ķ��� (�巡�� ��)
    }

    if (isDraggingLeft) {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // ����Ÿ�� (�巡�� ��)
    }
}

int main() {
    // GLFW �ʱ�ȭ
    if (!glfwInit()) {
       cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    // GLFW ������ ����
    GLFWwindow* window = glfwCreateWindow(1280, 768, "a", NULL, NULL);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    // �̺�Ʈ �ݹ� �Լ� ���
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    // OpenGL ���ؽ�Ʈ�� ���� �����忡 ����
    glfwMakeContextCurrent(window);

    // �̺�Ʈ ����
    while (!glfwWindowShouldClose(window)) {
        // �̺�Ʈ ó��
        glfwPollEvents();

        // OpenGL ������
        glClear(GL_COLOR_BUFFER_BIT);

        // ȭ�鿡 �������� ����� ���
        glfwSwapBuffers(window);
    }

    // GLFW ����
    glfwTerminate();
    return 0;
}