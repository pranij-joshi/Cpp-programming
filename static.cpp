#include <iostream>

using namespace std;

class Demo
{
    private:
        int a; // non static
        static int b; //static

    public:
        Demo()
        {

        }

        Demo(int a)
        {
            Demo::a = a;
        }

        void display() //non static function
        {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }

        static void show() //static function
        {
            //cout << "a = " << a << endl;
            cout << "Static function has been called." << endl;
            cout << "b = " << b << endl;
        }


};

int Demo :: b = 10; // initialize the static data members.
int main()
{
    Demo::show(); //calling the static function
    Demo d;
    d.show(); //object can be used to call static function too but not necessary.
    d.display(); // calling the non static function display.

    return 0;
}
