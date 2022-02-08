#include <iostream>

using namespace std;
//declaring a Base class
class Base
{
    public:
        //display function
        //virtual keyword is used for late binding.
        virtual void display()
        {
            cout << "Base class" << endl;
        }

};

//declaring a Derived class
class Derived : public Base
{
    public:
        //display function
        void display()
        {
            cout << "Display's Derived class by using virtual funciton." << endl;
        }
};

int main()
{
    //declaring an object of derived class
    Derived d;
    //declaring a pointer object of base class.
    Base *b;

    //giving the address of the derived object to base object
    b = &d;

    //calls the function of the base class.
    b->display();


    return 0;
}



