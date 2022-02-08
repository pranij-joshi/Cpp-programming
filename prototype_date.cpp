/****************************************
This program demonstrates a Date class
//@author Pranij Joshi
//Date of creation: 27th June, 2021
*****************************************
*/

#include <iostream>

using namespace std;


class Date
{
    private:
        int day;
        int month;
        int year;

        static string month_names[12];

    public:
        Date(int, int, int);
        void setDate();
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
        int operator -(Date);
        friend ostream& operator <<(ostream &, Date &);
};



string Date::month_names[12] = {"January", "February", "March",
                                "April", "May", "June",
                                "July", "August", "September",
                                "October", "November", "December"};



Date::Date(int day = 1, int month = 1, int year = 2020)
{

    if(year < 1)
    {
        cout << "Invalid value for year.";
        cout << "Setting the year to default value 2020." << endl;
        year = 2020;
    }


    if(month < 1 || month > 12)
    {
        cout << month << " is an invalid data for months." << endl;
        cout << "Error month can only be between 1-12!" << endl;
        cout << "Setting the month to default value 1." << endl;
        month = 1;
    }



    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {

        if(day < 1 || day > 31)
        {
            cout << day << " is an invalid data for day." << endl;
            cout << year << " " << month_names[month - 1] << " can only have 1-31 days." << endl;
            cout << "Setting the day to default value 1." << endl;
            day = 1;
        }
    }



    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {

        if(day < 1 || day > 30)
        {
            cout << day << " is an invalid data for day." << endl;
            cout << year << " " << month_names[month - 1] << " can only have 1-30 days." << endl;
            cout << "Setting the day to default value 1." << endl;
            day = 1;
        }
    }


    else
    {

        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {

            if(day < 1 || day > 29)
            {
                cout << day << " is an invalid data for day." << endl;
                cout << year << " " << month_names[month - 1] << " can only have 1-29 days." << endl;
                cout << "Setting the day to default value 1." << endl;
                day = 1;
            }
        }



        else
        {

            if(day < 1 || day > 28)
            {
                cout << day << " is an invalid data for day." << endl;
                cout << year << " " << month_names[month - 1] << " can only have 1-28 days." << endl;
                cout << "Setting the day to default value 1." << endl;
                day = 1;
            }
        }

    }


    Date::day = day;
    Date::month = month;
    Date::year = year;
}


void Date::setDate()
{
    cout << "Enter the year: ";
    cin >> year;

    while(year < 1)
    {
        cout << endl;
        cout << "Error!! Year cannot be less than 1." << endl;
        cout << "Enter a valid year: ";
        cin >> year;
    }

    cout << "Enter the month: ";
    cin >> month;

    while(month > 12 || month < 1)
    {
        cout << endl;
        cout << month << " is an invalid data for months." << endl;
        cout << "Error month can only be between 1-12!" << endl;
        cout << "Enter the month: ";
        cin >> month;
    }

    cout << "Enter the day: ";
    cin >> day;


    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {

        while(day > 31 || day < 1)
        {
            cout << endl;
            cout << day << " is an invalid data for day." << endl;
            cout << month_names[month - 1] << " "  << year <<  " can only have 1-31 days." << endl;
            cout << "Enter the day: ";
            cin >> day;
        }
    }



    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {

        while(day > 30 || day < 1)
        {
            cout << endl;
            cout << day << " is an invalid data for day." << endl;
            cout << month_names[month - 1] << " " << year << " can only have 1-30 days." << endl;
            cout << "Enter the day: ";
            cin >> day;
        }
    }


    else
    {

        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {

            while(day > 29 || day < 1)
            {
                cout << endl;
                cout << day << " is an invalid data for day." << endl;
                cout << month_names[month - 1] << " " << year << " can only have 1-29 days." << endl;
                cout << "Enter the day: ";
                cin >> day;
            }
        }



        else
        {

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



void Date::setDay(int d)
{


    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {

        if(d < 1 || d > 31)
        {
            cout << d << " is an invalid data for day." << endl;
            cout << year << " " << month_names[month - 1] << " can only have 1-31 days." << endl;
            cout << "Setting the day to default value 1." << endl;
            d = 1;
        }
    }


    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {

        if(d < 1 || d > 30)
        {
            cout << d << " is an invalid data for day." << endl;
            cout << year << " " << month_names[month - 1] << " can only have 1-30 days." << endl;
            cout << "Setting the day to default value 1." << endl;
            d = 1;
        }
    }


    else
    {
        //condition if the year is a leap year.
        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {

            if(d < 1 || d > 29)
            {
                cout << d << " is an invalid data for day." << endl;
                cout << year << " " << month_names[month - 1] << " can only have 1-29 days." << endl;
                cout << "Setting the day to default value 1." << endl;
                d = 1;
            }
        }


        else
        {

            if(d < 1 || d > 28)
            {
                cout << d << " is an invalid data for day." << endl;
                cout << year << " " << month_names[month - 1] << " can only have 1-28 days." << endl;
                cout << "Setting the day to default value 1." << endl;
                d = 1;
            }
        }
    }


    day = d;
}



void Date::setMonth(int m)
{

    if(m < 1 || m > 12)
    {
        cout << m << " is an invalid data for month." << endl;
        cout << "Error! Month can only be between 1-12!" << endl;
        cout << "Setting the month to default value 1." << endl;
        m = 1;
    }


    month = m;
}



void Date::setYear(int y)
{
    year = y;
}




int Date::getDay()
{
    return day;
}


int Date::getMonth()
{
    return month;
}



int Date::getYear()
{
    return year;
}


void Date::display_format1()
{
    int temp = year%100;
    cout << "The date in format 1 is: ";
    printf("%02d/%02d/%02d", day, month, temp);
    cout << endl;
}


void Date::display_format2()
{
    cout << "The date in format 2 is: ";
    cout << month_names[month-1] << " " << day << ", " << year << endl;
}



void Date::display_format3()
{
    cout << "The date in format 3 is: ";
    cout << day << " " << month_names[month-1] << " " << year << endl;
}



void Date::operator++()
{

    int d;

    ++day;
    d = day;


    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {

        if(d > 31)
        {
            day = d % 31;

            month = month + (d/31);


            if(month > 12)
            {
                month = month % 12;
                year = year + 1;
            }
        }
    }


    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {

        if(d > 30)
        {
            day = d % 30;

            month = month + (d/30);

        }
    }


    else
    {

        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {

            if(d > 29)
            {
                day = d % 29;

                month = month + (d/29);
            }
        }


        else
        {

            if(d > 28)
            {
                day = d % 28;

                month = month + (d/28);
            }
        }
    }
}



void Date::operator++(int)
{

    int d;


    day++;
    d = day;


    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {

        if(d > 31)
        {
            day = d % 31;

            month = month + (d/31);

            if(month > 12)
            {
                month = month % 12;
                year = year + 1;
            }
        }
    }


    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {

        if(d > 30)
        {
            day = d % 30;

            month = month + (d/30);

        }
    }


    else
    {

        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {

            if(d > 29)
            {
                day = d % 29;

                month = month + (d/29);
            }
        }


        else
        {

            if(d > 28)
            {
                day = d % 28;

                month = month + (d/28);
            }
        }
    }


}



void Date::operator--()
{

    --day;


    if(day == 0)
    {

        if(month == 5 || month == 7 || month == 10 || month == 12)
        {
            day = 30;
            month = month -1;
        }


        else if(month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
        {
            day = 31;
            month = month -1;


            if(month == 0)
            {
                month = 12;
                year = year - 1;
            }
        }


        else
        {

            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
                day = 29;
                month = month -1;
            }


            else
            {
                day = 28;
                month = month - 1;
            }
        }
    }
}


void Date::operator--(int)
{

    --day;


    if(day == 0)
    {

        if(month == 5 || month == 7 || month == 10 || month == 12)
        {
            day = 30;
            month = month -1;
        }


        else if(month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
        {
            day = 31;
            month = month -1;


            if(month == 0)
            {
                month = 12;
                year = year - 1;
            }
        }


        else
        {

            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
                day = 29;
                month = month -1;
            }


            else
            {
                day = 28;
                month = month - 1;
            }
        }
    }
}


int Date::operator -(Date d)
{
    int n = 0;


            if(year < d.year)
            {
                cout << "Error!!" << endl;
                cout << day << "/" << month << "/" << year << " is smaller than ";
                cout << d.day << "/" << d.month << "/" << d.year << endl;
            }


            else if(year == d.year)
            {

                if(month < d.month)
                {
                    cout << "Error!!" << endl;
                    cout << day << "/" << month << "/" << year << " is smaller than ";
                    cout << d.day << "/" << d.month << "/" << d.year << endl;
                }


                else if(month == d.month)
                {

                    if(day < d.day)
                    {
                        cout << "Error!!" << endl;
                        cout << day << "/" << month << "/" << year << " is smaller than ";
                        cout << d.day << "/" << d.month << "/" << d.year << endl;
                    }


                    else
                    {
                        n = n + (day - d.day);
                    }
                }


                else
                {

                    for(int i = d.month; i < month; i++)
                    {

                        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                        {
                            n = n + 31;
                        }


                        else if(i == 4 || i == 6 || i == 9 || i == 11)
                        {
                            n = n + 30;
                        }


                        else
                        {

                            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                            {
                                n = n + 29;
                            }


                            else
                            {
                                n = n + 28;
                            }
                        }
                    }


                    n = n + (day - d.day);
                }
            }


            else
            {

                for(int i = d.year; i < year; i++)
                {

                    if(((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
                    {
                        n = n + 366;
                    }


                    else
                    {
                        n = n + 365;
                    }
                }

                if(month < d.month)
                {
                    for(int i = month; i < d.month; i++)
                    {

                        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                        {
                            n = n - 31;
                        }


                        else if(i == 4 || i == 6 || i == 9 || i == 11)
                        {
                            n = n - 30;
                        }


                        else
                        {

                            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                            {
                                n = n - 29;
                            }


                            else
                            {
                                n = n - 28;
                            }
                        }
                    }
                }

                else
                {
                    for(int i = month; i < d.month; i++)
                    {

                        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                        {
                            n = n - 31;
                        }


                        else if(i == 4 || i == 6 || i == 9 || i == 11)
                        {
                            n = n - 30;
                        }


                        else
                        {

                            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                            {
                                n = n - 29;
                            }


                            else
                            {
                                n = n - 28;
                            }
                        }
                    }
                }

                n = n + (day - d.day);
            }


            return n;
}



int main()
{

    Date d1;
    //d1.setDate();
    d1.display_format1();
    cout << endl;
    d1.setDay(45);
    d1.display_format2();
    cout << endl;

    Date d2(30, 6, 2007);
    d2.display_format2();
    cout << endl;
    d2++;
    cout << "Date after increment:" << endl;
    d2.display_format2();
    cout << endl;

    Date d3(31, 12, 2008);
    d3.display_format2();
    cout << endl;
    ++d3;
    cout << "Date after increment: " << endl;
    d3.display_format2();
    cout << endl;

    Date d4(1,1,2021);
    d4.display_format2();
    cout << endl;
    --d4;
    cout << "Date after decrement:" << endl;
    d4.display_format2();

    Date d5(25, 2, 2000);
    d5.display_format2();
    --d5;
    cout << "Date after decrement:" << endl;
    d5.display_format2();

    Date d6(1, 3, 2007);
    d6.display_format2();
    --d6;
    cout << "Date after decrement:" << endl;
    d6.display_format2();
    cout << endl;

    Date d7(1, 1, 2008);
    d7.display_format2();
    d7--;
    cout << "Date after decrement: " << endl;
    d7.display_format2();

    Date d8(23, 4, 2008);
    Date d9(21, 8, 2006);

    cout <<  d8 - d9 << " days." << endl;

    Date d10(25,9, 2006);
    Date d11(2, 4, 2006);
    Date d12(3, 2, 2006);
    Date d13(2, 2, 2008);
    Date d14(5, 9, 2001);

    cout << d8 - d10 << endl;
    cout << d8 - d11 << endl;
    cout << d8 - d12 << endl;
    cout << d8 - d13 << endl;
    cout << d8 - d14 << endl;



    return 0;
}

