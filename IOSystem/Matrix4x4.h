#pragma once
#include "Vector.h"

class Matrix4x4
{
public:
	Matrix4x4();
	//~Matrix4x4();

	void setIdentity();
	float getDeterminant();
	void inverse();
	
	void setScale(const float x, const float y, const float z);
	void setTranslation(const float x, const float y, const float z);
	void setRotation(const float x);

	void setViewPort(float width, float height);
	void setOrthoLH(float width, float height, float nearPlane, float farPlane);
	void setPerspectiveFovLH(float fov, float aspect, float nearPlane, float farPlane);

	Vector getXDirection();
	Vector getYDirection();
	Vector getZDirection();
	Vector getTranslation();
	float* getPtr();
public:
	void operator *=(const Matrix4x4& matrix);
	Vector operator *(Vector vec);
private:
	float mat[4][4] = {0};
};