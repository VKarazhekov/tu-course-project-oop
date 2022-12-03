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
        Optics(){}
        Optics(string type, float thickness, float dioptre, string name)
        {
            this->type=type;
            this->thickness=thickness;
            this->dioptre=dioptre;
            this->name=name;
        }
        void setType(string type)
        {
            this->type = type;
        }
        string getType()
        {
            return type;
        }
        void setThickness(float thickness)
        {
            this->thickness = thickness;
        }
        float getThickness()
        {
            return thickness;
        }
        void setDioptre(float dioptre)
        {
            this->dioptre = dioptre;
        }
        float getDioptre()
        {
            return dioptre;
        }
        void setName(string name)
        {
            this->name = name;
        }
        string getType()
        {
            return name;
        }
};