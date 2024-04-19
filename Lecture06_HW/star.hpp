#include <GLFW/glfw3.h>
#include "MSList.h"

class star
{
	float R, G, B;
	float X, Y;
public:
	star(float r, float g, float b, float x, float y) : R(r), G(g), B(b), X(x), Y(y) {}

	void render()
	{
		glBegin(GL_TRIANGLES);
		glColor3f(R, G, B);
		glVertex2f(0.032f + X, 0.012f + Y);

		glColor3f(R, G, B);
		glVertex2f(-0.032f + X, 0.012f + Y);

		glColor3f(R, G, B);
		glVertex2f(0.0f + X, -0.016f + Y);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(R, G, B);
		glVertex2f(0.0f + X, 0.04f + Y);

		glColor3f(R, G, B);
		glVertex2f(-0.02f + X, -0.032f + Y);

		glColor3f(R, G, B);
		glVertex2f(0.012f + X, -0.012f + Y);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(R, G, B);
		glVertex2f(0.0f + X, 0.04f + Y);

		glColor3f(R, G, B);
		glVertex2f(-0.012f + X, -0.012f + Y);

		glColor3f(R, G, B);
		glVertex2f(0.02f + X, -0.032f + Y);
		glEnd();
	}
};