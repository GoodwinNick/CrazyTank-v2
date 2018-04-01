

#include "Controller.h"


Controller::Controller(Model* model)
{
	_model = model;
}

int Controller::getKeyState()
{	
	
	if (_kbhit())
	{
		int KeyState = (unsigned int) _getch();

		switch (KeyState)
		{

		case 72:
			return 1;

		case'w':
			return 1;

		case 80:
			return 2;

		case's':
			return 2;

		case 75:
			return 3;

		case 'a':
			return 3;

		case 77:
			return 4;

		case 'd':
			return 4;

		case 32:
			return 5;

		case 'z':
			return 5;

		case 27:
			return 6;

		default:
			return 7;
		
		}
	
	}
	else
	{
		return 7;
	}
}


void Controller::start()
{

	std::cout << "  W, A, S, D + SPACE\n   OR \n  UP, LEFT, RIGHT, DOWN + SPACE\n";
	system("pause");

	_model->firstCreateTanks();
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	int t = 0;
	while (t != 6)
	{
		t = getKeyState();
		_model->playerMovement(t);
		_model->aiMovement();
		_model->bulletMovement();

		if (_model->gameOver() == 6)
		{

			t = 6;

		}

		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		totalTime = (unsigned int) std::chrono::duration_cast<std::chrono::seconds> (end - start).count();

	}
	
}