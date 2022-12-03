#ifndef HH_PROVIDER
#define HH_PROVIDER
#include <iostream>
using namespace std;

class Provider
{
    private:
        string bulstat;
        string name;
        string location;
        string phoneNumber;
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
};

#endif