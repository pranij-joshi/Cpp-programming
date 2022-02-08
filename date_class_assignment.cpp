#include <iostream>

using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int, int, int);
        void display();
        void operator --();

};

Date::Date(int day =1, int month = 1, int year = 1)
    {
        if(month > 12 || month < 1)
        {
            cout << "Error value for month." << endl;
            cout << "Default month value set." << endl;
            month = 1;
        }

        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if(day < 1 || day > 31)
            {
                cout << "Date is invalid. Assigning default value." << endl;
                day = 1;
            }
        }

        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day < 1 || day > 30)
            {
                cout << "Date is invalid. Assigning default value." << endl;
                day = 1;
            }
        }

        else
        {
            if(day < 1 || day > 29)
            {
                cout << "Date is invalid. Assigning default value." << endl;
                day = 1;
            }
        }

        Date::day = day;
        Date::month = month;
        Date::year = year;
    }

void Date::display()
    {
        cout << day << "/" << month << "/" << year << endl;
    }

void Date::operator --()
{
    --day;

    int d, m;

    d = day;

    if(month == 5 || month == 7 || month == 10 || month == 12)
    {
        if(day == 0)
        {
            day = 30;
            month = month -1;
        }
    }

    else if(month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
    {
        if(day == 0)
        {
            day = 31;
            month = month -1;
            if(month == 0)
            {
                month = 12;
                year = year - 1;
            }
        }
    }

    else
    {
        if(day == 0)
        {
            day == 28;
            month = month -1;
        }
    }

}


int main()
{
    Date d1(27, 5, 2009);
    d1.display();
    cout << "Date after decrement." << endl;
    --d1;
    d1.display();

    cout << endl << endl;

    Date d2(1, 1, 2009);
    d2.display();
    cout << "Date after decrement." << endl;
    --d2;
    d2.display();

    return 0;
}
