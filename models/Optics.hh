#ifndef HH_OPTICS
#define HH_OPTICS
#include <iostream>
#include <vector>
#include "Provider.hh"
using namespace std;

class Optics
{
    private:
        float thickness;
        float dioptre;
        string type;
        string name;
        vector<Provider> providers;
    public:
        Optics();
        Optics(string type, float thickness, float dioptre, string name);
        void setType(string type);
        string getType();
        void setThickness(float thickness);
        float getThickness();
        void setDioptre(float dioptre);
        float getDioptre();
        void setName(string name);
        string getName();
        void addProvider(Provider provider);
        vector<Provider> getProviders();
};

#endif
