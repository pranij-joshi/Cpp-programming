#include <iostream>

using namespace std;

//base class declaration
class Base
{
    protected:
        int value;

    public:

    //function to take input for base class.
    void base_input()
    {
        cout<<"Enter the integer value of base class: ";
        cin>>value;
    }
};

class Derived : public Base
{

    public:

    //function to take input for derived class.
    void derived_input()
    {
        cout<<"Enter the integer value of derived class: ";
        cin>>value;
    }

    //function to add the values of both base and derived class.
    void sum()
    {
        cout << "The sum of the two integer values is: " << Base::value + Derived::value << endl;
    }
};

int main()
{
    // Creating an Object of the derived class
    Derived d;
    //calls base input
    d.base_input();

    //calls the derived input
    d.derived_input();

    //calls the sum function to add the two values.
    d.sum();

    return 0;
}
