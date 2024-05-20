#include "Location.h"

Object::Object(){}

Object::~Object(){}

void Object::show()
{
	drawMesh(index, 1.1, x, y, colors); 
	visible = true;
}

void Object::hide()
{
	drawMesh(index, 1.1, x, y, ConsoleColor);
	visible = false;
}

int* Object::getColors() { return colors; }

bool Object::getVisibility(){return visible;}

void Object::doSomething(int action, Object& obj){}

void Object::Update()
{
	if (GetKey(up))
	{
		y += speed;
	}
	else if (GetKey(down))
	{
		y -= speed;
	}


	if (GetKey(right))
	{
		x += speed;
	}
	else if (GetKey(left))
	{
		x -= speed;
	}
}
