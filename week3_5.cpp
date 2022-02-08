#include <iostream>

using namespace std;

//declaring a circle class
class Circle
{
    private:
        // to hold the value of pi
        double pi;
        // to hold the value of radius
        double radius;

    public:
        //default constructor to set the radius to 0.0 and sets the pi to 3.14159
        Circle()
        {
            radius = 0.0;
            pi = 3.14159;
        }

        //constructor that accepts the radius as an argument and sets the pi to 3.14159
        Circle(double r)
        {
            radius = r;
            pi = 3.14159;
        }

        //mutator function for the radius
        void setRadius(double r)
        {
            radius = r;
        }

        //function to return the value of the radius
        double getRadius()
        {
            return radius;
        }

        //function to get the area of the circle. It will return the area of the circle.
        double getArea()
        {
            return pi * radius * radius;
        }

        //function to return the diameter of the circle.
        double getDiameter()
        {
            return 2 * radius;
        }

        //function to return the circumference of the circle.
        double getCircumference()
        {
            return 2 * pi * radius;
        }
};

//main function
int main()
{
    //to hold the value of the radius.
    double radius;

    //ask's the user for the radius.
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "\n=========================================\n";

    //creating an object for the radius.
    Circle c(radius);

    //Displaying the data for the Circle.
    cout << "The Circle details are as follows:" << endl;
    cout << "Radius:\t\t" << c.getRadius() << endl;
    cout << "Area:\t\t" << c.getArea() << endl;
    cout << "Diameter:\t" << c.getDiameter() << endl;
    cout << "Circumference:\t" << c.getCircumference() << endl;
    cout << "\n=========================================\n";
    return 0;
}
