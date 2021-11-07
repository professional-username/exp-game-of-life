#include <Eigen/Dense>
#include <iostream>

using namespace std;
using Eigen::MatrixXd;

MatrixXd initWorld(int worldWidth, int worldHeight)
{
	// Create the world as a matrix
	MatrixXd world = MatrixXd::Zero(worldHeight, worldWidth);
	return world;
}

MatrixXd step(MatrixXd world)
{
	int worldWidth = world.cols();
	int worldHeight = world.rows();
	MatrixXd new_world = MatrixXd::Zero(worldHeight, worldWidth);

	return new_world;
}
