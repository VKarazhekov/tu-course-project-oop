#ifndef HH_PROGRAMLOGIC
#define HH_PROGRAMLOGIC
#include <iostream>
#include <vector>
#include <algorithm>
#include "models/Optics.hh"
#include "models/Provider.hh"
using namespace std;
class ProgramLogic
{
    private:
        void showAvailableProviders();
        void addProviders();
        void addOptics();
        void placeOrder();
    public:
        ProgramLogic();
        ProgramLogic(int temp1, int temp2);
        void mainMenu();
};
#endif