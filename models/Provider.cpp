#include <iostream>
#include "Provider.hh"
using namespace std;
Provider::Provider() {}
Provider::Provider(string bulstat, string name, string location, string phoneNumber)
{
    this->bulstat=bulstat;
    this->name=name;
    this->location=location;
    this->phoneNumber=phoneNumber;
}
void Provider::setBulstat(string bulstat)
{
    this->bulstat = bulstat;
}
string Provider::getBulstat()
{
    return bulstat;
}
void Provider::setName(string name)
{
    this->name = name;
}
string Provider::getName()
{
    return name;
}
void Provider::setLocation(string location)
{
    this->location = location;
}
string Provider::getLocation()
{
    return location;
}
void Provider::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
string Provider::getPhoneNumber()
{
    return phoneNumber;
}
void Provider::addOptics(Optics optics)
{
    this->optics.push_back(optics);
}
vector<Optics> Provider::getOptics()
{
    return optics;
}