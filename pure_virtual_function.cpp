#include <iostream>

using namespace std;
//declaring a Base class
class Base
{
    public:
        //display function
        //virtual keyword is used for late binding.
        virtual void display() = 0;
};

//declaring a Derived class
class Derived : public Base
{
    public:
        //display function
        void display()
        {
            cout << "Display's Derived class by using pure virtual function." << endl;
        }
};

int main()
{
    //declaring an object of derived class
    Derived d;


    d.display();




    return 0;
}



