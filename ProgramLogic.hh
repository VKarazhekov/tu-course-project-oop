#ifndef HH_PROGRAMLOGIC
#define HH_PROGRAMLOGIC
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
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
        ProgramLogic(Provider prov1, Optics optics1);
        void mainMenu();
};
#endif