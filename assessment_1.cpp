/****************************************
This program demonstrates a Date class
//@author Pranij Joshi
//Date of creation: 27th June, 2021
*****************************************
*/

#include <iostream>

using namespace std;

//Date class declaration
class Date
{
    private:
        int day;
        int month;
        int year;

        static string month_names[12];

    public:
        Date(int, int, int);
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        int getDay();
        int getMonth();
        int getYear();
        void display_format1();
        void display_format2();
        void display_format3();
        void operator ++();
        void operator ++(int);
        void operator --();
        void operator --(int);
};


//************************************************************
//giving value to the static variable month_names*
//************************************************************
string Date::month_names[12] = {"January", "February", "March",
                                "April", "May", "June",
                                "July", "August", "September",
                                "October", "November", "December"};


//************************************************************
//Constructor to set the value to the variables in Date class. *
//************************************************************
Date::Date(int day = 1, int month = 1, int year = 2010)
{
    if(month < 1 || month > 12)
    {
        cout << "Error month can only be between 1-12!" << endl;
        cout << "Program Ending!";
        exit(1);
    }

    else
    {
        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if(day < 1 || day > 31)
                {
                    cout << year << " " << month_names[month - 1] << " can only have 1-31 days." << endl;
                    cout << "Program ending" << endl;
                    exit(1);
                }
            }

            else if(month == 4 || month == 6 || month == 9 || month == 11)
            {
                if(day < 1 || day > 30)
                {
                    cout << year << " " << month_names[month - 1] << " can only have 1-30 days." << endl;
                    cout << "Program ending" << endl;
                    exit(1);
                }
            }

            else
            {
                if(day < 1 || day > 29)
                {
                    cout << year << " " << month_names[month - 1] << " can only have 1-29 days." << endl;
                    cout << "Program ending" << endl;
                    exit(1);
                }
            }
        }

        else
        {
            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if(day < 1 || day > 31)
                {
                    cout << year << " " << month_names[month - 1] << " can only have 1-31 days." << endl;
                    cout << "Program ending" << endl;
                    exit(1);
                }
            }

            else if(month == 4 || month == 6 || month == 9 || month == 11)
            {
                if(day < 1 || day > 30)
                {
                    cout << year << " " << month_names[month - 1] << " can only have 1-30 days." << endl;
                    cout << "Program ending" << endl;
                    exit(1);
                }
            }

            else
            {
                if(day < 1 || day > 28)
                {
                    cout << year << " " << month_names[month - 1] << " can only have 1-28 days." << endl;
                    cout << "Program ending" << endl;
                    exit(1);
                }
            }
        }
    }


    Date::day = day;
    Date::month = month;
    Date::year = year;
}


//************************************************************
//setDay assigns a value to the day member.
//It also ends the program if invalid input is supplied. *
//************************************************************
void Date::setDay(int d)
{
    if(d < 1 || d > 31)
    {
        cout << "Error! Date can only be between 1-31!" << endl;
        cout << "Program Ending!!" << endl;
        exit(1);
    }

    else
    {
        day = d;
    }
}


//************************************************************
//setMonth assigns a value to the month member.
//It also ends the program if invalid input is supplied. *
//************************************************************
void Date::setMonth(int m)
{
    if(m < 1 || m > 12)
    {
        cout << "Error! Month can only be between 1-12!" << endl;
        cout << "Program Ending!!" << endl;
        exit(1);
    }

    else
    {
        month = m;
    }
}


//************************************************************
//setYear assigns a value to the year member. *
//************************************************************
void Date::setYear(int y)
{
    year = y;
}


//************************************************************
//getDay returns the value in the day member.*
//************************************************************

int Date::getDay()
{
    return day;
}


//************************************************************
//getMonth returns the value in the month member.*
//************************************************************
int Date::getMonth()
{
    return month;
}


//************************************************************
//getYear returns the value in the year member.*
//************************************************************
int Date::getYear()
{
    return year;
}


//************************************************************
//display_format1 displays the date in MM/DD/YY format.*
//************************************************************
void Date::display_format1()
{
    int temp = year%100;
    cout << "The date in format 1 is:" << endl;
    cout << month << "/" << day << "/" << temp << endl;
}


//************************************************************
//display_format2 displays the date in Month DD, YYYY format.*
//************************************************************
void Date::display_format2()
{
    cout << "The date in format 2 is:" << endl;
    cout << month_names[month-1] << " " << day << ", " << year << endl;
}


//************************************************************
//display_format3 displays the date in DD Month YYYY format.*
//************************************************************
void Date::display_format3()
{
    cout << "The date in format 3 is:" << endl;
    cout << day << " " << month_names[month-1] << " " << year << endl;
}


//************************************************************
//++ prefix increment operator over loader to increment the day
//member of Date class.*
//
//If date is set to the last day of the month and incremented,
//it changes to the first day of the following month.
//
//If date is set to December 31 and incremented, it changes
//January 1 of the following year.
//************************************************************
void Date::operator++()
{
    //condition if the year is a leap year.
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        //condition for the month with 31 days.
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            int d, m;

            d = day;
            ++d;

            day = d % 31;

            m = month + (d/31);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the month with 30 days.
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            int d, m;
            d = day;
            ++d;

            day = d % 30;

            m = month + (d/30);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the month with 29 days as it is a leap year.
        else
        {
            int d, m;
            d = day;
            ++d;

            day = d % 29;

            m = month + (d/29);
            month = m % 12;

            year = year + (m/12);
        }
    }

    //condition if the year is not a leap year.
    else
    {
        //condition for months with 31 days.
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            int d, m;
            d = day;
            ++d;

            day = d % 31;

            m = month + (d/31);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the months with 30 days.
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            int d, m;
            d = day;
            ++d;

            day = d % 30;

            m = month + (d/30);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the months with 28 days as it is not a leap year.
        else
        {
            int d, m;
            d = day;
            ++d;

            day = d % 28;

            m = month + (d/28);
            month = m % 12;

            year = year + (m/12);
        }
    }
}


//************************************************************
//++ postfix increment operator over loader to increment the day
//member of Date class.*
//
//If date is set to the last day of the month and incremented,
//it changes to the first day of the following month.
//
//If date is set to December 31 and incremented, it changes
//January 1 of the following year.
//************************************************************
void Date::operator++(int)
{
    //condition if the year is a leap year.
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        //condition for the month with 31 days.
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            int d, m;

            d = day;
            ++d;

            day = d % 31;

            m = month + (d/31);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the month with 30 days.
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            int d, m;
            d = day;
            ++d;

            day = d % 30;

            m = month + (d/30);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the month with 29 days as it is a leap year.
        else
        {
            int d, m;
            d = day;
            ++d;

            day = d % 29;

            m = month + (d/29);
            month = m % 12;

            year = year + (m/12);
        }
    }

    //condition if the year is not a leap year.
    else
    {
        //condition for months with 31 days.
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            int d, m;
            d = day;
            ++d;

            day = d % 31;

            m = month + (d/31);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the months with 30 days.
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            int d, m;
            d = day;
            ++d;

            day = d % 30;

            m = month + (d/30);
            month = m % 12;

            year = year + (m/12);
        }

        //condition for the months with 28 days as it is not a leap year.
        else
        {
            int d, m;
            d = day;
            ++d;

            day = d % 28;

            m = month + (d/28);
            month = m % 12;

            year = year + (m/12);
        }
    }
}



//*************************************************
//Function main
//*************************************************
int main()
{
    Date d2(30, 6, 2007);
    ++d2;
    d2.display_format2();

    Date d3(29, 02, 2009);
    d3.display_format2();

    return 0;
}
