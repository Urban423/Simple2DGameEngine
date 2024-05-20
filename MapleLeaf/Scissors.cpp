#include "Location.h"

int scissors_colors[] = {
	0xFF'FF'FF'FF,
	0xFF'32'32'32
};

Scissors::Scissors() { index = 3; colors = scissors_colors; skip = 1; x = -12; }

Scissors::~Scissors(){}

void Scissors::show()
{
	visible = true;
	drawMesh(index, 0, x, y, colors);
} 

void Scissors::hide()
{
	visible = false;
	drawMesh(index, 0, x, y, ConsoleColor);
}
