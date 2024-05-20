#include "Location.h"

Point::Point(){}

Point::~Point(){}

void Point::hide()
{ 
	visible = false;
	drawPixel(x, y, 0);
}

void Point::show()
{
	visible = true;
	drawPixel(x, y, color);
}

void Point::moveTo(float x, float y)
{
	hide();
	this->x = x;
	this->y = y;
	show();
}
