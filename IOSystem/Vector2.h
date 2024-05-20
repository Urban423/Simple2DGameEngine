#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();
public:
	float length();
	Vector2 normalize();
public:
	float x;
	float y;
};

