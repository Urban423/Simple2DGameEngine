#include "utilities.h"
#include <stdio.h>

char* keyBoardState;
char* oldKeyBoardState;

float adabt(float a, float b)
{
	return -a / (b - a);
}


int setColorWithRGB(int r1, int g1, int b1, int r2, int g2, int b2, float k)
{
	//0xAA'RR'GG'BB
	int res = 0;
	r1 = (1.0f - k) * (float)r1 + k * (float)r2;
	if (r1 > 255) { r1 = 255; }
	g1 = (1.0f - k) * (float)g1 + k * (float)g2;
	if (g1 > 255) { g1 = 255; }
	b1 = (1.0f - k) * (float)b1 + k * (float)b2;
	if (b1 > 255) { b1 = 255; }
	res = (r1 << 16) + (g1 << 8) + b1;
	return res;
}

char setKeyBoard(char* keyBoardStatePointer, char* oldKeyBoardStatePointer)
{
	keyBoardState = keyBoardStatePointer;
	oldKeyBoardState = oldKeyBoardStatePointer;
	return 0;
}

char GetKey(char key_code)
{
	if (keyBoardState[key_code] >> 7)
	{
		return 1;
	}
	return 0;
}

char GetKeyDown(char key_code)
{
	if (keyBoardState[key_code] >> 7 && !(oldKeyBoardState[key_code] >> 7))
	{
		return 1;
	}
	return 0;
}

char GetKeyUp(char key_code)
{
	if (!(keyBoardState[key_code] >> 7) && oldKeyBoardState[key_code] >> 7)
	{
		return 1;
	}
	return 0;
}
