#include "Location.h"

int ductTape_colors[] = {
	0xFF'CC'CC'CC,
	0xFF'AA'AA'AA,
	0xFF'00'00'FF,
	0xFF'FF'FF'FF,
};

DuctTape::DuctTape() { index = 5; colors = ductTape_colors; skip = 1; x = -12; }

DuctTape::~DuctTape() {}

void DuctTape::show()
{
	visible = true;
	drawMesh(index, 0, x, y, colors);
}

void DuctTape::hide()
{
	visible = false;
	drawMesh(index, 0, x, y, ConsoleColor);
}
