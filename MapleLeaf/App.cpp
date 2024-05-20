#include "App.h"

App::App(){_running = true;}

App::~App(){}

bool App::isRunning() { return _running; }

void App::onCreate()
{
	initMesh(0, read2dModel("mapleLeaf.3ds"));
	initMesh(1, read2dModel("knife.3ds"));
	initMesh(2, read2dModel("ductTape.3ds"));
	initMesh(3, read2dModel("scissors.3ds"));
	initMesh(4, read2dModel("mapleLeafSeparated.3ds"));
	initMesh(5, read2dModel("ductTape.3ds"));


	objects[0] = new MapleLeaf();
	objects[1] = new Knife();
	objects[2] = new Scissors();
	objects[3] = new DuctTape();
}

void App::onUpdate()
{
	int matrix[6][6] = {
		//maple leaf	knife		ductTape	scissors	mapleLeafB		ductTape
		{do_nothing,	do_break,	do_repair,	do_break,	do_nothing,		do_nothing	},	//mapleLeaf
		{do_break,		do_nothing, do_nothing, do_nothing, do_nothing,		do_nothing	},	//knife
		{do_repair,		do_nothing, do_nothing, do_nothing, do_repair,		do_nothing	},	//ductTape
		{do_break,		do_nothing, do_nothing, do_nothing, do_nothing,		do_nothing	},	//scissors
		{do_nothing,	do_nothing, do_repair,	do_nothing, do_nothing,		do_repair	},	//mapleLeafB
		{do_repair,		do_nothing, do_nothing, do_nothing, do_repair,		do_nothing	},	//ductTape
	}; 
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (Vector::MagnitudeDistance(Vector(objects[i]->getX(), objects[i]->getY(), 0), Vector(objects[j]->getX(), objects[j]->getY(), 0)) < 15) {
				objects[i]->doSomething(matrix[objects[i]->index][objects[j]->index], *objects[i]);
				objects[j]->doSomething(matrix[objects[j]->index][objects[i]->index], *objects[j]);
			}
		}
	}

	if (GetKeyDown(KeyCode_E)) { moveable_index = (moveable_index + 1) % size; }
	objects[moveable_index]->Update();

	memset(image, 0, r.height * r.width * 4);
	for (int i = 0; i < size; i++) 	{
		if (objects[i]->getVisibility()) {
			drawMesh(objects[i]->index, objects[i]->rotation, objects[i]->getX(), objects[i]->getY(), objects[i]->getColors());
		}
	}

	setBuffer(image);
	broadcast();
}