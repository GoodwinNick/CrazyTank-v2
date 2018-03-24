
#include "Map.h"
#include "GlobVar.h"

void Map::createMap()
{

	for (int i = 0; i < mapHeight; i++)
	{

		for (int j = 0; j < mapWidth; j++)
		{

			if (i == 0 || i == mapHeight-1)
			{

				map[i][j] = (char)219;

			}

			else if (j == 0 || j == mapWidth-1)
			{

				map[i][j] = (char)219;

			}

			else map[i][j] = ' ';

		}

	}

	for (int i = 0; i < wallCount; i++)
	{

		x = rand() % mapWidth  ;
		y = rand() % (mapHeight - 9)  ;
		w.createWall(x, y, 3, 3);
	
	}

}

void Map::createBase()
{

	for (int i = 22; i <= 22+6; i++)
	{
		
		for (int j = 45; j <= 49; j++)
		{
		
			if (i >= 24 && i < 27 && j >= 46 && j < 49)
			{
			
				map[i][j] = 'G';
			
			}
			
			else
			{
			
				map[i][j] = (char)219;
	
			}
		
		}
	
	}

}

void Map::drawMap()
{

	for (int i = 0; i < 50; i++)
	{
	
		for (int j = 0; j < 50; j++)
		{
		
			std::cout << map[j][i];
		
		}
		
		std::cout << std::endl;
	
	}

}