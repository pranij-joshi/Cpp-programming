#include <iostream>
using namespace std;

//declaration of class A declartion
class A
{
    protected:
        int A_value;
};

//declaration of Class B declaration which inherits class A
class B : public A
{
    public:
        B() // Use of a constructor to initialize A_value
        {
        A_value = 20;
        }
};

//declaration of Class C
class C
{
    protected:
        int C_value;
    public:

    C() //Use of a constructor to initialize C_value
    {
        C_value = 40;
    }
};

//declaration of Class D which inheritance class b and class c
class D : public B, public C
{
public:
    void product()
    {
        cout<<"The product of the two integer values is: " << A_value * C_value<<endl;
    }
};

int main()
{

D d; // Object d of derived class D
d.product();
return 0;
}
