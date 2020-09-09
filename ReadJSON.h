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
#include "Objeto.h"
#include "ArbolAVL.h"
#include "SimpleListP.h"
#include "SimpleListLibreria.h"
#include "SimpleListProject.h"

using json = nlohmann::json;
using namespace std;

class ReadJSON
{
private:
	
public:
	SimpleListLibreria* leerLibrerias(string nameFile);
	SimpleListProject* leerProyectos(string nameFile);

	string nameFile();
};

#endif // READJSON_H


