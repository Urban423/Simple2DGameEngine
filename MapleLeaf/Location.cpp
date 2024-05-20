#include "Location.h"

Location::Location() : x(0), y(0) {}

Location::Location(float x, float y): x(x), y(y) {}

Location::~Location(){}

float Location::getX(){return x;}

float Location::getY(){return y;}

void Location::setX(float x){this->x = x;}

void Location::setY(float y){this->y = y;}