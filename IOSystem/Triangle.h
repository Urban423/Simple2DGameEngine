#pragma once
#include "Vector.h"

typedef struct TriangleInput
{
	int* buffer;
	int height;
	int width;
	int x1; int y1;
	int x2; int y2;
	int x3; int y3;
	int color;
}TriangleInput;


void DrawTriangle(TriangleInput* in);