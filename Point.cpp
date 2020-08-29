#include "Point.h"

Point::Point()
{
	this->x = "";
	this->y = "";
}

Point::Point(string x, string y)
{
	this->x = x;
	this->y = y;
}

string Point::getX()
{
	return this->x;
}

void Point::setX(string x)
{
	this->x = x;
}

string Point::getY()
{
	return this->y;
}

void Point::setY(string y)
{
	this->y = y;
}