
#include <iostream>
#include "ArbolAVL.h"
#include "Project.h"
#include "Matrix.h"

using namespace std;

class ControllerProject
{

private: 
    ArbolAVL* arbol = new ArbolAVL();
    void selectedProject(Project project);
    void agregarNivel(Project project);
    void editarNivel(Project project);
    void eliminarNivel(Project project);
    void eliminarProyecto(Project project);


public:
    void viewProjects();
    
};
