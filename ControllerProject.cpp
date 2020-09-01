#include "ControllerProject.h"

void ControllerProject::viewProjects()
{
    cout << "Lista de proyectos" << endl;
    
    



}

void ControllerProject::selectedProject(Project project)
{
    int entrada;
    do
    {
        system("cls");
        cout << "1. Agregar nivel" << endl;
        cout << "2. Editar nivel" << endl;
        cout << "3. Eliminar nivel" << endl; 
        cout << "4. Eliminar proyecto" << endl;
        cout << "5. Salir" << endl;
        cout << ">> ";
        cin >> entrada;

        switch (entrada)
        {
        case 1:
            agregarNivel(project);
            break;
        case 2:
            
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            break;
        }



    } while (entrada != 5);
}


void ControllerProject::agregarNivel(Project project)
{

    Matrix matriz = Matrix();

    project.addNivel(matriz);

}

void  ControllerProject::editarNivel(Project project)
{

}

void ControllerProject::eliminarNivel(Project project)
{

}

void ControllerProject::eliminarProyecto(Project project)
{

}