#pragma once
#include "Vector.h"
#include "Vector2.h"

struct Texture
{
	int* pixels;
	int height;
	int width;
};

typedef struct TriangleInput
{
	int* buffer;
	int height;
	int width;

	int x1; int y1;
	int x2; int y2;
	int x3; int y3;
	Texture texture;
	Vector2 uv1;
	Vector2 uv2;
	Vector2 uv3;
	int* counter;
}TriangleInput;


void DrawTriangleByTexture(void* input);