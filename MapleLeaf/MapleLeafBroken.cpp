#include "Location.h"

int maple_leaf_colors[] = {
	0x00'7A'34'01,
	0x00'FF'5F'03,
};

int maple2_leaf_colors[] = {
	maple_leaf_colors[1],
	maple_leaf_colors[0],
};

MapleLeafBroken::MapleLeafBroken() { index = 4; this->colors = maple2_leaf_colors; }

MapleLeafBroken::~MapleLeafBroken() {}

void MapleLeafBroken::doSomething(int action, Object& obj){}

void MapleLeafBroken::show()
{
	visible = true;
	drawMesh(index, 0, x, y, colors);
}

void MapleLeafBroken::hide()
{
	visible = false;
	drawMesh(index, 0, x, y, ConsoleColor);
}



MapleLeaf::MapleLeaf() { index = 0; this->colors = maple_leaf_colors;}

MapleLeaf::~MapleLeaf() {}

void MapleLeaf::show()
{
	visible = true;
	drawMesh(index, 0, x, y, colors);
}

void MapleLeaf::hide()
{
	visible = false;
	drawMesh(index, 0, x, y, ConsoleColor);
}

void MapleLeaf::doSomething(int action, Object& obj)
{
	if (action == do_break) {
		obj = MapleLeafBroken();
	}
	else if (action == do_repair) {
		obj = MapleLeaf();
	}
}