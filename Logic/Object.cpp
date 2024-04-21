#include "Object.h"

Object::Object(){}
Object::~Object(){}


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
