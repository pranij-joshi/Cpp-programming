//3.	Write a program which accepts days as integer and display total number of years, months and days in it.
#include <iostream>

using namespace std;

main()
{
    int number, month, year, days, temp;

    cout << "Enter the number of the days: ";
    cin >> number;

    temp = number;

    year = temp / 365;
    temp = temp % 365;

    month = temp / 30;
    temp = temp % 30;

    days = temp;

    cout << endl;
    cout << number << " days is equivalent to " << year << " years ";
    cout << month << " months and " << days << " days." << endl;
}
