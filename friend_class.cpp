#include <iostream>

using namespace std;

class A
{
    private:
        int x;

    public:
        A()
        {
            x = 10;
        }
        // friend class b can access private members of A but vice versa is not possible.
        friend class B;
};

class B
{
    public:
        //to access the private members the object has to be passed.
        void display(A a)
        {
            cout << "value stored at x = " << a.x << endl;
        }

};

int main()
{
    //declaring objects of class A and B.
    A a;
    B b;
    b.display(a);

    return 0;
}
