


#include "Model.h"

void Model::firstCreateTanks()
{

	for (int i = 0; i < t.size(); i++) 
	{
		if (i == 0)
		{

			
			t[i].setX((mapWidth / 4)*3);
			t[i].setY(mapHeight-3);
			t[i].setHP(3);
			t[i].setDirTank(UP);
			t[i].setFriendTank(true);
			t[i].setShot(true);

		}

		else
		{

			t[i].setX(rand() % 40 + 3);
			t[i].setY(rand() % 44 + 3);
			t[i].setHP(1);
			t[i].setDirTank(UP);
			t[i].setFriendTank(false);
			t[i].setShot(true);

		}

	}

	notifyUpdate();

}

void Model::bulletMovement()
{

	for (int i = 0; i < t.size(); i++)
	{

		b[i].bulletFlight();
		b[i].drawBullet(t, i);

	}

}

void Model::playerMovement(const int &direct)
{	
	
	switch (direct)
	{

	case 1:
		t[0].moveTo(UP);
		t[0].turnTo(UP);
		break;

	case 2:
		t[0].moveTo(DOWN);
		t[0].turnTo(DOWN);
		break;

	case 3:
		t[0].moveTo(LEFT);
		t[0].turnTo(LEFT);
		break;

	case 4:
		t[0].moveTo(RIGHT);
		t[0].turnTo(RIGHT);
		break;

	case 5:
		if (t[0].getShot() == true)
		{

			t[0].setShot(false);
			b[0].setXYDir(t[0].getX(), t[0].getY(), t[0].getDirTank());
			b[0].setFriendBullet(t[0].getFriendTank());
			b[0].setShotEnab(true);
			
		}
		break;

	default:
		break;

	}
	std::cout << "HP:  " << t[0].getHP()<<"   ";
	notifyUpdate();
}

int Model::gameOver()
{
	
	int sum = 0;
	
	for (auto it = t.begin(); it != t.end(); ++it)
	{
	
		if (it == t.begin())
		{

			if (it->getHP() <= 0)
			{
			
				system("cls");
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
				std::cout << "YOU LOSE!\n";
				std::cout << "Your score:  " << score << "\n";
				std::cout << "Your Time:  " << totalTime << "  s\n";
				return 6;
		
			}

		}
		else 
		{
		
			sum += it->getHP();
		
		}
	
	}

	if (sum == 0)
	{
	
		system("cls");
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << "                   YOU WIN!\n";
		std::cout << "                   Your score:  " << score << "\n";
		std::cout << "                   Your Time:  " << totalTime << "  s\n";
		return 6;
	
	}
	
	else return 0;
}

void Model::aiMovement()
{
	
	for (int i = 1; i < t.size(); i++)
	{
	
		if (t[0].getX() > t[i].getX() && t[0].getY() < t[i].getY())
		{

			int r = rand() % 2;
			switch (rand() % 2)
			{
			case 0:
				if (map[t[i].getX()][t[i].getY() - 1] != ' ')
				{
					t[i].turnTo(UP);
					t[i].moveTo(UP);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(UP);
					t[i].moveTo(UP);

				}
				break;

			case 1:
				if (map[t[i].getX() + 1][t[i].getY()] != ' ')
				{
					t[i].turnTo(RIGHT);
					t[i].moveTo(RIGHT);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(RIGHT);
					t[i].moveTo(RIGHT);

				}

				break;

			default:
				break;
			}

		}
		
		else if (t[0].getX() < t[i].getX() && t[0].getY() > t[i].getY())
		{
			int r = rand() % 2;
			switch (rand() % 2)
			{
			case 0:
				if (map[t[i].getX()][t[i].getY() + 1] != ' ')
				{
					t[i].turnTo(DOWN);
					t[i].moveTo(DOWN);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(DOWN);
					t[i].moveTo(DOWN);

				}
				break;

			case 1:
				if (map[t[i].getX() - 1][t[i].getY()] != ' ')
				{
					t[i].turnTo(LEFT);
					t[i].moveTo(LEFT);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(LEFT);
					t[i].moveTo(LEFT);

				}

				break;

			default:
				break;
			}

	    }
		
		else if (t[0].getX() < t[i].getX() && t[0].getY() < t[i].getY())
		{
			int r = rand() % 2;
			switch (rand()%2)
			{
			case 0:
				if (map[t[i].getX()-1][t[i].getY()]!=' ')
				{
					t[i].turnTo(UP);
					t[i].moveTo(UP);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(UP);
					t[i].moveTo(UP);

				}
				break;

			case 1:
				if (map[t[i].getX()][t[i].getY() - 1] != ' ')
				{
					t[i].turnTo(LEFT);
					t[i].moveTo(LEFT);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(LEFT);
					t[i].moveTo(LEFT);

				}

				break;

			default:
				break;
			}

		}
	
		else if (t[0].getX() > t[i].getX() && t[0].getY() > t[i].getY())
		{
			int r = rand() % 2;
			switch (rand() % 2)
			{
			case 0:
				if (map[t[i].getX() + 1][t[i].getY()] != ' ')
				{
					t[i].turnTo(DOWN);
					t[i].moveTo(DOWN);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(DOWN);
					t[i].moveTo(DOWN);

				}
				break;

			case 1:
				if (map[t[i].getX()][t[i].getY() + 1] != ' ')
				{
					t[i].turnTo(RIGHT);
					t[i].moveTo(RIGHT);
					if (t[i].getShot() == true)
					{
						t[i].setShot(false);
						b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
						b[i].setShotEnab(true);
						b[i].setFriendBullet(t[i].getFriendTank());
					}
				}
				else
				{
					t[i].turnTo(RIGHT);
					t[i].moveTo(RIGHT);

				}

				break;

			default:
				break;
			}

		}

	
		
		if (t[0].getX() == t[i].getX() && t[0].getY() > t[i].getY())
		{
			t[i].turnTo(DOWN);
			t[i].moveTo(DOWN);
			if (t[i].getShot() == true)
			{
				t[i].setShot(false);
				b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
				b[i].setShotEnab(true);
				b[i].setFriendBullet(t[i].getFriendTank());
			}

		}

		else if (t[0].getX() == t[i].getX() && t[0].getY() < t[i].getY())
		{
			t[i].turnTo(UP);
			t[i].moveTo(UP);
			if (t[i].getShot() == true)
			{
				t[i].setShot(false);
				b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
				b[i].setShotEnab(true);
				b[i].setFriendBullet(t[i].getFriendTank());
			}
		}

		else if (t[0].getX() > t[i].getX() && t[0].getY() == t[i].getY())
		{

			t[i].turnTo(RIGHT);
			t[i].moveTo(RIGHT);
			if (t[i].getShot() == true)
			{
				t[i].setShot(false);
				b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
				b[i].setShotEnab(true);
				b[i].setFriendBullet(t[i].getFriendTank());
			}

		}

		else if (t[0].getX() < t[i].getX() && t[0].getY() == t[i].getY())
		{
			
			t[i].turnTo(LEFT);
			t[i].moveTo(LEFT);
			if (t[i].getShot() == true)
			{
				t[i].setShot(false);
				b[i].setXYDir(t[i].getX(), t[i].getY(), t[i].getDirTank());
				b[i].setShotEnab(true);
				b[i].setFriendBullet(t[i].getFriendTank());
			}

		}


		if (t[i].getShot() == true)
		{
			b[i].drawBullet(t, i);
			b[i].bulletFlight();
		}


	}

	notifyUpdate();

}