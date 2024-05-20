#include "GraphicEngine.h"
#include "Triangle.h"

int* Image = nullptr;
int  _width = 0;
int  _height = 0;
Matrix4x4 proj;
Mesh meshes[20];

void initGraphic(int* image, int width, int height, Matrix4x4 proje)
{
	Image = image;
	_width = width;
	_height = height;
	proj = proje;
}

void drawPixel(int x, int y, int color)
{
	if (x < 0 || y < 0) { return; }
	if (x >= _width || y >= _height) { return; }
	Image[y * _width + x] = color;
}

void drawMesh(int mesh_index, float rot, float x, float y, int* colors)
{
	if (colors == ConsoleColor) { return; }
	Matrix4x4 pos, temp;
	pos.setIdentity();
	pos.setScale(0.2f, 0.2f, 0.2f);

	temp.setIdentity();
	temp.setTranslation(x, 0, y);
	pos *= temp;

	temp.setIdentity();
	temp.setRotation(rot);
	pos *= temp;

	Matrix4x4 temp2 = proj;
	temp2 *= pos;

	Mesh mesh = meshes[mesh_index];
	Vector* ptr = mesh.vertexs;
	Vector* ptr_copy = mesh.vertexs_copy;
	for (int i = 0; i < mesh.vertexs_size; i++)
	{
		*(ptr_copy++) = temp2 * *(ptr++);
	}

	int color = 0x00'FF'00'00;

	TriangleInput input;
	input.buffer = Image;
	input.height = _height;
	input.width = _width;
	input.color = 0x00'FF'5F'03;

	for (int i = 0; i < mesh.indicies_size; i += 3)
	{
		input.color = colors[mesh.materials[i]];

		input.x1 = mesh.vertexs_copy[mesh.indicies[i]].x;
		input.y1 = -mesh.vertexs_copy[mesh.indicies[i]].z;

		input.x2 = mesh.vertexs_copy[mesh.indicies[i + 1]].x;
		input.y2 = -mesh.vertexs_copy[mesh.indicies[i + 1]].z;

		input.x3 = mesh.vertexs_copy[mesh.indicies[i + 2]].x;
		input.y3 = -mesh.vertexs_copy[mesh.indicies[i + 2]].z;

		DrawTriangle(&input);
	}
}

void registerMesh(int index, Mesh mesh)
{
	meshes[index] = mesh;
}