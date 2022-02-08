/****************************************
-This program demonstrates a Sale and Salesperson class.
-It will use both classes to compare the id and
 display the result.
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
        Sale(int, int, int);
        int getID();
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
        int getID();
        friend void display(Sale, Salesperson);
};

//***********************************************
//Parameterized constructor for Sale class.
//***********************************************
Sale::Sale(int d, int a, int i)
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
//Accessor function for Sale class.
//returns the id
//***********************************************
int Sale::getID()
{
    return id;
}


//***********************************************
//Accessor function for Salesperson class.
//returns the id
//***********************************************
int Salesperson::getID()
{
    return id;
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


//***********************************************
//Function main
//***********************************************
int main()
{
    int d;
    double a;
    int i;

    //creating an array of objects of Salesperson class.
    Salesperson sp[5] = {Salesperson(31, "Jacqueline"),
                        Salesperson(32, "Blake"),
                        Salesperson(33, "Denice"),
                        Salesperson(34, "Aaron"),
                        Salesperson(35, "Timothy")};

    //declaring an sentinel
    char sentienl = 'y';

    while(sentienl == 'y')
    {
        //if error is 1 it will display error message.
        int error = 1;

        //asks the user if they want to enter a sale.
        cout << "Enter 'y' to enter a sale: ";
        cin >> sentienl;

        cout << "***************************************" << endl;
        //if the user does not input y then it breaks out of the loop.
        if(sentienl != 'y')
        {
            break;
        }

        //asks the user for input.
        cout << "Enter the day: ";
        cin >> d;

        cout << "Enter the sale amount: ";
        cin >> a;

        cout << "Enter the Salesperson ID: ";
        cin >> i;

        cout << "***************************************" << endl;

        //creating an object of Sale class that is parameterized.
        Sale s(d, a, i);

        //for loop to check the id
        for(int i = 0; i < 5; i++)
        {
            //matches the id form Sale class and Salesperson class.
            if(s.getID() == sp[i].getID())
            {
                //displays the data.
                display(s, sp[i]);

                //changes the value of error so no error message is displayed.
                error = 0;
            }
        }

        //To display error message.
        if(error == 1)
        {
            cout << "Error Salesperson Id could not be found!!" << endl;
        }

        cout << "***************************************" << endl;
    }



    return 0;
}

