#include "Location.h"

int stone_colors[] = {
	0xFF'DD'DD'DD,
	0xFF'CC'CC'CC,
	0xFF'AA'AA'AA,
};

Stone::Stone() { index = 2; colors = stone_colors; x = 12; }

Stone::~Stone() {}

void Stone::show()
{
	visible = true;
	drawMesh(index, 0, x, y, colors);
}

void Stone::hide()
{
	visible = false;
	drawMesh(index, 0, x, y, ConsoleColor);
}

void Stone::doSomething(int action, Object& obj)
{
	if (action == do_repair)
	{
		index = 2;
	}
	else if (action == do_break)
	{
		index = 6;
	}
}
