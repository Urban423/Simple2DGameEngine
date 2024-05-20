#pragma once

class Rect
{
public:
	Rect();
	Rect(int width, int height);
	Rect(unsigned int left, unsigned int top, unsigned int width, unsigned int height);
	Rect(const Rect& rect);
	//~Rect();
public:
	int width  = 0;
	int height = 0;
	int left  = 0;
	int top = 0;
};