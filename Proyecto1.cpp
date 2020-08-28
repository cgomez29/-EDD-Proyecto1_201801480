#include <iostream>
#include "MainMenu.h"

#include "Objeto.h"
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix* matrix= new Matrix();
    //// parametros: nombre, posX 1, posY 1
    Objeto* o = new Objeto("0", "0","0");
    Objeto* o1 = new Objeto("2", "1", "2");
    Objeto* o2 = new Objeto("3", "2", "1");
    Objeto* o3 = new Objeto("4", "2", "3");
    Objeto* o4 = new Objeto("5", "2", "2");
                   //H -> X , V -> Y
    matrix->add(o, "0", "0");
    matrix->add(o1, "1", "2");
    matrix->add(o2, "2", "1");
    matrix->add(o4, "2", "2");
    matrix->add(o3, "2", "3");
    
    matrix->graficar();
    delete matrix;

    /*MainMenu* menu = new MainMenu();
    menu->menu();
    delete menu;*/
    return 0;
}
