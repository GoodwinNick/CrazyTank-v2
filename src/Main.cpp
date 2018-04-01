#include "GlobVar.h"
#include "Controller.h"
#include "Map.h"
#include "Model.h"
#include "View.h"

int main()
{

	srand((unsigned int)time(NULL));

	Map m;

	Model model;
	View view(&model);
	Controller controller(&model);

	m.createMap();
	m.createBase();
	
	controller.start();

	system("pause");
	return 0;
}
