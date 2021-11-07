#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Dense>

float gScreenWidth = 1920;
float gScreenHeight = 1080;
float gSquareSize = 4e-6;
float hSize = gSquareSize * gScreenHeight;
float vSize = gSquareSize * gScreenWidth;

GLFWwindow* initGraphics(int *worldWidth, int *worldHeight)
{
	if (!glfwInit())
		std::cout << "Placeholder" << std::endl;
	GLFWwindow* window = glfwCreateWindow(gScreenWidth, gScreenHeight, "Rule", NULL, NULL);
	glfwMakeContextCurrent(window);
	glTranslatef(-1, -1, 0);

	// Define the size of the world based on the screen width / height
	*worldHeight = 2 / vSize;
	*worldWidth = 2 / hSize;

	return window;
}

void drawSquare(int x, int y)
{
	// Draw a square in a place
	glBegin(GL_QUADS);
	glVertex2f(x * hSize, y * vSize);
	glVertex2f(x * hSize, y * vSize + vSize);
	glVertex2f(x * hSize + hSize, y * vSize + vSize);
	glVertex2f(x * hSize + hSize, y * vSize);
	glEnd();
}

bool render(Eigen::MatrixXd world, GLFWwindow* window)
{
	// Signals the program to stop when the window is closed
	if (glfwWindowShouldClose(window))
		return true;

	// Render shapes etc
	glClear(GL_COLOR_BUFFER_BIT);

	int worldHeight = world.rows();
	int worldWidth = world.cols();
	for (size_t i = 0, size = world.size(); i < size; i++)
	{
		if ((*(world.data() + i)) == 1)
		{
			int x = (int) i / worldHeight;
			int y = i % worldHeight;
			drawSquare(x, y);
		}
	}

	glfwSwapBuffers(window);
	glfwPollEvents();

	return false;
}
