#include <iostream>
using namespace std;

//Base class declaration
class Base
{
    protected:
        int b_value;
    public:
        void Base_input()
        {
            cout<< "Enter the integer value of base class: ";
            cin>> b_value;
        }
};

//derived class declaration which inherits Base class
class Derived1 : public Base
{
    protected:
        int d1_value;
    public:

        void Derived1_input()
        {
            cout << "Enter the integer value of first derived class: ";
            cin >> d1_value;
        }
};

//derived class which inherits derived1 class which inherits base class.
class Derived2 : public Derived1
{
    protected:
        int d2_value;
    public:

        void Derived2_input()
        {
            cout<< "Enter the integer value of the second derived class: ";
            cin>> d2_value;
        }

        //function to find the sum
        void sum()
        {
            cout << "The sum of the three intger values is: " << b_value + d1_value + d2_value<<endl;
        }
};
int main()
{
    //creating a derived2 class object.
    Derived2 d2;
    d2.Base_input();
    d2.Derived1_input();
    d2.Derived2_input();
    d2.sum();
    return 0;
}

