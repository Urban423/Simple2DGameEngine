#pragma once
#include <cmath>

//����� ������� | ����� � ���������� ������������
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

	//������� ������������ ���� �� ���������
	double operator[](const int n);

	//�������, ������������ ����� �������
	double len();

	//�������, ������������ ��������������� ������
	Vector norm();

	//��������� ��� ������ � ���������
	Vector operator+(Vector vec2);
	Vector operator-(Vector vec2);
	Vector operator*(double multiplier);
	double operator*(Vector vec2);
};