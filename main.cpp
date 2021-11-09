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

extern GLFWwindow* initGraphics(int *worldWidth, int *worldHeight);
extern bool render(MatrixXd world, GLFWwindow* window);
extern MatrixXd initWorld(int worldWidth, int worldHeight);
extern MatrixXd step(MatrixXd world);

void reset()
{
	// Set the world and window
	int worldWidth;
	int worldHeight;
	window = initGraphics(&worldWidth, &worldHeight);
	world = initWorld(worldWidth, worldHeight);
	reset_flag = false;
}

int main()
{
	// Initialisation
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
