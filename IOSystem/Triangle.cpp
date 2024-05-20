#include "Triangle.h"
#include <stdio.h>
#include <process.h>
#include "Vector.h"
#include "Vector2.h"
#include <math.h>
#include "utilities.h"

void swap_int(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_float(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

void swap_Vector3(Vector* a, Vector* b)
{
	Vector temp = *a;
	*a = *b;
	*b = temp;
}

void DrawTriangle(TriangleInput* in)
{
	int* buffer = in->buffer;
	int height = in->height;
	int width = in->width;
	int color = in->color;

	int x1 = in->x1;
	int x2 = in->x2;
	int x3 = in->x3;

	int y1 = in->y1;
	int y2 = in->y2;
	int y3 = in->y3;

	if (y1 > y2)
	{
		swap_int(&x1, &x2);
		swap_int(&y1, &y2);
	}
	if (y1 > y3)
	{
		swap_int(&x1, &x3);
		swap_int(&y1, &y3);
	}
	if (y2 > y3)
	{
		swap_int(&x2, &x3);
		swap_int(&y2, &y3);
	}

	float dx13 = 0;
	float dx12 = 0;
	float dx23 = 0;
	if (y3 != y1)
	{
		dx13 = (float)(x3 - x1);
		dx13 /= y3 - y1;
	}
	if (y2 != y1)
	{
		dx12 = (float)(x2 - x1);
		dx12 /= (y2 - y1);
	}
	if (y3 != y2)
	{
		dx23 = (float)(x3 - x2);
		dx23 /= (y3 - y2);
	}



	//draw bottom triangle part
	int* pointer_buffer;
	float wx1 = (float)x1 - 1;
	float wx2 = wx1 + 1;
	float _dx13 = dx13;

	if (dx13 > dx12)
	{
		swap_float(&dx13, &dx12);
	}


	//calculate y start y end
	int st;
	int st_y = y1;
	if (st_y < 0)
	{
		if (y2 > 0)
		{
			wx1 += -st_y * dx13;
			wx2 += -st_y * dx12;
		}
		st_y = 0;
	}
	int end_y = y2;
	if (end_y > height - 1)
	{
		end_y = height;
	}

	for (int y = st_y; y < end_y; y++)
	{
		//calculate start row's x and end row's x
		st = (int)wx1;
		if (st < 0) { st = 0; }
		int end_x = (int)wx2;
		if (end_x > width - 1)
		{
			end_x = width;
		}

		//calculate new row's of buffer index
		pointer_buffer = buffer + width * y + st;

		for (int x = st; x < end_x; x++)
		{
			*pointer_buffer = color;
			//step for the next pixel in buffer
			pointer_buffer++;
		}

		//calculate new row's x coordinates
		wx1 += dx13;
		wx2 += dx12;
	}



	//draw top triangle part
	if (y1 == y2)
	{
		if (x1 > x2)
		{
			swap_int(&x1, &x2);
			swap_int(&y1, &y2);
		}
		wx1 = (float)x1;
		wx2 = (float)x2;
	}
	else
	{
		if (y2 <= 0)
		{
			int m = abs(y1 - y2);
			wx1 += m * dx13;
			wx2 += m * dx12;
		}
	}

	if (_dx13 < dx23)
	{
		swap_float(&_dx13, &dx23);
	}
	if (wx1 > wx2)
	{
		swap_float(&wx1, &wx2);
	}

	st_y = y2;
	if (st_y < 0)
	{
		st_y = -st_y;
		wx1 += st_y * _dx13;
		wx2 += st_y * dx23;
		st_y = 0;
	}
	end_y = y3;
	if (end_y > height - 1)
	{
		end_y = height;
	}

	for (int y = st_y; y < end_y; y++)
	{
		//calculate start row's x and end row's x
		st = (int)wx1;
		if (st < 0) { st = 0; }
		int end_x = (int)wx2;
		if (end_x > width - 1)
		{
			end_x = width;
		}

		//calculate new row's of buffer index
		pointer_buffer = buffer + width * y + st;

		for (int x = st; x < end_x; x++)
		{
			*pointer_buffer = color;

			//step for the next pixel in buffer
			pointer_buffer++;
		}

		//calculate new row's x coordinates
		wx1 += _dx13;
		wx2 += dx23;
	}
}