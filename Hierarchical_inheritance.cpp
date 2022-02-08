#include <iostream>
using namespace std;

//class A declaration.
class A
{
    protected:
        int x, y;
    public:
        void A_input()
        {
            cout<<"Enter two values of class A: ";
            cin>> x >> y;
        }
};

//declaration class B which inherits class A.
class B : public A
{
    public:
        void product()
        {
            cout<< "The Product of the two values is: "<< x * y << endl;
        }
};

//declaration class c which inherits class A.
class C : public A
{
    public:
        void division()
        {
            cout<<"The Division of the two values is: "<< x / y<<endl;
        }
};
int main()
{

B b; // Object b of derived class B
C c; // Object c of derived class C
b.A_input();
b.product();
c.A_input();
c.division();
return 0;
}
