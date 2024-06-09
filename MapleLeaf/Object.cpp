#include "Location.h"

Object::Object(){}

Object::~Object(){}

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
