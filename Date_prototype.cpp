/****************************************
-This program demonstrates a Date class.
-It will increment and decrement the date
 using postfix and prefix operators.
-It will also give you the days between two
 dates.
//@author Pranij Joshi
//Date of creation: 4th July, 2021
*****************************************
*/

#include <iostream>
#include <string>

using namespace std;

//Date class declaration
class Date
{
    private:
        int day;
        int month;
        int year;

        static const string month_names[12];

    public:
        //member function prototypes.
        Date();
        void setDate();
        void display_format1();
        void display_format2();
        void display_format3();
        void increment();
        void decrement();
        void operator ++();
        void operator ++(int);
        void operator --();
        void operator --(int);
        int operator -(Date &);
};


//************************************************************
//giving value to the static variable month_names*
//************************************************************
string const Date::month_names[12] = {"January", "February", "March",
                                "April", "May", "June",
                                "July", "August", "September",
                                "October", "November", "December"};


//Default constructor for Date class.
Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}



//************************************************************
//setDate function asks user for the input for day, month, and year values. *
//It will only accept correct values.
//************************************************************
void Date::setDate()
{
    //asks the user for the year
    cout << "Enter the year: ";
    cin >> year;

    //if the year is less than 1 it asks the user to input a valid year.
    while(year < 1)
    {
        cout << endl;
        cout << "Error!! Year cannot be less than 1." << endl;
        cout << "Enter a valid year: ";
        cin >> year;
    }

    //asks the user for the month.
    cout << "Enter the month: ";
    cin >> month;

    //if the month is invalid the while loop asks the user to enter a valid month.
    while(month > 12 || month < 1)
    {
        cout << endl;
        cout << month << " is an invalid data for months." << endl;
        cout << "Error month can only be between 1-12!" << endl;
        cout << "Enter the month: ";
        cin >> month;
    }

    //asks the user the day.
    cout << "Enter the day: ";
    cin >> day;

    //asks the user for the correct input.

    //condition for the months with 31 days.
    //i.e. January, March, May, July, August, October and December.
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        //while loop runs if and until the correct value is provided.
        while(day > 31 || day < 1)
        {
            cout << endl;
            cout << day << " is an invalid data for day." << endl;
            cout << month_names[month - 1] << " "  << year <<  " can only have 1-31 days." << endl;
            cout << "Enter the day: ";
            cin >> day;
        }
    }


    //condition for the months with 30 days.
    //i.e. April, June, September and November.
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        //while loop runs if and until the correct value is provided.
        while(day > 30 || day < 1)
        {
            cout << endl;
            cout << day << " is an invalid data for day." << endl;
            cout << month_names[month - 1] << " " << year << " can only have 1-30 days." << endl;
            cout << "Enter the day: ";
            cin >> day;
        }
    }


    //condition for the month with 28/29 days.
    //i.e. February.
    else
    {
        //condition if the year is a leap year.
        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            //while loop runs if and until the correct value is provided.
            while(day > 29 || day < 1)
            {
                cout << endl;
                cout << day << " is an invalid data for day." << endl;
                cout << month_names[month - 1] << " " << year << " can only have 1-29 days." << endl;
                cout << "Enter the day: ";
                cin >> day;
            }
        }


        //condition if the year is not a leap year.
        else
        {
            //while loop runs if and until the correct value is provided.
            while(day > 28 || day < 1)
            {
                cout << endl;
                cout << day << " is an invalid data for day." << endl;
                cout << month_names[month - 1] << " " << year << " can only have 1-28 days." << endl;
                cout << "Enter the day: ";
                cin >> day;
            }
        }

    }
}



//************************************************************
//display_format1 displays the date in MM/DD/YY format.*
//************************************************************
void Date::display_format1()
{
    int temp = year%100;
    cout << "The date in format 1 is: ";
    printf("%02d/%02d/%02d", day, month, temp);
    cout << endl;
}


//************************************************************
//display_format2 displays the date in Month DD, YYYY format.*
//************************************************************
void Date::display_format2()
{
    cout << "The date in format 2 is: ";
    cout << month_names[month-1] << " " << day << ", " << year << endl;
}


//************************************************************
//display_format3 displays the date in DD Month YYYY format.*
//************************************************************
void Date::display_format3()
{
    cout << "The date in format 3 is: ";
    cout << day << " " << month_names[month-1] << " " << year << endl;
}


//************************************************************
//Increment member function increments the day.
//
//If date is set to the last day of the month and incremented,
//it changes to the first day of the following month.
//
//If date is set to December 31 and incremented, it changes
//January 1 of the following year.
//************************************************************
void Date::increment()
{
    int d;

    //increments the day by 1.
    day++;
    d = day;

    //condition for the month with 31 days.
    //i.e. for January, March, May, July, August, October, and December.
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        //condition if the day is greater than 31.
        if(d > 31)
        {
            day = d % 31;

            month = month + (d/31);

            //condition if the month is greater than 12.
            if(month > 12)
            {
                month = month % 12;
                year = year + 1;
            }
        }
    }

    //condition for the month with 30 days.
    //i.e. for April, June, September, and November.
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        //condition if the day is greater than 30.
        if(d > 30)
        {
            day = d % 30;

            month = month + (d/30);

        }
    }

    //condition for the month with 28/29.
    //i.e. for February.
    else
    {
        //condition for leap year.
        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            //condition if the day is greater than 29.
            if(d > 29)
            {
                day = d % 29;

                month = month + (d/29);
            }
        }

        //condition if it is not a leap year.
        else
        {
            //condition if the day is greater than 28.
            if(d > 28)
            {
                day = d % 28;

                month = month + (d/28);
            }
        }
    }
}


//************************************************************
//decrement member function decrements the day member.*
//
//If date is set to the first day of the month and decremented,
//it changes to the last day of the following previous.
//
//If date is set to January 1 and decremented, it changes
//December 31 of the previous year.
//************************************************************
void Date::decrement()
{
    //decrements the day by 1.
    --day;

    //condition if the day is decremented to 0.
    if(day == 0)
    {
        //condition if the month before has 30 days.
        //i.e. April, June, September and November.
        if(month == 5 || month == 7 || month == 10 || month == 12)
        {
            day = 30;
            month = month -1;
        }

        //condition if the month before has 31 days.
        //i.e. for January, March, May, July, August, October and December.
        else if(month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
        {
            day = 31;
            month = month -1;

            //condition if the month exceeds the value of 12.
            if(month == 0)
            {
                month = 12;
                year = year - 1;
            }
        }

        //condition if the month before has 28/29 days.
        //i.e. February.
        else
        {
            //condition if it is a leap year.
            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
                day = 29;
                month = month -1;
            }

            //condition if it is not a leap year.
            else
            {
                day = 28;
                month = month - 1;
            }
        }
    }
}

//************************************************************
//++ prefix increment operator over loader to increment the day
//member of Date class.*
//************************************************************
void Date::operator++()
{
    //increment member function is called.
    increment();
}


//************************************************************
//++ postfix increment operator over loader to increment the day
//member of Date class.*
//************************************************************
void Date::operator++(int)
{
    //calls the increment function.
    increment();
}


//************************************************************
//-- prefix decrement operator over loader to decrement the day
//member of Date class.*
//************************************************************
void Date::operator--()
{
    //calls the decrement function.
    decrement();
}


//************************************************************
//-- postfix decrement operator over loader to decrement the day
//member of Date class.*
//************************************************************
void Date::operator--(int)
{
    //calls the decrement function.
    decrement();
}


//************************************************************
//- subtraction operator over loader subtracts two dates and
//returns the days between them.
//************************************************************
int Date::operator -(Date &d)
{
    int n = 0; //int variable to store the number of days.

    //condition if the year to be subtracted is greater.
    if(year < d.year)
    {
        int j = year + 1;
        //for loop adds the days in the year.
        for(int i = j; i < d.year; i++)
        {
            //condition if it is a leap year.
            if(((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
            {
                n = n + 366;
            }

            //condition if it is not a leap year.
            else
            {
                n = n + 365;
            }
        }

        //for loop adds the days in the months for the smaller date.
        for(int i = month; i <=12; i++)
        {
            //condition for months with 31 days.
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                n = n + 31;
            }

            //condition for months with 30 days.
            else if(i == 4 || i == 6 || i == 9 || i == 11)
            {
                n = n + 30;
            }

            //condition for months with 28/29 days.
            else
            {
                //condition for a leap year.
                if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                {
                    n = n + 29;
                }

                //condition if it is not a leap year.
                else
                {
                    n = n + 28;
                }
            }
        }


        //for loop adds the days in the months for the greater date.
        for(int i = 1; i < d.month; i++)
        {
            //condition for months with 31 days.
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                n = n + 31;
            }

            //condition for months with 30 days.
            else if(i == 4 || i == 6 || i == 9 || i == 11)
            {
                n = n + 30;
            }

            //condition for months with 28/29 days.
            else
            {
                //condition for a leap year.
                if(((d.year % 4 == 0) && (d.year % 100 != 0)) || (d.year % 400 == 0))
                {
                    n = n + 29;
                }

                //condition if it is not a leap year.
                else
                {
                    n = n + 28;
                }
            }
        }

        //adds the days,
        n = n + (d.day - day);
    }

    //condition if the years are equal.
    else if(year == d.year)
    {
        //condition if the years are equal but the month to be subtracted is greater.
        if(month < d.month)
        {
            //for loop adds the days in the months.
            for(int i = month; i < d.month; i++)
            {
                //adds the months with 31 days.
                if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    n = n + 31;
                }

                //adds the months with 30 days.
                else if(i == 4 || i == 6 || i == 9 || i == 11)
                {
                    n = n + 30;
                }

                //adds the months with 28/29 days.
                else
                {
                    //condition if it is a leap year.
                    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                    {
                        n = n + 29;
                    }

                    //condition if it is not a leap year.
                    else
                    {
                        n = n + 28;
                    }
                }
            }

            //adds the days.
            n = n + (d.day - day);
        }

        //condition if the years are equal and the months are equal.
        else if(month == d.month)
        {
            //condition if the years and months are equal but the day to be subtracted is greater.
            if(day < d.day)
            {
                n = n + (d.day - day);
            }

            //condition if the years and months are equal but the day to be subtracted is equal or smaller.
            else
            {
                n = n + (day - d.day);
            }
        }

        //condition if the years are equal but month to be subtracted is smaller.
        else
        {
            //for loop adds the days in the months.
            for(int i = d.month; i < month; i++)
            {
                //adds the months with 31 days.
                if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    n = n + 31;
                }

                //adds the months with 30 days.
                else if(i == 4 || i == 6 || i == 9 || i == 11)
                {
                    n = n + 30;
                }

                //adds the months with 28/29 days.
                else
                {
                    //condition if it is a leap year.
                    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                    {
                        n = n + 29;
                    }

                    //condition if it is not a leap year.
                    else
                    {
                        n = n + 28;
                    }
                }
            }

            //adds the days.
            n = n + (day - d.day);
        }
    }

    //*****************************************************
    //condition if the year to be subtracted is smaller.
    else
    {
        int j = d.year + 1;
        //for loop adds the days in the year.
        for(int i = j; i < year; i++)
        {
            //condition if it is a leap year.
            if(((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
            {
                n = n + 366;
            }

            //condition if it is not a leap year.
            else
            {
                n = n + 365;
            }
        }

        //condition if the year and the month to be subtracted is smaller.
        for(int i = d.month; i <=12; i++)
        {
                            //condition for months with 31 days.
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                n = n + 31;
            }

            //condition for months with 30 days.
            else if(i == 4 || i == 6 || i == 9 || i == 11)
            {
                n = n + 30;
            }

            //condition for months with 28/29 days.
            else
            {
                //condition for a leap year.
                if(((d.year % 4 == 0) && (d.year % 100 != 0)) || (d.year % 400 == 0))
                {
                    n = n + 29;
                }

                //condition if it is not a leap year.
                else
                {
                    n = n + 28;
                }
            }
        }


        //condition if the year and the month to be subtracted is smaller.
        for(int i = 1; i < month; i++)
        {
                            //condition for months with 31 days.
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                n = n + 31;
            }

            //condition for months with 30 days.
            else if(i == 4 || i == 6 || i == 9 || i == 11)
            {
                n = n + 30;
            }

            //condition for months with 28/29 days.
            else
            {
                //condition for a leap year.
                if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                {
                    n = n + 29;
                }

                //condition if it is not a leap year.
                else
                {
                    n = n + 28;
                }
            }
        }

        //adds the days,
        n = n + (day - d.day);
    }

    //returns the days.
    return n;
}



//*************************************************
//Function main
//*************************************************
int main()
{
    char again = 'y', new_date;
    int choice;

    //program description.
    cout << "-The program will ask the user for dates and display it in three different formats.\n";
    cout << "-It will also ask the user for dates to be incremented and decremented using both the\n";
    cout << " prefix and postfix operator.\n";
    cout << "-It will also ask the user for two dates and give the days between the two dates.\n";
    cout << "*****************************************************************************************" << endl << endl;


    //creating instance for Date class.
    Date d1, d2;

    //asks the user for the date.
    cout << "\tEnter the date:\n";
    d1.setDate(); //calls the setDate function from Date class.
    cout << "*****************************************************************************************" << endl;

    //programs run again if the user enters y.
    while(tolower(again) == 'y')
    {
        //choices description for the switch case.
        cout << "Enter:\n\t'1' to display the date.";
        cout << "\n\t'2' to increment the date using the prefix increment operator.";
        cout << "\n\t'3' to increment the date using the postfix increment operator.";
        cout << "\n\t'4' to decrement the date using the prefix decrement operator.";
        cout << "\n\t'5' to decrement the date using the postfix decrement operator.";
        cout << "\n\t'6' to subtract the date with a second date and display the days between them.\n\n";

        //asks the user for their choice.
        cout << "Enter your choice: ";
        cin >> choice;

        //switch case.
        switch(choice)
        {
            case 1:
                d1.display_format1();
                d1.display_format2();
                d1.display_format3(); //displays the date.
                cout << "*****************************************************************************************" << endl;
                break;

            case 2:
                ++d1; //date increment with prefix ++ operator.
                d1.display_format1();
                d1.display_format2();
                d1.display_format3(); //displays the date.
                cout << "*****************************************************************************************" << endl;
                break;

            case 3:
                d1++; //date increment with postfix ++ operator.
                d1.display_format1();
                d1.display_format2();
                d1.display_format3(); //displays the date.
                cout << "*****************************************************************************************" << endl;
                break;

            case 4:
                --d1; //date decrement with prefix -- operator.
                d1.display_format1();
                d1.display_format2();
                d1.display_format3(); //displays the date.
                cout << "*****************************************************************************************" << endl;
                break;

            case 5:
                d1--; //date decrement with postfix -- operator.
                d1.display_format1();
                d1.display_format2();
                d1.display_format3(); //displays the date.
                cout << "*****************************************************************************************" << endl;
                break;

            case 6:
                cout << "Enter the second date: " << endl;
                d2.setDate(); // asks the user for a second date.
                cout << "The difference between the two dates is: ";
                cout << d1-d2 << endl; //displays the days in between the dates.
                cout << "*****************************************************************************************" << endl;
                break;

            default:
                cout << "Error Input!!"; //displays if incorrect input.
                cout << "*****************************************************************************************" << endl;
                break;
        }

        //asks the user to try again.
        cout << "Enter 'y' to try again: ";
        cin >> again;
        cout << "*****************************************************************************************" << endl;

        //if the user want to try again.
        if(again == 'y')
        {
            //asks the user if they want to try with a new date.
            cout << "Enter 'y' to enter a new date to try with: ";
            cin >> new_date;
            cout << "*****************************************************************************************" << endl;

            //if the user wants to try with a new date.
            if(tolower(new_date) == 'y')
            {
                cout << "Enter the new date:\n";
                d1.setDate(); //asks the user for a new date.
                cout << "*****************************************************************************************" << endl;
            }
        }
    }

    cout << endl << endl;
    cout << "*****************************************************************************************" << endl;
    cout << "********************************************END******************************************" << endl;
    cout << "*****************************************************************************************" << endl;

    return 0;
}


