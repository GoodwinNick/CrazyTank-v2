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
	void drawBullet(std::array<Tank, 5> &t, int i);
	void bulletFlight();

	void setXYDir(int x,int y,Direction dirBullet);
	

	int getX();
	int getY();
	Direction getDirBullet();


	void setFriendBullet(bool friendBullet);
	bool getFriendBullet();
    
	
	void setShotEnab(bool shotEnab);
	bool getShotEnab();
};

#endif // !BULLET_H
