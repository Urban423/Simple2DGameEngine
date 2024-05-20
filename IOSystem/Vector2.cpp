#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

float Vector2::length()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::normalize()
{
	float l = this->length();
	if (l == 0) { return Vector2(); }
	return Vector2(x / l, y / l);
}
