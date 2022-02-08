//1.	Write a program that reads a Celsius degree in a double value from the console,
//then converts it to Fahrenheit and displays the result. The formula for the conversion is as follows:
//fahrenheit = (9 / 5) * celsius + 32

//Hint: In C++, 9 / 5 is 1, but 9.0 / 5 is 1.8.

#include <iostream>

using namespace std;

main()
{
    float farenheit, celsius;   //declaring float farenheit and celsius for the temperatures.

    //Asking for the user input.
    cout << "Enter the temperature in Degree Celsius: ";
    cin >> celsius;

    //changing celsius into farenheit.
    farenheit = ((9.0/5)*celsius) + 32;

    cout << endl;
    //printing the result.
    cout << celsius << " Celsius equals to " << farenheit << " Farenheit";
    cout << endl;
}
