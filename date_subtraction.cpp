#include <iostream>

using namespace std;

class Date
{
    private:
        int day, month, year;
    public:
        Date(int day = 1, int month = 1, int year = 2005)
        {

        }

        int operator -(Date);

};


int Date::operator -(Date d)
        {
            int n = 0; //int variable to store the number of days.

            //condition if the year to be subtracted is greater.
            if(year < d.year)
            {
                cout << "Error!!" << endl;
                cout << day << "/" << month << "/" << year << " is smaller than ";
                cout << d.day << "/" << d.month << "/" << d.year << endl;
            }

            //condition if the years are equal.
            else if(year == d.year)
            {
                //condition if the years are equal but the month to be subtracted is greater.
                if(month < d.month)
                {
                    cout << "Error!!" << endl;
                    cout << day << "/" << month << "/" << year << " is smaller than ";
                    cout << d.day << "/" << d.month << "/" << d.year << endl;
                }

                //condition if the years are equal and the months are equal.
                else if(month == d.month)
                {
                    //condition if the years and months are equal but the day to be subtracted is greater.
                    if(day < d.day)
                    {
                        cout << "Error!!" << endl;
                        cout << day << "/" << month << "/" << year << " is smaller than ";
                        cout << d.day << "/" << d.month << "/" << d.year << endl;
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

            //condition if the year to be subtracted is smaller.
            else
            {
                //for loop adds the days in the year.
                for(int i = d.year+1; i < year; i++)
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


int main()
{
    Date d8(23, 4, 2008);
    Date d9(21, 8, 2006);


    cout <<  d8 - d9 << " days." << endl;

    Date d10(25,9, 2006);
    Date d11(2, 4, 2006);
    Date d12(3, 2, 2006);
    Date d13(2, 2, 2008);

    cout << d8 - d10 << endl;
    cout << d8 - d11 << endl;
    cout << d8 - d12 << endl;
    cout << d8 - d13 << endl;
    return 0;
}
