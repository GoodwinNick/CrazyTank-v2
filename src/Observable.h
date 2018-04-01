#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "GlobVar.h"
#include "Observer.h"

class Observable 
{

private:
	std::vector<Observer*> _observers;

public:
	void addObservers(Observer* observer);
	void notifyUpdate();

};

#endif // !OBSERVABLE_H
