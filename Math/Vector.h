#pragma once
#include <cmath>

//класс вектора | точки в трехмерном пространстве
class Vector
{
public:
	double x;
	double y;
	double z;
public:
	static Vector Cross(Vector a, Vector b);
public:
	Vector() {};
	Vector(double x, double y, double z);

	//фукнция возвращающая одну из координат
	double operator[](const int n);

	//функция, возвращающая длину вектора
	double len();

	//функция, возвращающая нормализованный вектор
	Vector norm();

	//операторы для работы с векторами
	Vector operator+(Vector vec2);
	Vector operator-(Vector vec2);
	Vector operator*(double multiplier);
	double operator*(Vector vec2);
};