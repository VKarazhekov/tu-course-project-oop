#ifndef HH_PROGRAMLOGIC
#define HH_PROGRAMLOGIC
#include <iostream>
#include <vector>
#include "models/Optics.hh"
#include "models/Provider.hh"
using namespace std;
class ProgramLogic
{
    private:
        vector<Provider> providers;
        vector<Optics> optics;
    public:
        ProgramLogic();
        ProgramLogic(int temp1, int temp2);
        int mainMenu();
};
#endif