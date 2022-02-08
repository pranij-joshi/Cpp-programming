//pointer class
#include <iostream>

using namespace std;

class A
{
    private:
        int x;

    public:
        A()
        {
            //this -> x = 10; works as pointer to the address of x and later accesses x;
            x = 10;
        }

        void setX(int a)
        {
            x = a;
        }

        int getX()
        {
            return x;
        }

        void display()
        {
            cout << "x = " << x << endl;
        }

};

int main()
{
    A a;
    a.display();

    A *p; //creating an object using pointer.
    p = &a; // pointer that points to the object a

    p -> setX(3000);//pointer to set the value of x
    p -> display(); // pointer calls the address and then displays x

    (*p).display(); //another syntax to retireve the properties of object.
    A a1;
    a1.setX(200);
    //a1.display();
    cout << "Value of x = " << a1.getX() << endl;
    A a2;
    a2.setX(20);
    a2.display();

    //A a3 = a1 + a2; //adding two objects gets an error

    return 0;
}
