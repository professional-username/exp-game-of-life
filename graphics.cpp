#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Dense>

using namespace std;

float gScreenWidth = 1920 ;
float gScreenHeight = 1080;
float gSquareSize = 9e-6;
float hSize = gSquareSize * gScreenHeight;
float vSize = gSquareSize * gScreenWidth;
vector<float> gColors(6, 1);

extern bool reset_flag;

// Pressing space tells the main game loop to reset the world
void space_to_reset(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		reset_flag = true;
}

void generateColors()
{
	// Colors fade towards black over time, but in funky ways
	srand (time(NULL));
	for (int i = 0; i < 6; i += 2)
		gColors[i] = rand() / float(RAND_MAX);
	for (int i = 1; i < 6; i += 2)
		gColors[i] = 3 * (rand() / float(RAND_MAX));
}

GLFWwindow* initGraphics(int *worldWidth, int *worldHeight)
{
	// Create the window
	glfwTerminate();
	if (!glfwInit())
		std::cout << "Placeholder" << std::endl;
	GLFWwindow* window = glfwCreateWindow(
	                         gScreenWidth,
	                         gScreenHeight,
	                         "Game of Life",
	                         NULL, NULL
	                     );
	glfwMakeContextCurrent(window);
	glTranslatef(-1, -1, 0);

	// Reset when space is pressed
	glfwSetKeyCallback(window, space_to_reset);

	// Define the size of the world based on the screen width / height
	*worldHeight = 2 / vSize;
	*worldWidth = 2 / hSize;

	return window;
}

void drawSquare(int x, int y, float intensity)
{
	// Set the color of the square
	glColor4f(
	    pow((intensity * gColors[0]), gColors[1]),
	    pow((intensity * gColors[2]), gColors[3]),
	    pow((intensity * gColors[4]), gColors[5]),
	    0.0f
	);
	// Draw the square in the place
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
		float v = (*(world.data() + i));
		if (v != 0)
		{
			int x = (int) i / worldHeight;
			int y = i % worldHeight;
			drawSquare(x, y, v);
		}
	}

	glfwSwapBuffers(window);
	glfwPollEvents();

	return false;
}
