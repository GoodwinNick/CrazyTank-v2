#include "View.h"


#include "GlobVar.h"

View::View(Model* model)
{

	_model = model;
	_model->addObservers(this);

}
void View::clearScreen()
{

	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);

}
void View::update()
{

	clearScreen();

	for (int i = 0; i <mapHeight; i++)
	{

		for (int j = 0; j < mapWidth; j++)
		{

			std::cout << map[j][i];

		}

		std::cout << std::endl;

	}

	std::cout << "Score: " << score << "  Time: " << totalTime << "  ";

}
