#include <Eigen/Dense>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;

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
			sum += world(j - 1, i - 1);
			sum += world(j - 1, i);
			sum += world(j - 1, i + 1);
			sum += world(j, i - 1);
			sum += world(j, i + 1);
			sum += world(j + 1, i - 1);
			sum += world(j + 1, i);
			sum += world(j + 1, i + 1);

			// Standard Conway's GOL rules
			if (sum < 2 || sum > 3)
				new_world(j, i) = 0;
			else if (sum == 3)
				new_world(j, i) = 1;
			else if (sum == 2)
				new_world(j, i) = world(j, i);
		}
	}

	return new_world;
}
