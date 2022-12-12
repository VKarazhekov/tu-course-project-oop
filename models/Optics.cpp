#include <iostream>
#include "Optics.hh"
using namespace std;

Optics::Optics(){}
Optics::Optics(string type, float thickness, float dioptre, string name, double price)
{
    this->type=type;
    this->thickness=thickness;
    this->dioptre=dioptre;
    this->name=name;
    this->price=price;
}
void Optics::setType(string type)
{
    this->type = type;
}
string Optics::getType()
{
    return type;
}
void Optics::setThickness(float thickness)
{
    this->thickness = thickness;
}
float Optics::getThickness()
{
    return thickness;
}
void Optics::setDioptre(float dioptre)
{
    this->dioptre = dioptre;
}
float Optics::getDioptre()
{
    return dioptre;
}
void Optics::setName(string name)
{
    this->name = name;
}
string Optics::getName()
{
    return name;
}
void Optics::setPrice(double &price)
{
    this->price=price;
}
double Optics::getPrice()
{
    return price;
}