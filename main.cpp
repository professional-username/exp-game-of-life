#include <GLFW/glfw3.h>
#include <iostream>
#include <Eigen/Dense>
#include <chrono>
#include <thread>

using namespace std;
using Eigen::MatrixXd;
using namespace std::chrono;

int gWait = 10;

extern GLFWwindow* initGraphics(int *worldWidth, int *worldHeight);
extern bool render(MatrixXd world, GLFWwindow* window);
extern MatrixXd initWorld(int worldWidth, int worldHeight);
extern MatrixXd step(MatrixXd world);

int main()
{
	// Initialisation
	int worldWidth;
	int worldHeight;
	GLFWwindow* window = initGraphics(&worldWidth, &worldHeight);
	MatrixXd world = initWorld(worldWidth, worldHeight);

	// Main loop
	bool done = false;
	while (!done)
	{
		world = step(world);
		done = render(world, window);
		//this_thread::sleep_for(chrono::milliseconds(gWait));
	}

	glfwTerminate();
	return 0;
}
