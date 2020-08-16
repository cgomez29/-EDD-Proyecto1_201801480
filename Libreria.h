#pragma once
#include "SimpleList.h"
#include "Point.h"
#include <iostream>

using namespace std;

class Libreria
{
private:
	int id;
	string name;
	string letter;
	string color;
	SimpleList<Point> list;

public:
	int getId();
	string getName();
	string getLetter();
	string getColor();
	void setId(int id);
	void setName(string name);
	void setLetter(string letter);
	void setColor(string color);
	SimpleList<Point> getList();
};

