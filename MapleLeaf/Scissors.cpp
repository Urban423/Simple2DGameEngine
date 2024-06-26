#include "Location.h"

int scissors_colors[] = {
	0xFF'DD'DD'DD,
	0xFF'32'32'32
};

Scissors::Scissors() { index = 3; colors = scissors_colors; x = -12; }

Scissors::~Scissors(){}

void Scissors::show()
{
	visible = true;
	DrawPolygons(index, 0, x, y, colors);
} 

void Scissors::hide()
{
	visible = false;
	DrawPolygons(index, 0, x, y, ConsoleColor);
}
void Scissors::doSomething(int action, Object& obj)
{
	if (action == do_repair)
	{
		index = 3;
	}
	else if (action == do_break)
	{
		index = 7;
	}
}