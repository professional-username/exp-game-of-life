#include <Eigen/Dense>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;

float gFade = 0.035f;

MatrixXd initWorld(int worldWidth, int worldHeight)
{
	// Create the world as a matrix
	MatrixXd world = MatrixXd::Zero(worldHeight, worldWidth);
	// Fill the cells randomly
	srand (time(NULL));
	for (int i = 1; i < worldWidth - 1; i++)
	{
		for (int j = 1; j < worldHeight; j++)
		{
			world(j, i) = rand() % 2;
		}

	}
	return world;
}

MatrixXd step(MatrixXd world)
{
	int worldWidth = world.cols();
	int worldHeight = world.rows();
	MatrixXd new_world = MatrixXd::Zero(worldHeight, worldWidth);
	// Update every cell
	for (int i = 1; i < worldWidth - 1; i++)
	{
		for (int j = 1; j < worldHeight - 1; j++)
		{
			// Yes it's ugly, yes I need to fix it
			int sum = 0;
			sum += floor(world(j - 1, i - 1));
			sum += floor(world(j - 1, i));
			sum += floor(world(j - 1, i + 1));
			sum += floor(world(j, i - 1));
			sum += floor(world(j, i + 1));
			sum += floor(world(j + 1, i - 1));
			sum += floor(world(j + 1, i));
			sum += floor(world(j + 1, i + 1));

			// Standard Conway's GOL rules, but with fading cells
			if (sum < 2 || sum > 3)
				new_world(j, i) = max(float (world(j, i) - gFade), 0.0f);
			else if (sum == 3)
				new_world(j, i) = 1;
			else if (sum == 2 && world(j, i) == 1)
				new_world(j, i) = 1;
			else if (sum == 2 && world(j, i) < 1)
				new_world(j, i) = max(float (world(j, i) - gFade), 0.0f);
		}
	}

	return new_world;
}
