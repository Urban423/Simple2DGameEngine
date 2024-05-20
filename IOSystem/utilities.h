#pragma once
#include "Vector.h"
#define KeyCode_Enter 13
#define KeyCode_Escape 27
#define KeyCode_Space 32

#define KeyCode_LeftArrow 37
#define KeyCode_UpArrrow 38
#define KeyCode_RightArrow 39
#define KeyCode_DownArrow  40

#define KeyCode_Alpha0  48
#define KeyCode_Alpha1  49
#define KeyCode_Alpha2  50
#define KeyCode_Alpha3  51
#define KeyCode_Alpha4  52
#define KeyCode_Alpha5  53
#define KeyCode_Alpha6  54
#define KeyCode_Alpha7  55
#define KeyCode_Alpha8  56
#define KeyCode_Alpha9  57
#define KeyCode_A  65
#define KeyCode_B  66
#define KeyCode_C  67
#define KeyCode_D  68
#define KeyCode_E  69
#define KeyCode_F  70
#define KeyCode_G  71
#define KeyCode_H  72
#define KeyCode_I  73
#define KeyCode_J  74
#define KeyCode_K  75
#define KeyCode_L  76
#define KeyCode_M  77
#define KeyCode_N  78
#define KeyCode_O  79
#define KeyCode_P  80
#define KeyCode_Q  81
#define KeyCode_R  82
#define KeyCode_S  83
#define KeyCode_T  84
#define KeyCode_U  85
#define KeyCode_V  86
#define KeyCode_W  87
#define KeyCode_X  88
#define KeyCode_Y  89
#define KeyCode_Z  90

float adabt(float a, float b);
int setColorWithRGB(int r1, int g1, int b1, int r2, int g2, int b2, float k);


char setKeyBoard(char* keyBoardStatePointer, char* oldKeyBoardStatePointer);
char GetKey(char key_code);
char GetKeyDown(char key_code);
char GetKeyUp(char key_code);


struct Mesh
{
	int* indicies;
	int indicies_size;

	Vector* vertexs;
	int vertexs_size;

	Vector* normals;
	Vector* vertexs_copy;

	int* uv_indicies;
	Vector* uv_coords;
	int uv_size;

	int* materials;
};