#include <iostream>

using namespace std;

//declaring a class car.
class Car
{
    private:
        int yearModel;
        string make;
        int speed;

    public:
        //constructor for a Car
        Car(int year, string model)
        {
            yearModel = year;
            make = model;
            speed  = 0;
        }

        //accessor function to get the year Model.
        int getYear()
        {
            return yearModel;
        }

        //accessor function to get the Model.
        string getMake()
        {
            return make;
        }

        //accessor function to get the speed of the function.
        int getSpeed()
        {
            return speed;
        }

        //function to return the speed after acceleration
        int accelerate()
        {
            return speed += 5;
        }

        //function to return the speed after breaking.
        int brake()
        {
            return speed -= 5;
        }
};

//main function
int main()
{
    string model;   //declaring a sting model
    int year;       //declaring an int year

    //Asking the user for input fr the car year and model.
    cout << "Enter the following details for the car: \n";
    cout << "Make year: ";
    cin >> year;

    cout << "Make: ";
    cin >> model;

    //creating an object for the class Car with two arguments.
    Car c(year, model);

    //Displaying output
    cout << "The make year of the car is: " << c.getYear() << endl;
    cout << "The model of the car is: " << c.getMake() << endl;
    cout << "The speed of the car is: " << c.getSpeed() << endl;

    cout << "\n============================================\n";

    //Displaying the output after increasing the speed for 5 times using for loop
    for(int x = 0; x < 5; x++)
    {
        cout << "After acceleration the speed of the car is: " << c.accelerate() << endl;
    }

    cout << "\n============================================\n";

    //Displaying the output after increasing the speed for 5 times using for loop
    for(int x = 0; x < 5; x++)
    {
        cout << "After braking the speed of the car is: " << c.brake() << endl;
    }

    cout << "\n============================================\n";

    return 0;
}
