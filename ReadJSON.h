#ifndef READJSON_H
#define READJSON_H
// #define WIN32_LEAN_AND_MEAN 

#include <nlohmann/json.hpp>
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "ArbolB.h"
#include "ArbolAVL.h"

using json = nlohmann::json;
using namespace std;

class ReadJSON
{
private:
	ArbolB* treeB = new ArbolB();
	ArbolAVL* treeAVL = new ArbolAVL();


public:
	void leerLibrerias();
	void leerProyectos();

	string nameFile();
};

#endif // READJSON_H


