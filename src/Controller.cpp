

#include "Controller.h"


Controller::Controller(Model* model)
{
	_model = model;
}

int Controller::getKeyState()
{	
	
	if (_kbhit())
	{
		    
		switch (_getch())
		{

		case VK_UP:
			return 1;

		case'w':
			return 1;

		case VK_DOWN:
			return 2;

		case's':
			return 2;

		case VK_LEFT:
			return 3;

		case 'a':
			return 3;

		case VK_RIGHT:
			return 4;

		case 'd':
			return 4;

		case VK_SPACE:
			return 5;

		case 'z':
			return 5;

		case VK_ESCAPE:
			return 6;

		default:
			break;
		
		}
	
	}

}


void Controller::start()
{

	_model->firstCreateTanks();
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	int temp = 0;
	while (temp != 6)
	{

		temp = getKeyState();
		_model->playerMovement(temp);
		_model->aiMovement();
		_model->bulletMovement();

		if (_model->gameOver() == 6)
		{

			temp = 6;

		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();;
		totalTime = std::chrono::duration_cast<std::chrono::seconds> (end - start).count();

	}
	
}