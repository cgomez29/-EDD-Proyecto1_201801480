#include "MainMenu.h"


MainMenu::MainMenu()
{
    this->controller = new ControllerProject();
    this->contadorProyecto = 1;
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
                verProjectos();
                break;
            case 2:
                break;
            case 3:
                llenarArbolAVL(readJson->leerProyectos("prueba"));
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                llenarArbolB(readJson->leerLibrerias("preuba"));
                break;
            }



        } while (entrada != 7);
    }

}


void MainMenu::llenarArbolB(SimpleListLibreria* list)
{
    NodoO* aux = list->getHead();
    while (aux != NULL)
    {
        treeB->insert(aux->getObjeto());
        aux = aux->getSiguiente();
    }
    //treeB->graficar();
}

void MainMenu::llenarArbolAVL(SimpleListProject* list)
{
    NodoProject* aux = list->getHead();

    while (aux != NULL)
    {
        aux->getProject()->setId(contadorProyecto);
        treeAVL->insertar(aux->getProject());
        aux = aux->getSiguiente();
        contadorProyecto++;
    }
    //treeAVL->graficar();
}

void MainMenu::verProjectos()
{
    int contador = 0;
    NodoAVL* nodoFound = nullptr;
    Project* project = NULL;
    do
    {
        system("cls");
        cout << "Lista de proyectos" << endl;
        treeAVL->inOrden();
        cout << endl;
        cout << "Ingrese el numero del proyecto a graficar" << endl;
        cout << "Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        int id;
        cin >> id;

        if (id == 0)
        {
            break;
        }

        NodoAVL* nodoFound = treeAVL->buscarNodo(id);

        if (nodoFound != nullptr)
        {
            NodoM* headList = nodoFound->getProject()->getListNivel()->getHead();
            project = nodoFound->getProject();

            while (headList != NULL)
            {
                headList->getMatrix()->graficar();
                //cin >> id;
                headList = headList->getSiguiente();
            }
            contador = 0;
        }
        else
        {
            cout << "Numero no valido" << endl;
            cin >> id;
            contador = 1;
        }
    } while (contador != 0);
    

    if (project != NULL)
    {
        int entrada = 0;
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
                agregarNiveles(project, readJson->leerNivel("prueba"));
                break;
            case 2:
                break;
            case 3:
                eliminarNivel(project);
                break;
            case 4:
                break;
            case 5:
                break;
            }


        } while (entrada != 5);
    
    }

}

void MainMenu::agregarNiveles(Project* project, SimpleListM* list)
{
    NodoM* aux = list->getHead();

    while (aux != NULL)
    {
        project->getListNivel()->add(aux->getMatrix());
        aux->getMatrix()->graficar();
        aux = aux->getSiguiente();
    }

}

void MainMenu::eliminarNivel(Project* project)
{
    NodoM* aux = project->getListNivel()->getHead();
    int id;
    do
    {
        system("cls");
        cout << "Lista de niveles en el proyecto: " << project->getName() << endl;
        while (aux != NULL)
        {
            cout << aux->getMatrix()->getId() << ". " << aux->getMatrix()->getName() << endl;
            aux = aux->getSiguiente();
        }
        cout << endl;
        cout << "Ingrese el numero del nivel a eliminar" << endl;
        cout << "Ingrese 0 si desea salir" << endl;
        cout << ">> ";
        cin >> id;
        if (id == 0) { break; }

        if (project->getListNivel()->delete_item(id))
        {
            cout << "NIVEL ELIMINADO" << endl;
            cin >> id;
            break;
        }
        else {
            cout << "Elemento no encontrado!!" << endl;
            cin >> id;
            id = 1;
        }


    } while (id != 0);
}