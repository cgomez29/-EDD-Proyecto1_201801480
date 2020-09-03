#include "MainMenu.h"


MainMenu::MainMenu()
{
    this->controller = new ControllerProject();
}


void MainMenu::menu()
{
    cout << "**************************************" << endl;
    cout << "* USAC                               *" << endl;
    cout << "* ESTRUCTURAS DE DATOS               *" << endl;
    cout << "* SECCION A:                         *" << endl;
    cout << "* Cristian Alexander Gomez Guzman    *" << endl;
    cout << "* Carnet: 201801480                  *" << endl;
    cout << "**************************************" << endl;
    int entrada = 0;
    char enter = _getch();
    //cin >> enter;
    if (enter == 13)
    {
        do
        {
            system("cls");
            cout << "1. Ver proyectos" << endl;
            cout << "2. Editar proyectos" << endl;
            cout << "3. Cargar proyectos" << endl;
            cout << "4. Graficar proyectos" << endl;
            cout << "5. Guardar proyectos" << endl;
            cout << "6. Cargar librerias" << endl;
            cout << "7. salir" << endl;
            cout << ">> ";
            cin >> entrada;

            switch (entrada)
            {
            case 1:
                this->controller->viewProjects();
                break;
            case 2:
                break;
            case 3:
                //cargar proyectos
                readJson->leerProyectos();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                //cargar librerias
                readJson->leerLibrerias();
                break;
            }



        } while (entrada != 7);
    }

}
