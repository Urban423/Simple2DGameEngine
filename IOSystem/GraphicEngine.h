#pragma once
#include "Vector.h"
#include "utilities.h"
#include "Matrix4x4.h"
#define ConsoleColor nullptr

void initGraphic(int* image, int width, int height, Matrix4x4 proje);
void drawPixel(int  x, int y, int color);
void DrawPolygons(int mesh_index, float rot, float x, float y, int* colors);
void registerMesh(int index, Mesh mesh);
