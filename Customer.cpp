/****************************************
This program demonstrates a Customer class
and uses Name class and CreditData class
to store and display data.
//Date of creation: 2nd July, 2021
*****************************************
*/

#include <iostream>
#include <string>

using namespace std;

//**********************************************
//Name class declaration.
//**********************************************
class Name
{
    private:
        //private data members for Name class.
        string first;
        string middle;
        string last;
    public:
        //public member function prototypes for Name class.
        Name(string, string, string);
        void displayFullName();
};

//**********************************************
//Constructor for the Name class.
//**********************************************
Name::Name(string first, string middle, string last)
{
    this->first = first;
    this->middle = middle;
    this->last = last;
}

//**********************************************
//function to display the name for Name class.
//**********************************************
void Name::displayFullName()
{
    cout << first << " " << middle << " " << last << endl;
}

//**********************************************
//CreditData class declaration.
//**********************************************
class CreditData
{
    private:
        //private data members for CreditData class.
        double currentBalance;
        double maxBalance;
    public:
        //public member function prototype for CreditData class
        CreditData(double, double = 0);
        void displayCreditData();
};

//**********************************************
//Constructor for CreditData class.
//**********************************************
CreditData::CreditData(double currBal, double maxBal)
{
    currentBalance = currBal;
    if(maxBal < currBal)
        maxBalance = currBal;
    else
        maxBalance = maxBal;
}

//**********************************************
//function to display the data for CreditData class.
//**********************************************
void CreditData::displayCreditData()
{
    double creditLeft = maxBalance - currentBalance;
    cout << "Current balance: $" << currentBalance << "\nMaximum balance: $"
    << maxBalance << "\nCredit left: $" << creditLeft << endl;
}

//**********************************************
//Customer class declaration.
//Customer class will use the data from CreditData class and Name class.
//**********************************************
class Customer
{
    private:
        Name name; //creating an instance for Name class.
        CreditData credit; //creating an instance for CreditData class.
        string phoneNumber; //String private data member
    public:
        //member function prototype.
        Customer(string, string, string, double, double, string);
        void showCustomer();
};

//**********************************************
//constructor for Customer class
//the constructor also calls the Name and CreditData class constructor.
//**********************************************
Customer::Customer(string firstName, string middleName,
        string lastName, double bal, double max, string phone):
        name(firstName, middleName, lastName), credit(bal, max)
{
    phoneNumber = phone;
}

//**********************************************
//function to display the data.
//**********************************************
void Customer::showCustomer()
{
    cout << "Customer data:" << endl;
    name.displayFullName(); //calls the display function from Name class
    cout << phoneNumber << endl;
    credit.displayCreditData(); //calls the display function from CreditData class.
}

//**********************************************
//main function
//**********************************************
int main()
{
    int x; //integer variable x.
    const int TIMES = 2; //constant integer TIMES.
    string first, middle, last, phone; //String variables.
    double bal, lim; //double variables.
    //for loop to get the customer data.
    for(x = 0; x < TIMES; ++x)
    {
        cout << endl <<
        "Please enter the first name for customer #" <<
        (x + 1) << " ";
        cin >> first;
        cout << "Please enter middle name ";
        cin >> middle;
        cout << "Please enter last name ";
        cin >> last;
        cout << "Enter current balance ";
        cin >> bal;
        cout << "Enter credit limit ";
        cin >> lim;
        cout << "Enter phone number ";
        cin >> phone;
        //creating an instance for Customer class.
        Customer cust(first, middle, last, bal, lim, phone);
        cust.showCustomer(); //displays the data.
    }
    return 0;
}
