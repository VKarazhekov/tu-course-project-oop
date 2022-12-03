#ifndef HH_OPTICS
#define HH_OPTICS
#include <iostream>
using namespace std;

class Optics
{
    private:
        string type;
        float thickness;
        float dioptre;
        string name;
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
};

#endif
