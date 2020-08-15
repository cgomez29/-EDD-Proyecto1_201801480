#include <iostream>
#include "MainMenu.h"
using namespace std;

int main()
{
    MainMenu* menu = new MainMenu();
    menu->menu();
    delete menu;
    return 0;
}
