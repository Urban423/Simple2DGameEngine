#pragma once
#include "Vector.h"
#include <utilities.h>
#include <Matrix4x4.h>


class GraphicEngine
{
public:
	static void drawMesh(mesh Mesh, int* Image, int _width, int _height, Matrix4x4 camView, Matrix4x4 proj, float rot, float x, float y);
};

