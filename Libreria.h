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
	SimpleList<Point>* list;

public:
	Libreria();
	int getId();
	string getName();
	string getLetter();
	string getColor();
	SimpleList<Point>* getList();
	void setId(int id);
	void setName(string name);
	void setLetter(string letter);
	void setColor(string color);
	void setSimpleList(SimpleList<Point>* list);
};

