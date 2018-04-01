#ifndef MODEL_H
#define MODEL_H

#include "GlobVar.h"
#include "Map.h"
#include "Tank.h"
#include "Bullet.h"
#include "Observable.h"


class Model : public Observable
{

private:
	Map* m;
	std::array<Tank  , 5> t;
	std::array<Bullet, 5> b;

public:
	void bulletMovement();
	void firstCreateTanks();
	void playerMovement(const int &direct);
	void aiMovement();
	int  gameOver();

};

#endif // !MODEL_H
