#include "Location.h"

int knife_colors[] = {
	0xFF'FF'00'00,
	0xFF'AA'AA'AA,
	0xFF'10'10'10
};

Knife::Knife() 
{
	index = 4; x = 12; y = 12; rotation = -0.6f;
	skip = true;
	index = 1;
	this->colors = knife_colors; 
}

Knife::~Knife() {}

void Knife::show()
{
	visible = true;
	drawMesh(index, 1.1, x, y, colors);
}

void Knife::hide()
{
	visible = false;
	drawMesh(index, 1.1, x, y, ConsoleColor);
}