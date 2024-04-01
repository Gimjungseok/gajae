//과제물 프로젝트명: Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색

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
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 빨간색
    }
    else if (isLeftButtonDown) {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 초록색
    }
    else {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 검정색
    }

    if (isDraggingRight) {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파란색 (드래그 중)
    }

    if (isDraggingLeft) {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타색 (드래그 중)
    }
}

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
       cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    // GLFW 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(1280, 768, "a", NULL, NULL);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    // 이벤트 콜백 함수 등록
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    // OpenGL 컨텍스트를 현재 스레드에 연결
    glfwMakeContextCurrent(window);

    // 이벤트 루프
    while (!glfwWindowShouldClose(window)) {
        // 이벤트 처리
        glfwPollEvents();

        // OpenGL 렌더링
        glClear(GL_COLOR_BUFFER_BIT);

        // 화면에 렌더링된 결과를 출력
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}