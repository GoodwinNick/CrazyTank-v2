
#include "Observable.h"

void Observable::addObservers(Observer* observer)
{

	_observers.push_back(observer);

}

void Observable::notifyUpdate()
{

	int size = _observers.size();

	for (int i = 0; i < size; i++)
	{

		_observers[i]->update();
	
	}

}