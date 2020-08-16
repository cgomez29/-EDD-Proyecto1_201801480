#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

int Point::getX()
{
	return this->x;
}

void Point::setX(int x)
{
	this->x = x;
}

int Point::getY()
{
	return this->y;
}

void Point::setY(int y)
{
	this->y = y;
}