#ifndef HH_PROVIDER
#define HH_PROVIDER
#include <iostream>
#include <vector>
#include "Optics.hh"
using namespace std;

class Provider
{
    private:
        string bulstat;
        string name;
        string location;
        string phoneNumber;
        vector<Optics> optics;
    public:
        Provider();
        Provider(string bulstat, string name, string location, string phoneNumber);
        void setBulstat(string bulstat);
        string getBulstat();
        void setName(string name);
        string getName();
        void setLocation(string location);
        string getLocation();
        void setPhoneNumber(string phoneNumber);
        string getPhoneNumber();
        void addOptics(Optics optics);
        vector<Optics> getOptics();
};

#endif