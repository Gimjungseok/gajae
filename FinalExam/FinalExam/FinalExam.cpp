#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include "Object.h"
#include <vector>
#include <iostream>

GLFWwindow* window;

const int MAX_OBSTACLES = 3;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        return -1;
    }

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Square", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // OpenGL 함수 로드
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 장애물들의 컨테이너
    std::vector<Obstacle> obstacles;

    // 변수 초기화
    bool createSmallObstacle = false; // 작은 장애물 생성 여부 플래그

   

    // 메인 루프
    while (!glfwWindowShouldClose(window)) {
        // 입력 처리
        processInput(window);

        // 시간 계산
        static double lastTime = glfwGetTime();
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // 화면 지우기
        glClearColor(0.0f, 0.12f, 0.39f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawSquare();

        // 지면 그리기
        drawGround(800, 600);


        // 장애물 업데이트 및 그리기
        for (auto& obstacle : obstacles) {
            obstacle.update(deltaTime);
            obstacle.draw();
        }

        // 새 장애물 생성 (최대 개수 제한)
        if (obstacles.size() < MAX_OBSTACLES) {
            float startX = 1.0f; // 화면 오른쪽에서 시작
            float obstacleWidth = 0.1f;
            float obstacleSpeed = 0.3f;

            float obstacleHeight = createSmallObstacle ? 0.1f : 0.3f;
            createSmallObstacle = !createSmallObstacle; // 다음 번은 다른 높이로 생성하기 위해 플래그 전환

            obstacles.emplace_back(startX, obstacleWidth, obstacleHeight, obstacleSpeed);
        }

        // 화면을 벗어난 장애물 제거
        obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), [](const Obstacle& obstacle) {
            return obstacle.isOffscreen();
            }), obstacles.end());

        // 버퍼 교체 및 이벤트 처리
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}

// 윈도우 크기 변경 콜백
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// 키 입력 처리
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
