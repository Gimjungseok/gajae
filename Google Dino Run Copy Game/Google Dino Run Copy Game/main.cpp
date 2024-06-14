#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include "Object.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        return -1;
    }

    // GLFW 윈도우 생성 및 설정
    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // 윈도우를 현재 컨텍스트로 설정
    glfwMakeContextCurrent(window);

    // Viewport 설정
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, 800, 600);

    // 배경색 설정 (하늘색: R=0, G=30, B=100)
    glClearColor(0.0f, 0.12f, 0.39f, 1.0f);

    Object player(0.0f, 0.0f, 0.5f, 0.03f);
    


    // 메인 루프
    while (!glfwWindowShouldClose(window)) {
        // 버퍼 지우기
        glClear(GL_COLOR_BUFFER_BIT);

        player.Draw();
        

        

        // 버퍼 교환
        glfwSwapBuffers(window);
        // 이벤트 처리
        glfwPollEvents();
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}
