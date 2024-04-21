#include "GraphicEngine.h"
#include "Triangle.h"
#include "Cube.h"


void GraphicEngine::drawMesh(mesh Mesh, int* Image, int _width, int _height, Matrix4x4 camView, Matrix4x4 proj, float rot, float x, float y)
{
	Matrix4x4 pos, temp;
	pos.setIdentity();
	pos.setScale(0.2f, 0.2f, 0.2f);

	temp.setIdentity();
	temp.setTranslation(x, 0, y);
	pos *= temp;

	temp.setIdentity();
	temp.setRotation(rot);
	pos *= temp;


	camView *= pos;
	proj *= camView;


	Vector* ptr = Mesh.vertexs;
	Vector* ptr_copy = Mesh.vertexs_copy;
	for (int i = 0; i < Mesh.vertexs_size; i++)
	{
		*(ptr_copy++) = proj * *(ptr++);
	}

	int color = 0x00'FF'00'00;

	TriangleInput input;
	input.buffer = Image;
	input.height = _height;
	input.width = _width;
	input.counter = 0;
	input.texture = {&color, 1, 1};


	int k = 0;
	for (int i = 0; i < Mesh.indicies_size; i += 3)
	{
		//input.color = colors[k++ %  12];

		input.x1 = Mesh.vertexs_copy[Mesh.indicies[i]].x;
		input.y1 = -Mesh.vertexs_copy[Mesh.indicies[i]].z;
		input.uv1 = Vector2(0, 0);

		input.x2 = Mesh.vertexs_copy[Mesh.indicies[i + 1]].x;
		input.y2 = -Mesh.vertexs_copy[Mesh.indicies[i + 1]].z;
		input.uv2 = Vector2(0.5f, 0);

		input.x3 = Mesh.vertexs_copy[Mesh.indicies[i + 2]].x;
		input.y3 = -Mesh.vertexs_copy[Mesh.indicies[i + 2]].z;
		input.uv3 = Vector2(0, 0.5f);

		DrawTriangleByTexture(static_cast<void*>(&input));
	}
	//printf("here");
}
