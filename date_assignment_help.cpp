#include <iostream>

using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;

        static int numbef_of_days[];

    public:
        Date()
        {
            day = month = year = 0;
        }

        Date(int d, int m, int y)
        {
            day = d;
            month = m;
            year = y;
        }

        void display()
        {
            //cout << "Day : " << day << endl;
            //cout << "Month : " << month << endl;
            //cout << "Year : " << year << endl;

            cout << day << "/" << month << "/" << year << endl;
        }

        bool operator ==(Date &d)
        {
            if(day == d.day && month == d.month && year == d.year)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        Date& operator --();

        friend ostream& operator <<(ostream &out, Date &d);

};

int Date::numbef_of_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//void Date::decrement()
//{

//}

//Date &Date::operator --()
//{
//    return *this;
//}


ostream& operator <<(ostream &out, Date &d)
{
    static string month_names[13] = {"", "January", "February", "March",
                                        "April", "May", "June",
                                        "July", "August", "September",
                                        "October", "November", "December"};

    out << month_names[d.month] << " " << d.day << "," << d.year << endl;
    int temp = d.year%100;
    printf("%02d/%02d/%02d", d.day, d.month, temp);
}

int main()
{
    Date d1(12, 5, 2021);
    cout << d1;

    /*d1.display();
    Date d2(12, 6, 2021);
    d2.display();

    if(d1 == d2)
    {
        cout << "Both dates are equal." << endl;
    }

    else
    {
        cout << "Dates are not equal." << endl;
    }*/

    return 0;
}
