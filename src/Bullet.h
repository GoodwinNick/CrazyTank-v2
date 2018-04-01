#ifndef BULLET_H
#define BULLET_H

#include "GlobVar.h"
#include "Tank.h"

class Bullet
{
	int bX;
	int bY;
	Direction dirBullet;
	bool shotEnab;
	bool friendBullet;

public:
	void drawBullet(std::array<Tank, 5> &t, const int &i);
	void bulletFlight();

	void setXYDir(const int &x, const int &y,const Direction &dirBullet);
	

	int getX();
	int getY();
	Direction getDirBullet();


	void setFriendBullet(const bool &friendBullet);
	bool getFriendBullet();
    
	
	void setShotEnab(const bool &shotEnab);
	bool getShotEnab();
};

#endif // !BULLET_H
