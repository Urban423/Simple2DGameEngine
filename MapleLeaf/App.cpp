#include "App.h"

App::App(){_running = true;}

App::~App(){}

bool App::isRunning() { return _running; }

void App::onCreate()
{
	registerMesh(0, loadResourse("mapleLeaf.3ds"));
	registerMesh(1, loadResourse("knife.3ds"));
	registerMesh(2, loadResourse("stone.3ds"));
	registerMesh(3, loadResourse("scissors.3ds"));
	registerMesh(4, loadResourse("mapleLeafSeparated.3ds"));
	registerMesh(5, loadResourse("ductTape.3ds"));
	registerMesh(6, loadResourse("brokenStone.3ds"));
	registerMesh(7, loadResourse("brokenScissros.3ds"));
	registerMesh(8, loadResourse("brokenKnife.3ds"));


	objects[0] = new MapleLeaf();
	objects[1] = new Knife();
	objects[2] = new Scissors();
	objects[3] = new DuctTape();
	objects[4] = new Stone();
}

void App::onUpdate()
{
	int matrix[9][9] = {
		//maple leaf	knife		stone		scissors	mapleLeafB		ductTape	brokenStone	brokenKnife	brokenScissors
		{do_nothing,	do_break,	do_nothing,	do_break,	do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//mapleLeaf
		{do_nothing,	do_nothing, do_break,	do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//knife
		{do_break,		do_nothing, do_nothing,	do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//stone
		{do_nothing,	do_nothing, do_break,	do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//scissors
		{do_nothing,	do_nothing, do_nothing,	do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//mapleLeafB
		{do_nothing,	do_nothing, do_nothing, do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//ductTape
		{do_nothing,	do_nothing, do_nothing, do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//brokenStone
		{do_nothing,	do_nothing, do_nothing, do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//brokenknife
		{do_nothing,	do_nothing, do_nothing, do_nothing, do_nothing,		do_repair,	do_nothing,	do_nothing,	do_nothing	},	//brokenScissors
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