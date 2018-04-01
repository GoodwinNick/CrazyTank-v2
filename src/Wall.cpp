#include "Wall.h"


void Wall::createWall(int wX, int wY, int wHeight, int wWidth)
{

	for (int i = wX; i < wHeight + wX; i++)
	{

		for (int j = wY; j < wWidth + wY; j++)
		{

			map[i][j] = (char)219;

		}

	}
}