#include <iostream>

using namespace std;

class A
{
private:
    int x;
public:
    A() //allocate memory
    {
        cout << "Constructor has been called" << endl;
    }

    ~A() //clean memory
    {
        cout << "Destructor has been called" << endl;
    }
};

int main()
{
    A a1, a2, a3;


    return 0;
}
