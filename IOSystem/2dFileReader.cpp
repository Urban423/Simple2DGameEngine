#include "2dFileReader.h"
#include <stdio.h>

Mesh read2dModel(const char* filename)
{
	float x, y, z;
	Mesh result;
	FILE* file;
	fopen_s(&file, filename, "rb");
	fread(&result.vertexs_size, 4, 1, file);
	fread(&result.indicies_size, 4, 1, file);
	fread(&result.uv_size, 4, 1, file);

	result.vertexs	= new Vector[result.vertexs_size];
	result.normals	= new Vector[result.indicies_size];
	result.indicies = new int[result.indicies_size];
	result.vertexs_copy = new Vector[result.vertexs_size];

	result.uv_indicies	= new int[result.indicies_size];
	result.materials = new int[result.indicies_size];
	result.uv_coords	= new Vector[result.uv_size];

	for (int i = 0; i < result.vertexs_size; i++)
	{
		fread(&x, sizeof(float), 1, file);
		fread(&y, sizeof(float), 1, file);
		fread(&z, sizeof(float), 1, file);
		result.vertexs[i] = Vector(x, y, z);
	}
	for (int i = 0; i < result.indicies_size; i++)
	{
		fread(&x, sizeof(float), 1, file);
		fread(&y, sizeof(float), 1, file);
		fread(&z, sizeof(float), 1, file);
		result.normals[i] = Vector(x, y, z);
	}
	fread(result.indicies,		sizeof(int),    result.indicies_size,	file);
	fread(result.uv_indicies,	sizeof(int),	result.indicies_size,	file);
	for (int i = 0; i < result.uv_size; i++)
	{
		fread(&x, sizeof(float), 1, file);
		fread(&y, sizeof(float), 1, file);
		result.uv_coords[i] = Vector(x, y, 0);
	}
	fread(result.materials, sizeof(int), result.indicies_size, file);

	fclose(file);
	return result;
}