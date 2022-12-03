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
        Provider() {}
        Provider(string bulstat, string name, string location, string phoneNumber)
        {
            this->bulstat=bulstat;
            this->name=name;
            this->location=location;
            this->phoneNumber=phoneNumber;
        }
        void setBulstat(string bulstat)
        {
            this->bulstat = bulstat;
        }
        string getBulstat()
        {
            return bulstat;
        }
        void setName(string name)
        {
            this->name = name;
        }
        string getName()
        {
            return name;
        }
        void setLocation(string location)
        {
            this->location = location;
        }
        string getLocation()
        {
            return location;
        }
        void setPhoneNumber(string phoneNumber)
        {
            this->phoneNumber = phoneNumber;
        }
        string getPhoneNumber()
        {
            return phoneNumber;
        }
};