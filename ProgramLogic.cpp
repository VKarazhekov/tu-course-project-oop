#include <iostream>
#include "ProgramLogic.hh"
using namespace std;
ProgramLogic::ProgramLogic(){}
ProgramLogic::ProgramLogic(int temp1, int temp2)
{

}
void mainMenu()
{
    int choice;
    cout << "Main menu:\n"
    "1 - Show available providers and their optics\n"
    "2 - Add providers\n"
    "3 - Add optics\n"
    "4 - Choose provider and calculate order price\n"
    "4 - Exit\n"
    "Enter choice: ";
    switch(choice)
    {
        case 1:
            //call a function to show available providers and their optics
            break;
        case 2:
            //call a function to show a menu for adding a provider
            break;
        case 3:
            //call a function to add optics
            break;
        case 4:
            //call a function to choose provider and calculate order price
            break;    
    }

}