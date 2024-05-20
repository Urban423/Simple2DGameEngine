#pragma once
#include "Vector.h"
#include "utilities.h"
#include "Matrix4x4.h"
#define ConsoleColor nullptr

void initGraphic(int* image, int width, int height, Matrix4x4 proje);
void drawPixel(int  x, int y, int color);
void drawMesh(int mesh_index, float rot, float x, float y, int* colors);
void initMesh(int index, Mesh mesh);
