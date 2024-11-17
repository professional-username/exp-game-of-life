#include <GLFW/glfw3.h>
#include <iostream>
#include <Eigen/Dense>
#include <chrono>
#include <thread>

using namespace std;
using Eigen::MatrixXd;
using namespace std::chrono;

int gWait = 10;
GLFWwindow* window;
MatrixXd world;
bool reset_flag = false;
int worldWidth;
int worldHeight;

extern GLFWwindow* initGraphics(int *worldWidth, int *worldHeight);
extern bool render(MatrixXd world, GLFWwindow* window);
extern MatrixXd initWorld(int worldWidth, int worldHeight);
extern MatrixXd step(MatrixXd world);
extern void generateColors();

void reset()
{
	// Set the world and window
	generateColors();
	world = initWorld(worldWidth, worldHeight);
	reset_flag = false;
}

int main()
{
	// Initialisation
	window = initGraphics(&worldWidth, &worldHeight);
	reset();

	// Main loop
	bool done = false;
	while (!done)
	{
		world = step(world);
		done = render(world, window);
		//this_thread::sleep_for(chrono::milliseconds(gWait));
		if (reset_flag)
			reset();
	}

	glfwTerminate();
	return 0;
}
