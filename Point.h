#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
private: 
	//Coordenadas
	string x;
	string y;

public:
	Point();
	Point(string x, string y);
	string getX();
	void setX(string x);
	string getY();
	void setY(string y);
};

#endif // !POINT_H


