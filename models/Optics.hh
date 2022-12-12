#ifndef HH_OPTICS
#define HH_OPTICS
#include <iostream>
#include <vector>
using namespace std;

class Optics
{
    private:
        float thickness;
        float dioptre;
        double price;
        string type;
        string name;
    public:
        Optics();
        Optics(string type, float thickness, float dioptre, string name, double price);
        void setType(string type);
        string getType();
        void setThickness(float thickness);
        float getThickness();
        void setDioptre(float dioptre);
        float getDioptre();
        void setName(string name);
        string getName();
        void setPrice(double &price);
        double getPrice();
};

#endif
