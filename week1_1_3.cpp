#include <iostream>

using namespace std;

main()
{

    int num, i;

    cout << "Enter a number: ";
    cin >> num;

    i = num % 2;

    if(i == 0)
    {
        cout << "Even number!";
    }
    else
    {
        cout << "Odd Number!";
    }

}
