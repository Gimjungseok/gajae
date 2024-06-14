#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <vector>
#include "Object.h"

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Game Window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glClearColor(0.0f, 0.12f, 0.39f, 1.0f);

    // Initialize objects
    Player player(20.0f, 3.0f); // 플레이어 생성 (50cm, 3cm)
    Ground ground(10.0f); // 지면 생성 (바닥으로부터 100cm)

    std::vector<Obstacle> obstacles;
    obstacles.emplace_back(5.0f, 10.0f); // 장애물 생성 (가로 50cm, 높이 100cm)
    obstacles.emplace_back(5.0f, 30.0f); // 장애물 생성 (가로 50cm, 높이 300cm)

    float obstacleSpacing = 300.0f; // 장애물 간의 가로 간격 (임의로 설정)

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here, e.g. clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw ground
        ground.draw();

        // Draw player
        player.draw();

        // Draw obstacles
        float startX = 0.0f;
        for (const auto& obstacle : obstacles) {
            obstacle.draw(startX);
            startX += obstacleSpacing;
        }

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}