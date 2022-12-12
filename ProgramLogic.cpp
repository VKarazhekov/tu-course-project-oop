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
void ProgramLogic::addOptics()
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
        float tempThickness;
        float tempDioptre;
        double tempPrice;
        string tempType;
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
            else
            {
                for (int a = 0; a < optics.size(); a++)
                {
                    if(tempName == optics[a].getName())
                    {
                        cout << "An optics with the same name already exists!\n";
                        return;
                    }
                }
                break;
            }
        }
        while(true)
        {
            cout << "Enter the price of optics #" << i+1 << ": ";
            cin >> tempPrice;
            if(tempPrice<0)
            {
                cout << "Invalid input detected. Please enter a positive floating point number.\n";
            }
            else break;
        }
        cout << endl;
        Optics tempOptics(tempType, tempThickness, tempDioptre, tempName, tempPrice);
        optics.push_back(tempOptics);
        int choice = 0;
        int d = 0; //black magic
        while(true)
        {
            while(true)
            {
                cout << "Choose which provider will be offering optics #" << i+1 << ":\n";
                for (int c = 0; c < providers.size(); c++)
                {
                    cout << c+1 << " - " << providers[c].getName() << endl;
                }
                //TO DO: add price input
                cout << providers.size()+1 << " - Done\n";
                cout << "Enter choice: ";
                cin >> choice; 
                if(choice < 1 || choice > providers.size()+1)
                {
                    cout << "Invalid input detected. Please enter a number between 1 and " << providers.size()+1 << ".\n";
                }
                else break;
            }
            if(choice==providers.size()+1) break;
            if(providers[choice-1].getOptics().empty())
            {
                providers[choice-1].addOptics(tempOptics);
            }
            else
            {
                for (; d < providers[choice-1].getOptics().size(); d++)
                {
                    if(providers[choice-1].getOptics()[d].getName() == tempName)
                    {
                        cout << "Provider " << providers[choice-1].getName() << " already offers optics " << tempName << "!\n";
                        break;
                    }
                    else
                    {
                        providers[choice-1].addOptics(tempOptics);
                        d++; //TO DO: debug!!!!!!!!!!!!
                        break;
                    }
                }
            }
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
        if(providers[i].getOptics().empty())
        {
            continue;
        }
        else
        {
            cout << "Optics for provider "<<providers[i].getName()<<":\n";
            for (int c = 0; c < providers[i].getOptics().size(); c++)
            {
                cout << "\tOptics #"<< c+1 <<":\n" \
                "\t\tType: "<<optics[c].getType()<<"\n"<< \
                "\t\tThickness: "<<optics[c].getThickness()<<"\n"<< \
                "\t\tDioptre: "<<optics[c].getDioptre()<<"\n"<< \
                "\t\tName: "<<optics[c].getName()<<"\n"<< \
                "\t\tPrice: "<<optics[c].getPrice()<<"\n";
                cout << endl;
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
        cout << endl;
    }
}
void ProgramLogic::placeOrder()
{
    int providerChoice = 0, opticsChoice = 0;
    double totalPrice = 0;
    bool providerIsPresent = 0, opticsIsPresent = false;
    while(true)
    {
        while(true)
        {
            showAvailableProviders();
            cout<<"\nEnter the number of provider you have chosen: ";
            cin>>providerChoice;
            if((providerChoice-1) < 0 || (providerChoice-1) >= providers.size())
            {
                cout << "Invalid input detected. Please enter a whole number between 1 and "<<providers.size()<<".\n";
            }
            else break;
        }
        for (int i = 0; i < providers.size(); i++)
        {
            if(providers[i].getName()==providers[providerChoice-1].getName())
            {
                providerIsPresent = true;
                cout<<"\nI ENTERED HERE!!\n";
            }
        }
        if(providerIsPresent) break;
        else cout<<"Provider with number "<<providerChoice<<" not found, please choose again.\n";
    }
    while(true)
    {
        cout<<"Optics being offered from provider "<<providers[providerChoice-1].getName()<<":\n";
        for (int i = 0; i < providers[providerChoice-1].getOptics().size(); i++)
        {
            cout << "Optics #"<< i+1 <<":\n" \
            "\t\tType: "<<optics[i].getType()<<"\n"<< \
            "\t\tThickness: "<<optics[i].getThickness()<<"\n"<< \
            "\t\tDioptre: "<<optics[i].getDioptre()<<"\n"<< \
            "\t\tName: "<<optics[i].getName()<<"\n"<< \
            "\t\tPrice: "<<optics[i].getPrice()<<"\n";
            cout << endl;
        }
        cout<<"Your order's price up to now: "<<totalPrice<<"\nEnter the number of the optics you want to order(or enter 0 to finish order): ";
        cin>>opticsChoice;
        for (int i = 0; i < providers[providerChoice-1].getOptics().size(); i++)
        {
            if(providers[providerChoice-1].getOptics()[i].getName()==providers[providerChoice-1].getOptics()[opticsChoice-1].getName())
            {
                opticsIsPresent = true;
                totalPrice += providers[providerChoice-1].getOptics()[i].getPrice();
                cout<<"Your order's price up to now: "<<totalPrice<<"\n";
                break;
            }
        }
        if(opticsChoice==0)
        {
            cout<<"Total price for order: "<<totalPrice<<"\n";
            break;
        }
        else if(!opticsIsPresent) cout<<"Optics with number "<<opticsChoice<<" not found, please enter choice again.\n";
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
                placeOrder();
                break;
            case 5:
                return;
            default:
                cout << "Invalid input detected. Please enter a number between 1 and 5 inclusive.\n";
        }
    }

}