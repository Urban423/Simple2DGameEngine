#include "Vector.h"

Vector Vector::Cross(Vector a, Vector b)
{
	return Vector(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::operator[](int n) {
	switch (n) {
		case 1:
			return x;
		case 2:
			return y;
		case 3:
			return z;
	}
}

double Vector::len() {
	return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::norm() {
	double Length = this->len();
	if (Length == 0) { return Vector(0, 0, 0); }
	Vector NormalizeVector(x / Length, y / Length, z / Length);

	return NormalizeVector;
}

Vector Vector::operator+(Vector vec2) {
	Vector newVec(this->x + vec2[1], this->y + vec2[2], this->z + vec2[3]);
	return newVec;
}

Vector Vector::operator-(Vector vec2) {
	Vector newVec(this->x - vec2[1], this->y - vec2[2], this->z - vec2[3]);
	return newVec;
}

Vector Vector::operator*(double multiplier) {
	Vector newVec(this->x * multiplier, this->y * multiplier, this->z * multiplier);
	return newVec;
}

double Vector::operator*(Vector vec2) {
	return x * vec2[1] + y * vec2[2] + z * vec2[3];
}