#ifndef VIEW_H
#define VIEW_H

#include "Observer.h"
#include "Model.h"
#include "Controller.h"


class View : public Observer
{

private:
	Model* _model;

public:
	View(Model* model);
	virtual void update();
	void clearScreen();

};
#endif // !VIEW_H
