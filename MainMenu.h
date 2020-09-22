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
#include "NodoAVL.h"
#include "Project.h"
using namespace std;

class MainMenu
{

private:
    //Arbol global de proyectos
    ArbolAVL* treeAVL = new ArbolAVL();
    //Arbol global de librerias
    ArbolB* treeB = new ArbolB();
    // Lectura de .json
    ReadJSON* readJson = new ReadJSON();
    
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
    void guardarProyectos();
    void agregarObjeto();
    void eliminarObjeto(ArbolB* nivel);
    void copiarNivel(Project* project);
    void graficarNivel(ArbolB* nivel);
    void reportes();
    bool valorAscii(string cadena);
    void nivelDesc();
    void nivelAsc();
    void reportInPorject();
    void eliminarProyecto(Project* project);

public:
    MainMenu();
    ~MainMenu();
    void menu();

};
