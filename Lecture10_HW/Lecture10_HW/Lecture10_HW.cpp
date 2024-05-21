#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

const float SUN_RADIUS = 30.0f;
const float EARTH_SIDE = 20.0f; // 정사각형 한 변의 길이

const float SUN_RADIUS1 = 10.0f;

const float SUN_RADIUS2 = 6.0f;

const float MOON_RADIUS = 5.0f;

float earthAngle = 0.0f;
float moonAngle = 0.0f;

// 원 그리기 함수
void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; ++i) {
        glVertex2f(x + radius * cos(i * 3.14159265f / 180.0f), y + radius * sin(i * 3.14159265f / 180.0f));
    }
    glEnd();
}

// 별 모양 그리기 함수
void drawStar(float x, float y, float radius) {
    glColor3f(1.0f, 1.0f, 1.0f); // 흰색
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 5; ++i) {
        float angle = (i * 4 * 3.14159265f / 5) - 3.14159265f / 2;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
        angle = ((i + 0.5f) * 4 * 3.14159265f / 5) - 3.14159265f / 2;
        glVertex2f(x + radius * 0.5f * cos(angle), y + radius * 0.5f * sin(angle));
    }
    glEnd();
}

// 태양 그리기 함수
void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f); // 노란색
    drawCircle(WIDTH / 2, HEIGHT / 2, SUN_RADIUS); // 원을 그려 태양을 표현
}

void drawSunColor()
{
    glColor3f(1.0f, 1.0f, 0.8f); // 노란색
    drawCircle(WIDTH / 2.05f, HEIGHT / 2.05f, SUN_RADIUS1); // 원을 그려 태양을 표현
}
void drawSunColor2()
{
    glColor3f(0.5f, 0.4f, 0.3f); // 노란색
    drawCircle(WIDTH / 1.925f, HEIGHT / 1.925f, SUN_RADIUS2);
}

// 지구 그리기 함수
void drawEarth() {
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색
    float earthX = WIDTH / 2 + 200.0f * cos(earthAngle); // 태양 주위를 공전하는 지구의 X 좌표
    float earthY = HEIGHT / 2 + 200.0f * sin(earthAngle); // 태양 주위를 공전하는 지구의 Y 좌표
    glRectf(earthX - EARTH_SIDE / 2, earthY - EARTH_SIDE / 2, earthX + EARTH_SIDE / 2, earthY + EARTH_SIDE / 2); // 정사각형으로 지구를 그림
}

// 달 그리기 함수
void drawMoon() {
    glColor3f(0.7f, 0.7f, 0.7f); // 회색
    float moonX = WIDTH / 2 + 200.0f * cos(earthAngle) + 50.0f * cos(moonAngle); // 지구 주위를 공전하는 달의 X 좌표
    float moonY = HEIGHT / 2 + 200.0f * sin(earthAngle) + 50.0f * sin(moonAngle); // 지구 주위를 공전하는 달의 Y 좌표
    drawStar(moonX, moonY, MOON_RADIUS); // 별 모양으로 달을 그림
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT); // 이전의 그림을 지움
    drawSun(); // 태양 그리기
    drawSunColor();
    drawSunColor2();
    drawEarth(); // 지구 그리기
    drawMoon(); // 달 그리기
}

// 업데이트 함수
void update() {
    earthAngle += 0.01f; // 지구의 공전 속도
    moonAngle += 0.05f;  // 달의 공전 속도
}

int main() {
    GLFWwindow* window;

    if (!glfwInit()) // GLFW 초기화
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "star", NULL, NULL); // 윈도우 생성
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // 현재 컨텍스트를 윈도우로 설정

    glOrtho(0, WIDTH, HEIGHT, 0, 0, 1); // 2D 좌표 시스템 설정

    while (!glfwWindowShouldClose(window)) {
        update(); // 업데이트
        draw(); // 그리기
        glfwSwapBuffers(window); // 버퍼 교체
        glfwPollEvents(); // 이벤트 처리
    }

    glfwTerminate(); // GLFW 종료
    return 0;
}