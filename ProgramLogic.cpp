#include "ProgramLogic.hh"
using namespace std;
vector<Provider> providers;
vector<Optics> optics;
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
void addOptics()
{
    string numOfOptics;
    while(true)
    {
        cout << "Enter how many optics you wish to add: ";
        cin >> numOfOptics;
        if(checkInteger(numOfOptics)==false || stoi(numOfOptics) < 1)
        {
            cout << "Invalid input detected. Please enter a whole number, greater than 0.\n";
        }
        else break;
    }
    for (int i = 0; i < stoi(numOfOptics); i++)
    {
        string tempType;
        float tempThickness;
        float tempDioptre;
        string tempName;
        while(true)
        {
            cout << "Enter the type of optics #" << i+1 << ": ";
            cin >> tempType;
            if(tempType.length()<2 || tempType.length()>10)
            {
                cout << "Invalid input detected. Please enter a string of characters with a length between 2 and 10.\n";
            }
            else break;       
        }
        while(true)
        {
            cout << "Enter the thickness of optics #" << i+1 << ": ";
            cin >> tempThickness;
            if(tempThickness<0 || tempThickness>1)
            {
                cout << "Invalid input detected. Please enter a floating point number between 0 and 1.\n";
            }
            else break; 
        }
        while(true)
        {
            cout << "Enter the dioptre of optics #" << i+1 << ": ";
            cin >> tempDioptre;
            if(tempDioptre<0 || tempDioptre>4)
            {
                cout << "Invalid input detected. Please enter a floating point number between 0 and 4.\n";
            }
            else break; 
        }   
        
        while(true)
        {
            cout << "Enter the name of optics #" << i+1 << ": ";
            cin >> tempName;
            if(tempName.length()<2 || tempName.length()>20)
            {
                cout << "Invalid input detected. Please enter a string of characters with a length between 2 and 20.\n";
            }
            else break;
        }
        Optics tempOptics(tempType, tempThickness, tempDioptre, tempName);
        int choice = 0;
        while(true)
        {
            while(true)
            {
                cout << "Choose which providers will be offering optics #" << numOfOptics << ":\n";
                for (int c = 0; c < providers.size(); c++)
                {
                    cout << c+1 << " - " << providers[c].getName() << endl;
                }
                cout << providers.size()+1 << " - Done\n";
                cout << "Enter choice: ";
                cin >> choice;
                if(choice < 1 || choice > providers.size()+1)
                {
                    cout << "Invalid input detected. Please enter a number between 1 and " << providers.size()+1 << ".\n";
                }
                else break;
            }
            if (choice == providers.size()+1) break;
            if(tempOptics.getProviders().empty())
            {
                tempOptics.addProvider(providers[choice-1]);
            }
            else
            {
                for (int d = 0; d < tempOptics.getProviders().size(); d++)
                {
                    
                    //if(tempOptics.getProviders()[d].getName() == providers[choice-1].getName())
                    if((tempOptics.getProviders()[d].getName().compare(providers[choice-1].getName()))==0)
                    {
                        cout << "You have already chosen " << 
                        providers[choice-1].getName() << 
                        " to be able to offer optics " << tempName <<
                        endl;
                    }
                    else
                    {
                        tempOptics.addProvider(providers[choice-1]);
                    }
                }
            }
            optics.push_back(tempOptics);
        }
    }
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
        for (int c = 0; c < optics.size(); c++)
        {
            for (int d = 0; d < optics[c].getProviders().size(); d++)
            {
                if(optics[c].getProviders()[d].getName() == providers[i].getName())
                {
                    cout << "\tOptics for provider "<<providers[i].getName()<<":\n"<<
                    "\t\tType: "<<optics[c].getType()<<"\n"<<
                    "\t\tThickness: "<<optics[c].getThickness()<<"\n"<<
                    "\t\tDioptre: "<<optics[c].getDioptre()<<"\n"<<
                    "\t\tName: "<<optics[c].getName()<<"\n";
                } 
            }
            
        }
        
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
            cout << "Enter the bulstat of provider #" << i+1 << ": ";
            cin >> tempBulstat;
            if(tempBulstat.length()<7 || tempBulstat.length()>10 || checkInteger(tempBulstat)==false)
            {
                cout << "Invalid input detected. Please enter a string of digits with a length between 7 and 13.\n";
            }
            else break;       
        }
        while(true)
        {
            cout << "Enter the name of provider #" << i+1 << ": ";
            cin >> tempName;
            if(tempName.length()>20 || tempName.length()<2) 
            {
                cout << "Invalid input detected. Please enter a string with length between 2 and 20 characters.\n";
            }
            else break;
        }
        while(true)
        {
            cout << "Enter the location of provider #" << i+1 << ": ";
            cin >> tempLocation;
            if(tempLocation.length()<2 || tempLocation.length()>20)
            {
                cout << "Invalid input detected. Please enter a string with length between 2 and 20 characters.\n";
            }
            else break;
        }
        while(true)
        {
            cout << "Enter the phone number of provider #" << i+1 << ": ";
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
                addOptics();
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