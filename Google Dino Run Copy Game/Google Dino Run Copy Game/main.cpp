#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include "Object.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // GLFW �ʱ�ȭ
    if (!glfwInit()) {
        return -1;
    }

    // GLFW ������ ���� �� ����
    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // �����츦 ���� ���ؽ�Ʈ�� ����
    glfwMakeContextCurrent(window);

    // Viewport ����
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, 800, 600);

    // ���� ���� (�ϴû�: R=0, G=30, B=100)
    glClearColor(0.0f, 0.12f, 0.39f, 1.0f);

    Object player(0.0f, 0.0f, 0.5f, 0.03f);
    


    // ���� ����
    while (!glfwWindowShouldClose(window)) {
        // ���� �����
        glClear(GL_COLOR_BUFFER_BIT);

        player.Draw();
        

        

        // ���� ��ȯ
        glfwSwapBuffers(window);
        // �̺�Ʈ ó��
        glfwPollEvents();
    }

    // GLFW ����
    glfwTerminate();
    return 0;
}
