/****************************************
This program demonstrates a Car class and its
constructor and destructor.
//@author Pranij Joshi
//Date of creation: 26th June, 2021
*****************************************
*/

#include <iostream>

using namespace std;

//Car class declaration.
class Car
{
    private:
        //declaring a static int count for the Car class.
        static int count;

    public:
        //Constructor for class Car.
        Car()
        {
            //increments count by 1.
            count++;

            //Displays the count every time Car class is created.
            cout << "Car " << count << " was created." << endl;
        }

        //Destructor for class car.
        ~Car()
        {
            //Displays the count every time Car class is created.
            cout << "Car " << count << " was deleted." << endl;

            //decrements count by 1.
            count--;
        }
};

//*************************************************
//Initializing static variable count to 0.
//*************************************************
int Car::count = 0;


//*************************************************
//Function main
//*************************************************
int main()
{
    //creating a array of 5 objects for Car class.
    Car c[5];

    cout << endl;

    return 0;
}
