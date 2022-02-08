#include <iostream>

using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int day = 1, int month =1, int year = 1)
        {
            if(month < 1 || month > 12)
            {
                cout << month << " is an invalid data for months." << endl;
                cout << "Error month can only be between 1-12!" << endl;
                cout << "Setting the month to default value 1." << endl;
                month = 1;
            }


            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                //condition if the day is not between 1-31.
                if(day < 1 || day > 31)
                {
                    cout << day << " is an invalid data for day." << endl;
                    cout << "Setting the day to default value 1." << endl;
                    day = 1;
                }
            }

            else if(month == 4 || month == 6 || month == 9 || month == 11)
            {
                if(day < 1 || day > 30)
                {
                    cout << day << " is an invalid data for day." << endl;
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
                        cout << "Setting the day to default value 1." << endl;
                        day = 1;
                    }
                }

                else
                {
                    if(day < 1 || day > 28)
                    {
                        cout << day << " is an invalid data for day." << endl;
                        cout << "Setting the day to default value 1." << endl;
                        day = 1;
                    }
                }

            }

            Date::day = day;
            Date::month = month;
            Date::year = year;
        }


        void display()
        {
            cout << day << "/" << month << "/" << year << endl;
        }


        void operator --()
        {
            --day;
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
                if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                {
                    if(day == 0)
                    {
                        day = 29;
                        month = month -1;
                    }
                }

                else
                {
                    if(day == 0)
                    {
                        day = 28;
                        month = month - 1;
                    }
                }
            }
        }
};

int main()
{
    Date d1(1,3,2008);
    cout << "The date is: ";
    d1.display();
    cout << endl;
    --d1;
    cout << "The date after decrement is: ";
    d1.display();

}
