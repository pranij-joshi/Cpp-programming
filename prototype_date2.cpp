#include <iostream>

using namespace std;

class Date
{
    private:
        int day, month, year;
    public:
        Date(int day = 1, int month = 1, int year = 1)
        {
            while(day > 31 || day < 1)
            {
                cout << "Enter the day: ";
                cin >> day;
            }

            while(month > 12 || month < 1)
            {
                cout << "Enter the month: ";
                cin >> month;
            }

            Date::day = day;
            Date::month = month;
            Date::year = year;
        }

        void display()
        {
            cout << day << "/" << month << "/" << year << endl;
        }
};

int main()
{
    Date d1(45, 23, 3334);

    return 0;
}
