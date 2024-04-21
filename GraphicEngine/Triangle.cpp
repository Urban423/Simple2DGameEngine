#include "Triangle.h"
#include <stdio.h>
#include <process.h>
#include <Vector.h>
#include <Vector2.h>
#include <math.h>
#include <utilities.h>

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

void swap_Vector2(Vector2* a, Vector2* b)
{
	Vector2 temp = *a;
	*a = *b;
	*b = temp;
}

void sortThreeTrinanglePointsByY(Vector* a, Vector* b, Vector* c)
{
	if (a->y > b->y)
	{
		swap_Vector3(a, b);
	}
	if (a->y > c->y)
	{
		swap_Vector3(a, c);
	}
	if (b->y > c->y)
	{
		swap_Vector3(b, c);
	}
}

int RGBtoInt(char r, char g, char b)
{
	return (r << 16) + (g << 8) + b;
}
void DrawTriangleByTexture(void* input)
{
	TriangleInput* in = (TriangleInput*)input;
	//printf("c: %d\n", *(in->threads_counter));

	int* buffer = in->buffer;
	int height = in->height;
	int width = in->width;

	int x1 = in->x1;
	int x2 = in->x2;
	int x3 = in->x3;

	int y1 = in->y1;
	int y2 = in->y2;
	int y3 = in->y3;

	int color = 0x00'FF'5F'03;

	Texture texture = in->texture;

	Vector2 uv1 = in->uv1;
	Vector2 uv2 = in->uv2;
	Vector2 uv3 = in->uv3;

	if (y1 > y2)
	{
		swap_int(&x1, &x2);
		swap_int(&y1, &y2);
		swap_Vector2(&uv1, &uv2);
	}
	if (y1 > y3)
	{
		swap_int(&x1, &x3);
		swap_int(&y1, &y3);
		swap_Vector2(&uv1, &uv3);
	}
	if (y2 > y3)
	{
		swap_int(&x2, &x3);
		swap_int(&y2, &y3);
		swap_Vector2(&uv2, &uv3);
	}

	char changed = 0;
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

	float wx1 = (float)x1 - 1;
	float wx2 = wx1 + 1;
	float _dx13 = dx13;

	if (dx13 > dx12)
	{
		swap_float(&dx13, &dx12);
	}

	int tex_x = 0;
	int tex_y = 0;
	int* pointer_buffer;
	unsigned int index_of_texture = 0;
	int max_texture_x = texture.width - 1;
	int max_texture_y = texture.height - 1;


	int y_from_left = y2;
	int y_from_right = y3;
	if (x2 > x3)
	{
		changed = 1;
		swap_int(&y_from_left, &y_from_right);
		swap_Vector2(&uv2, &uv3);
	}

	double u_left = uv1.x;
	double v_left = uv1.y;
	double u_right = u_left;
	double v_right = v_left;
	double delta_u_left = (uv2.x - u_left) / (y_from_left - y1);
	double delta_v_left = (uv2.y - v_left) / (y_from_left - y1);

	double delta_u_right = (uv3.x - u_left) / (y_from_right - y1);
	double delta_v_right = (uv3.y - v_left) / (y_from_right - y1);

	double u;
	double v;
	double delta_u;
	double delta_v;


	//calculate y start y end
	int st;
	int st_y = y1;
	if (st_y < 0)
	{
		if (y2 > 0)
		{
			u_left += -st_y * delta_u_left;
			v_left += -st_y * delta_v_left;
			u_right += -st_y * delta_u_right;
			v_right += -st_y * delta_v_right;

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
		u = u_left;
		v = v_left;
		delta_u = (u_right - u_left) / (wx2 - wx1);
		delta_v = (v_right - v_left) / (wx2 - wx1);


		//calculate start row's x and end row's x
		st = (int)wx1;
		if (st < 0)
		{
			u += -st * delta_u;
			v += -st * delta_v;
			st = 0;
		}
		int end_x = (int)wx2;
		if (end_x > width - 1)
		{
			end_x = width;
		}

		//calculate new row's of buffer index
		pointer_buffer = buffer + width * y + st;

		for (int x = st; x < end_x; x++)
		{
			tex_x = (int)(u * texture.width);
			tex_y = (int)(v * texture.height);

			index_of_texture = tex_y * texture.width + tex_x;

			
			*pointer_buffer = color;

			u += delta_u;
			v += delta_v;
			//step for the next pixel in buffer
			pointer_buffer++;
		}
		u_left += delta_u_left;
		v_left += delta_v_left;

		u_right += delta_u_right;
		v_right += delta_v_right;

		//calculate new row's x coordinates
		wx1 += dx13;
		wx2 += dx12;
	}



	//draw top triangle part

	if (changed == 1)
	{
		swap_Vector2(&uv2, &uv3);
	}
	if (y1 == y2)
	{
		if (x1 > x2)
		{
			swap_int(&x1, &x2);
			swap_int(&y1, &y2);
			swap_Vector2(&uv1, &uv2);
		}
		u_left = uv1.x;
		v_left = uv1.y;
		u_right = uv2.x;
		v_right = uv2.y;
		wx1 = (float)x1;
		wx2 = (float)x2;

		delta_u_left = (uv3.x - u_left) / (y3 - y2);
		delta_v_left = (uv3.y - v_left) / (y3 - y2);
		delta_u_right = (uv3.x - u_right) / (y3 - y2);
		delta_v_right = (uv3.y - v_right) / (y3 - y2);
	}
	else
	{
		if (y2 <= 0)
		{
			int m = abs(y1 - y2);
			u_left += m * delta_u_left;
			v_left += m * delta_v_left;
			u_right += m * delta_u_right;
			v_right += m * delta_v_right;

			wx1 += m * dx13;
			wx2 += m * dx12;
		}
		if (x2 > x3)
		{
			delta_u_right = (uv3.x - u_right) / (y3 - y2);
			delta_v_right = (uv3.y - v_right) / (y3 - y2);
		}
		else
		{
			//wx1 = x2;
			delta_u_left = (uv3.x - u_left) / (y3 - y2);
			delta_v_left = (uv3.y - v_left) / (y3 - y2);
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
		u_left += st_y * delta_u_left;
		v_left += st_y * delta_v_left;
		u_right += st_y * delta_u_right;
		v_right += st_y * delta_v_right;

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
		u = u_left;
		v = v_left;
		delta_u = (u_right - u_left) / (wx2 - wx1);
		delta_v = (v_right - v_left) / (wx2 - wx1);


		//calculate start row's x and end row's x
		st = (int)wx1;
		if (st < 0)
		{
			u += -st * delta_u;
			v += -st * delta_v;
			st = 0;
		}
		int end_x = (int)wx2;
		if (end_x > width - 1)
		{
			end_x = width;
		}

		//calculate new row's of buffer index
		pointer_buffer = buffer + width * y + st;

		for (int x = st; x < end_x; x++)
		{
			tex_x = (int)(u * texture.width);
			tex_y = (int)(v * texture.height);

			index_of_texture = tex_y * texture.width + tex_x;


			
			*pointer_buffer = color;

			u += delta_u;
			v += delta_v;

			//step for the next pixel in buffer
			pointer_buffer++;
		}

		u_left += delta_u_left;
		v_left += delta_v_left;

		u_right += delta_u_right;
		v_right += delta_v_right;

		//calculate new row's x coordinates
		wx1 += _dx13;
		wx2 += dx23;
	}

	//(*in->counter)++;
	//_endthread();
}