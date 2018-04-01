#ifndef TANK_H
#define TANK_H

#include "GlobVar.h"

class Tank
{

private:
	int tX;
	int tY;
	int HP;
	bool shot;
	bool friendTank;
	Direction dirTank;

public:
	void turnTo(const Direction &dirTank);
	void moveTo(const Direction &dirTank);

	void setX(const int &tX);
	int getX();

	void setY(int const &tY);
	int getY();

	void setHP(const int &HP);
	int getHP();

	void setShot(const bool &shotEnab);
	bool getShot();

	void setFriendTank(const bool &friendTank);
	bool getFriendTank();

	void setDirTank(const Direction &dirTank);
	Direction getDirTank();

};

#endif // !TANK_H
