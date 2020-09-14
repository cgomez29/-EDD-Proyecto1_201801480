#include "ControllerProject.h"
#include "conio.h"
#include "ReadJSON.h"
#include <iostream>
#include "ArbolAVL.h"
#include "SimpleListLibreria.h"
#include "NodoO.h"
#include "SimpleListProject.h"
#include "NodoProject.h"
#include "SimpleListArbolB.h"
#include "NodoSLB.h"
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
    void agregarNiveles(Project* project, SimpleListArbolB* list);
    void eliminarNivel(Project* project);
    void editarNivel(Project* project);
    void editarProyecto();
    void graficarProyectos();
    //Editar nivel
    void eliminarPared(ArbolB* nivel);
    bool isNum(string valor);

public:
    MainMenu();
    ~MainMenu();
    void menu();

};
