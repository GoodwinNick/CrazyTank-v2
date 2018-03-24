#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "GlobVar.h"
#include "Model.h"

class Controller
{
private:
	Model * _model;
public:
	Controller(Model* model);
	int getKeyState();
	void start();
};

#endif // !CONTROLLER_H
