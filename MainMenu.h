#include "ControllerProject.h"
#include "conio.h"
#include "ReadJSON.h"
#include <iostream>
#include "ArbolAVL.h"
#include "SimpleListLibreria.h"
#include "NodoO.h"
#include "SimpleListProject.h"
#include "NodoProject.h"
using namespace std;

class MainMenu
{

private:
    ControllerProject* controller;
    ReadJSON* readJson = new ReadJSON();
    ArbolAVL* treeAVL = new ArbolAVL();
    ArbolB* treeB = new ArbolB();
    void llenarArbolB(SimpleListLibreria* list);
    void llenarArbolAVL(SimpleListProject* list);
    void verProjectos();
    int contadorProyecto;

public:
    MainMenu();
    ~MainMenu();
    void menu();

};
