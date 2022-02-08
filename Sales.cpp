/****************************************
-This program demonstrates a Sale and Salesperson class.
-It will use both classes to display the result.
//@author Pranij Joshi
//Date of creation: 9th July, 2021
*****************************************
*/


#include <iostream>

using namespace std;

//declaring a Salesperson class.
class Salesperson;


//declaring a Sale class
class Sale
{
    private:
        //declaring private members.
        int day;
        double amount;
        int id;

    public:
        //declaring member function prototypes.
        Sale(int, double, int);
        friend void display(Sale, Salesperson);
};


//initializing Salesperson class.
class Salesperson
{
    private:
        //declaring private members.
        int id;
        string lastName;

    public:
        //declaring member function prototypes.
        Salesperson(int, string);
        friend void display(Sale, Salesperson);
};


//***********************************************
//Parameterized constructor for Sale class.
//***********************************************
Sale::Sale(int d, double a, int i)
{
    //checks the date if it is between 1 and 31.
    //otherwise sets its value to 1.
    if(d < 1 || d > 31)
        day = 1;
    else
        day = d;

    //if amount is less than 0 it sets it to 0.
    amount = a>0 ? a : 0;

    id = i;
}


//***********************************************
//Parameterized constructor for Salesperson class.
//***********************************************
Salesperson::Salesperson(int i, string l)
{
    id = i;
    lastName = l;
}


//***********************************************
//friend function to access the data members of both
//Sale class and Salesperson class.
//It will display the data stored in the classes.
//***********************************************
void display(Sale s, Salesperson sp)
{
    cout << "Day of sale: " << s.day << endl;
    cout << "Sale amount: " << s.amount << endl;
    cout << "Salesperson last name: " << sp.lastName << endl;
    cout << "Salesperson ID: " << sp.id << endl;
}

int main()
{
    //creating an object of Sale class with parameters.
    Sale s(21, 59.99, 6982);

    //creating an object of Salesperson class with parameters.
    Salesperson sp(6982, "Joshi");

    //displays the values.
    display(s, sp);

    return 0;
}
