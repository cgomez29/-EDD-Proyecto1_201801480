#include <iostream>
#include "MainMenu.h"

#include "Objeto.h"
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix* matrix= new Matrix();

    Objeto* o = new Objeto("obj1");

    matrix->add(o);

    delete matrix;

    /*MainMenu* menu = new MainMenu();
    menu->menu();
    delete menu;*/
    return 0;
}
