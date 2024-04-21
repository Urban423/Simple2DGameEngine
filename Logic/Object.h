#pragma once
#include "Verticle.h"
#include "utilities.h"

class Object : public Verticle
{
public:
	Object();
	~Object();

	void Update();
public:
	unsigned char up = KeyCode_UpArrrow;
	unsigned char down = KeyCode_DownArrow;
	unsigned char left = KeyCode_LeftArrow;
	unsigned char right = KeyCode_RightArrow;
	unsigned char rotate_left;
	unsigned char rotate_right;

	float speed = 0.5f;
	float rotation = 0;
};

