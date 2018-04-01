

#include "Bullet.h"




void Bullet::bulletFlight()
{
	if (shotEnab)
	{

		switch (dirBullet)
		{
		case UP:
			bY --;
			break;

		case DOWN:
			bY ++;	
			break;

		case LEFT:
			bX --;
			break;

		case RIGHT:
			bX ++;
			break;
		}
	}


}

void Bullet::drawBullet(std::array<Tank, 5> &t,const int &i)
{
	if ( shotEnab )
	{
		if (t[i].getFriendTank() == false)
		{

			if (map[bX][bY] == ' ')
			{
			
				switch (dirBullet)
				{
				
				case UP:
					map[bX][bY] = 'o';
					map[bX][bY + 1] = ' ';
					break;
				
				case DOWN:
					map[bX][bY] = 'o';
					map[bX][bY - 1] = ' ';
					break;
				
				case LEFT:
					map[bX][bY] = 'o';
					map[bX + 1][bY] = ' ';
					break;
				
				case RIGHT:
					map[bX][bY] = 'o';
					map[bX - 1][bY] = ' ';
					break;
				}

			}
			
			else if (map[bX][bY] == '#' || map[bX][bY] == '|' || map[bX][bY] == '-')
			{
				switch (dirBullet)
				{

				case UP:
					map[bX][bY + 1] = ' ';
					shotEnab = false;
					break;

				case DOWN:
					map[bX][bY - 1] = ' ';
					shotEnab = false;
					break;

				case LEFT:
					map[bX + 1][bY] = ' ';
					shotEnab = false;
					break;

				case RIGHT:
					map[bX - 1][bY] = ' ';
					shotEnab = false;
					break;

				}
				
				t[0].setHP(t[0].getHP() - 1);

			}

			else if (map[bX][bY] != ' ')
			{
				switch (dirBullet)
				{

				case UP:
					map[bX    ][bY    ] = ' ';
					map[bX + 1][bY    ] = ' ';
					map[bX - 1][bY    ] = ' ';
					map[bX    ][bY + 1] = ' ';
					shotEnab = false;
					break;

				case DOWN:
					map[bX    ][bY    ] = ' ';
					map[bX + 1][bY    ] = ' ';
					map[bX - 1][bY    ] = ' ';
                    map[bX    ][bY - 1] = ' ';
					shotEnab = false;
					break;

				case LEFT:
					map[bX    ][bY    ] = ' ';
					map[bX    ][bY - 1] = ' ';
					map[bX    ][bY + 1] = ' ';
					map[bX + 1][bY    ] = ' ';
					shotEnab = false;
					break;

				case RIGHT:
					map[bX    ][bY    ] = ' ';
					map[bX    ][bY + 1] = ' ';
					map[bX    ][bY - 1] = ' ';
					map[bX - 1][bY    ] = ' ';
					shotEnab = false;
					break;

				}

				t[i].setShot(true);
			
			}
		
        }
		
		else
		{
			if (map[bX][bY] == ' ')
			{
				switch (dirBullet)
				{
				case UP:
					map[bX][bY] = 'o';
					map[bX][bY + 1] = ' ';
					break;

				case DOWN:
					map[bX][bY] = 'o';
					map[bX][bY - 1] = ' ';
					break;

				case LEFT:
					map[bX][bY] = 'o';
					map[bX + 1][bY] = ' ';
					break;

				case RIGHT:
					map[bX][bY] = 'o';
					map[bX - 1][bY] = ' ';
					break;
				}
			}
			
			else if (map[bX][bY] == '&'|| map[bX][bY] == '|' || map[bX][bY] == '-')
			{
		
				switch (dirBullet)
				{

				case UP:
					map[bX][bY + 1] = ' ';
					shotEnab = false;
					break;
				
				case DOWN:
					map[bX][bY - 1] = ' ';
					shotEnab = false;
					break;
				
				case LEFT:
					map[bX + 1][bY] = ' ';
					shotEnab = false;
					break;
				
				case RIGHT:
					map[bX - 1][bY] = ' ';
					shotEnab = false;
					break;
				
				}

				score++;
				t[i].setShot(true);

				for (int j = 1; j < tanksCount; j++)
				{


					if (
						(bX == t[j].getX()     && bY == t[j].getY())     ||
						(bX == t[j].getX() - 1 && bY == t[j].getY() - 1) ||
						(bX == t[j].getX() - 1 && bY == t[j].getY())     ||
						(bX == t[j].getX() - 1 && bY == t[j].getY() + 1) ||
						(bX == t[j].getX() + 1 && bY == t[j].getY() - 1) ||
						(bX == t[j].getX() + 1 && bY == t[j].getY())     ||
						(bX == t[j].getX() + 1 && bY == t[j].getY() + 1) ||
						(bX == t[j].getX()     && bY == t[j].getY() - 1) ||
						(bX == t[j].getX()     && bY == t[j].getY() + 1)
						)
					{

						t[j].setHP(t[j].getHP() - 1);

					}


					if (t[j].getHP() <= 0)
					{

						map[t[j].getX()    ][t[j].getY()    ] = ' ';
						map[t[j].getX()    ][t[j].getY() + 1] = ' ';
						map[t[j].getX() - 1][t[j].getY()    ] = ' ';
						map[t[j].getX() + 1][t[j].getY()    ] = ' ';
						map[t[j].getX() - 1][t[j].getY() - 1] = ' ';
						map[t[j].getX() + 1][t[j].getY() - 1] = ' ';
						map[t[j].getX() - 1][t[j].getY() + 1] = ' ';
						map[t[j].getX() + 1][t[j].getY() + 1] = ' ';
						map[t[j].getX()    ][t[j].getY() - 1] = ' ';
						

					}

				}
				
			}
			
			else if (map[bX][bY] != ' ')
			{
				switch (dirBullet)
				{

				case UP:
					map[bX    ][bY    ] = ' ';
					map[bX + 1][bY    ] = ' ';
					map[bX - 1][bY    ] = ' ';
					map[bX    ][bY + 1] = ' ';
					shotEnab = false;
					break;

				case DOWN:
					map[bX    ][bY    ] = ' ';
					map[bX + 1][bY    ] = ' ';
					map[bX - 1][bY    ] = ' ';					
					map[bX    ][bY - 1] = ' ';
					shotEnab = false;
					break;

				case LEFT:
					map[bX    ][bY    ] = ' ';
					map[bX    ][bY - 1] = ' ';
					map[bX    ][bY + 1] = ' ';
					map[bX + 1][bY    ] = ' ';
					shotEnab = false;
					break;

				case RIGHT:
					map[bX    ][bY    ] = ' ';
					map[bX    ][bY + 1] = ' ';
					map[bX    ][bY - 1] = ' ';
					map[bX - 1][bY    ] = ' ';
					shotEnab = false;
					break;

				}

				t[i].setShot(true);
			
			}
		
        }
		
	}

}


void Bullet::setXYDir(const int &x,const int &y,const Direction &dirBullet)
{

	switch (dirBullet)
	{
	
	case UP:
		this->bX = x;
		this->bY = y - 2;
		break;
	
	case DOWN:
		this->bX = x;
		this->bY = y + 2;
		break;
	
	case LEFT:
		this->bX = x - 2;
		this->bY = y;
		break;

	case RIGHT:
		this->bX = x + 2;
		this->bY = y;
		break;
	
	default:
		break;
	}
	
	this->dirBullet = dirBullet;

}

int Bullet::getX()
{
	return this->bX;
}

int Bullet::getY()
{
	return this->bY;
}

Direction Bullet::getDirBullet()
{
	return this->dirBullet;
}


void Bullet::setFriendBullet(const bool &friendBullet)
{
	this->friendBullet = friendBullet;
}

bool Bullet::getFriendBullet()
{
	return this->friendBullet;
}

void Bullet::setShotEnab(const bool &shotEnab)
{
	this->shotEnab = shotEnab;
}

bool Bullet::getShotEnab()
{
	return this->shotEnab;
}
