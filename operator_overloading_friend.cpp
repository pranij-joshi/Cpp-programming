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

        friend void operator -(A &a); //friend operator function

};

//uniary operator overloading.
void operator-(A &a)
{
    a.x = -a.x;
    a.y = -a.y;
    a.z = -a.z;
}

int main()
{
    A a;
    a.setX(10, -12, 30);
    a.display();
    cout << endl;

    cout << "After negating the object: \";
    -a; //negate the object, it will change the properties of the object.
    a.display();

    return 0;
}


