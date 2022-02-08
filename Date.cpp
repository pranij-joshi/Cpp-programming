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
        //Default constructor
        Date()
        {
            day = 1;
            month = 1;
            year = 2000;
        }
        //Parameterized constructor.
        Date(int day, int month, int year)
        {
            Date::day = day;
            Date::month = month;
            Date::year = year;
        }

        void display();

        //Destructor for Date class
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
    cout << "Display date with arguments passed to the constructor:" << endl;
    //Displaying the data.
    d2.display();

    return 0;
}
