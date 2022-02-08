//1.	Write a program to swap value of two variables without using third variable.

#include <iostream>

using namespace std;

main()
{
    int n1, n2, temp;

    cout << "Enter a value for n1: ";
    cin >> n1;

    cout << "Enter a value for n2: ";
    cin >> n2;

    cout << "The value in n1 is " << n1 << " and n2 is " << n2 << endl;

    temp = n1;
    n1 = n2;
    n2 = temp;

    cout << endl << endl;

    cout << "When the values are swapped:" << endl;
    cout << "The value in n1 is " << n1 << " and n2 is " << n2 << endl;
}
