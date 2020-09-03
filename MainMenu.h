#include "ControllerProject.h"
#include "conio.h"
#include "ReadJSON.h"
#include <iostream>

using namespace std;

class MainMenu
{

private:
    ControllerProject* controller;
    ReadJSON* readJson = new ReadJSON();
public:
    MainMenu();
    ~MainMenu();
    void menu();

};
