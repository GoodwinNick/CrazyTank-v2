
#include "Tank.h"
#include "GlobVar.h"


void Tank::turnTo(const Direction &dirTank)
{
	if (HP > 0) 
	{

		switch (dirTank)
		{

		case LEFT:
			if (friendTank)
			{

				map[tX    ][tY    ] = '#';
				map[tX    ][tY - 1] = '#';
				map[tX    ][tY + 1] = '#';
				map[tX + 1][tY    ] = '#';
				map[tX + 1][tY - 1] = '#';
				map[tX + 1][tY + 1] = '#';
				map[tX - 1][tY - 1] = '#';
				map[tX - 1][tY + 1] = '#';
				map[tX - 1][tY    ] = '-';

			}
			else
			{

				map[tX    ][tY    ] = '&';
				map[tX    ][tY - 1] = '&';
				map[tX    ][tY + 1] = '&';
				map[tX + 1][tY    ] = '&';
				map[tX + 1][tY - 1] = '&';
				map[tX + 1][tY + 1] = '&';
				map[tX - 1][tY - 1] = '&';
				map[tX - 1][tY + 1] = '&';
				map[tX - 1][tY    ] = '-';

			}
			break;
		
		case RIGHT:
			if (friendTank)
			{

				map[tX    ][tY    ] = '#';
				map[tX    ][tY - 1] = '#';
				map[tX    ][tY + 1] = '#';
				map[tX + 1][tY    ] = '-';
				map[tX + 1][tY - 1] = '#';
				map[tX + 1][tY + 1] = '#';
				map[tX - 1][tY - 1] = '#';
				map[tX - 1][tY + 1] = '#';
				map[tX - 1][tY    ] = '#';

			}
			else
			{

				map[tX    ][tY    ] = '&';
				map[tX    ][tY - 1] = '&';
				map[tX    ][tY + 1] = '&';
				map[tX + 1][tY    ] = '-';
				map[tX + 1][tY - 1] = '&';
				map[tX + 1][tY + 1] = '&';
				map[tX - 1][tY - 1] = '&';
				map[tX - 1][tY + 1] = '&';
				map[tX - 1][tY    ] = '&';

			}
			break;
		
		case UP:
			if (friendTank)
			{

				map[tX    ][tY    ] = '#';
				map[tX    ][tY - 1] = '|';
				map[tX    ][tY + 1] = '#';
				map[tX + 1][tY    ] = '#';
				map[tX + 1][tY - 1] = '#';
				map[tX + 1][tY + 1] = '#';
				map[tX - 1][tY - 1] = '#';
				map[tX - 1][tY + 1] = '#';
				map[tX - 1][tY    ] = '#';

			}
			else
			{

				map[tX    ][tY    ] = '&';
				map[tX    ][tY - 1] = '|';
				map[tX    ][tY + 1] = '&';
				map[tX + 1][tY    ] = '&';
				map[tX + 1][tY - 1] = '&';
				map[tX + 1][tY + 1] = '&';
				map[tX - 1][tY - 1] = '&';
				map[tX - 1][tY + 1] = '&';
				map[tX - 1][tY    ] = '&';

			}
			break;
		
		case DOWN:
			if (friendTank)
			{

				map[tX    ][tY    ] = '#';
				map[tX    ][tY - 1] = '#';
				map[tX    ][tY + 1] = '|';
				map[tX + 1][tY    ] = '#';
				map[tX + 1][tY - 1] = '#';
				map[tX + 1][tY + 1] = '#';
				map[tX - 1][tY - 1] = '#';
				map[tX - 1][tY + 1] = '#';
				map[tX - 1][tY    ] = '#';
			
			}
			else
			{

				map[tX    ][tY    ] = '&';
				map[tX    ][tY - 1] = '&';
				map[tX    ][tY + 1] = '|';
				map[tX + 1][tY    ] = '&';
				map[tX + 1][tY - 1] = '&';
				map[tX + 1][tY + 1] = '&';
				map[tX - 1][tY - 1] = '&';
				map[tX - 1][tY + 1] = '&';
				map[tX - 1][tY    ] = '&';
			
			}
			break;

		default:
			break;
		}
	}
}
void Tank::moveTo(const Direction &dirTank )
{
	if (HP > 0) 
	{
	
		switch (dirTank)
		{
		
		case UP:
			if (map[tX - 1][tY - 2] != ' ' || map[tX + 1][tY - 2] != ' ')
			{
				this->dirTank = UP;
				return;
			}
			this->dirTank = UP;
			tY--;
			map[tX - 1][tY + 2] = ' ';
			map[tX    ][tY + 2] = ' ';
			map[tX + 1][tY + 2] = ' ';
			break;
		
		
		case DOWN:
			if (map[tX - 1][tY + 2] != ' ' || map[tX + 1][tY + 2] != ' ')
			{
				this->dirTank = DOWN;
				return;
			}
			this->dirTank = DOWN;
			tY++;
			map[tX    ][tY - 2] = ' ';
			map[tX + 1][tY - 2] = ' ';
			map[tX - 1][tY - 2] = ' ';
			break;

		
		case LEFT:
			if (map[tX - 2][tY + 1] != ' ' || map[tX - 2][tY - 1] != ' ')
			{
				this->dirTank = LEFT;
				return;
			}
			this->dirTank = LEFT;
			tX--;
			map[tX + 2][tY    ] = ' ';
			map[tX + 2][tY - 1] = ' ';
			map[tX + 2][tY + 1] = ' ';
			break;

		
		case RIGHT:
			if (map[tX + 2][tY + 1] != ' ' || map[tX + 2][tY - 1] != ' ')
			{
				this->dirTank = RIGHT;
				return;
			}
			this->dirTank = RIGHT;
			tX++;
			map[tX - 2][tY    ] = ' ';
			map[tX - 2][tY - 1] = ' ';
			map[tX - 2][tY + 1] = ' ';
			break;

		
		default:
			break;
		
		}
	
	}

}

void Tank::setX(const int &tX)
{
	this->tX = tX;
}
int Tank::getX()
{
	return this->tX;
}


void Tank::setY(const int &tY)
{
	this->tY = tY;
}
int Tank::getY()
{
	return this->tY;
}


void Tank::setHP(const int &HP)
{
	this->HP = HP;
}
int Tank::getHP()
{
	return this->HP;
}

void Tank::setShot(const bool &shot)
{
	this->shot = shot;
}
bool Tank::getShot()
{
	return this->shot;
}


void Tank::setFriendTank(const bool &friendTank)
{
	this->friendTank = friendTank;
}
bool Tank::getFriendTank()
{
	return this->friendTank;
}


void Tank::setDirTank(const Direction &dirTank)
{
	this->dirTank = dirTank;
}
Direction Tank::getDirTank()
{
	return this->dirTank;
}