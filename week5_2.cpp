/****************************************
This program demonstrates a Date class
//@author Pranij Joshi
//Date of creation: 26th June, 2021
*****************************************
*/

#include <iostream>

using namespace std;

//Date class declaration.
class Date
{
    private:
        int day; //declaring private int variable day
        int month; //declaring private int variable month
        int year; //declaring private int variable year

    public:
        //Default constructor that accepts parameterized values as well.
        Date(int day = 1, int month = 1, int year = 2000)
        {
            Date::day = day;
            Date::month = month;
            Date::year = year;
        }

        //Destructor for Date class
        void display();

        ~Date()
        {

        }
};

//*************************************************
//Function to display the data
//*************************************************
void Date::display()
{
    cout << day << "/" << month << "/" << year << endl;
}

//*************************************************
//Function main
//*************************************************
int main()
{
    //creating an instance of Class date that calls the default constructor.
    Date d1;
    cout << "Display date with default constructor:" << endl;
    //Displaying the data.
    d1.display();

    cout << endl;

    //creating an instance of Class date that calls the parameterized constructor.
    Date d2(5, 6, 2009);
    cout << "Display date with parameterized constructor:" << endl;
    //Displaying the data.
    d2.display();
}
