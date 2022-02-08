//pointer class
#include <iostream>

using namespace std;

class A
{
    private:
        int x;
        int y;
        int z;

    public:
        A()
        {
            x = 0;
            y = 0;
            z = 0;
        }

        void setX(int a, int b, int c)
        {
            x = a;
            y = b;
            z = c;
        }

        //int getX()
        //{
        //    return x;
        //}

        void display()
        {
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
            cout << "z = " << z << endl;
        }

        void operator -(); //operator functon

};

//uniary operator overloading.
void A::operator-()
{
    x = -x;
    y = -y;
    z = -z;
}

int main()
{
    A a; //default x = 10
    a.setX(10, -12, 30);
    a.display();
    cout << endl;
    float m = 2.5;
    cout << "m = " << -m << endl << endl; //negating a literal floating point constant
    -a; //negate the object, it will change the properties of the object.
    a.display();

    return 0;
}

