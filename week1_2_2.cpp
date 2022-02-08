//2.	Write a program which input three numbers and display the largest number using ternary operator.
#include <iostream>

using namespace std;

main()
{
    int n1, n2, n3, largest;

    cout << "Enter a value for n1: ";
    cin >> n1;

    cout << "Enter a value for n2: ";
    cin >> n2;

    cout << "Enter a value for n3: ";
    cin >> n3;

    cout << "The values are: " << endl;
    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;
    cout << "n3: " << n3 << endl;

    cout << endl;

    //great = (a>b)?a: b; //ternary operator altrenative of if else
    largest = n1 > n2 ? (n1 > n3 ? n1 : n3) : (n2 > n3 ? n2 : n3) ;

    cout << "The greatest number is " << largest << endl;
}
