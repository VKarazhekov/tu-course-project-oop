#include <iostream>
#include <vector>
#include "ProgramLogic.hh"
using namespace std;
vector<Provider> providers;
ProgramLogic::ProgramLogic(){}
ProgramLogic::ProgramLogic(int temp1, int temp2)
{

}
bool checkInteger(string input)
{
    bool isNeg=false;
    int itr=0;
    if(input.size()==0)
        return false;
    if(input[0]=='-')
    {
        isNeg=true;
        itr=1;
    }
 
    for(int i=itr;i<input.size();i++)
    {
        if(!isdigit(input[i]))
            return false;
    }
    return true;
}
void ProgramLogic::showAvailableProviders()
{
    cout << "\nAvailable providers:\n\n";
    for (int i = 0; i < providers.size(); i++)
    {
        cout << "Provider #" << i+1 << ":\n" <<
        "\tBulstat: " << providers[i].getBulstat() << endl <<
        "\tName: " << providers[i].getName() << endl <<
        "\tLocation: " << providers[i].getLocation() << endl <<
        "\tphoneNumber: " << providers[i].getPhoneNumber() << "\n\n";
    }
    
}
void ProgramLogic::addProviders()
{
    string numOfProviders;
    while(true)
    {
        cout << "Enter how many providers you wish to add: ";
        cin >> numOfProviders;
        if(checkInteger(numOfProviders)==false || stoi(numOfProviders) < 1)
        {
            cout << "Invalid input detected. Please enter a whole number, greater than 0.\n";
        }
        else break;
    }
    for (int i = 0; i < stoi(numOfProviders); i++)
    {
        string tempBulstat;
        string tempName;
        string tempLocation;
        string tempPhoneNumber;
        while(true)
        {
            cout << "Enter the bulstat of provider #" << numOfProviders << ": ";
            cin >> tempBulstat;
            if(tempBulstat.length()<7 || tempBulstat.length()>10 || checkInteger(tempBulstat)==false)
            {
                cout << "Invalid input detected. Please enter a string of digits with a length between 7 and 13.\n";
            }
            else break;       
        }
        while(true)
        {
            cout << "Enter the name of provider #" << numOfProviders << ": ";
            cin >> tempName;
            if(tempName.length()>20 || tempName.length()<2) 
            {
                cout << "Invalid input detected. Please enter a string with length between 2 and 20 characters.\n";
            }
            else break;
        }
        while(true)
        {
            cout << "Enter the location of provider #" << numOfProviders << ": ";
            cin >> tempLocation;
            if(tempLocation.length()<2 || tempLocation.length()>20)
            {
                cout << "Invalid input detected. Please enter a string with length between 2 and 20 characters.\n";
            }
            else break;
        }
        while(true)
        {
            cout << "Enter the phone number of provider #" << numOfProviders << ": ";
            cin >> tempPhoneNumber;
            if(tempPhoneNumber.length()!=10 || checkInteger(tempPhoneNumber)==false)
            {
                cout << "Invalid input detected. Please enter a string with a length of 10 digits.\n";
            }
            else break;
        }
        Provider tempProvider(tempBulstat, tempName, tempLocation, tempPhoneNumber);
        providers.push_back(tempProvider);
    }
}
void ProgramLogic::mainMenu()
{
    int choice = 0;
    while(true)
    {
        cout << "Main menu:\n"
        "1 - Show available providers and their optics\n"
        "2 - Add providers\n"
        "3 - Add optics\n"
        "4 - Choose provider and calculate order price\n"
        "5 - Exit\n"
        "Enter choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                showAvailableProviders();
                break;
            case 2:
                addProviders();
                break;
            case 3:
                //call a function to add optics
                break;
            case 4:
                //call a function to choose provider and calculate order price
                break;
            case 5:
                return;
            default:
                cout << "Invalid input detected. Please enter a number between 1 and 5 inclusive.\n";
        }
    }

}