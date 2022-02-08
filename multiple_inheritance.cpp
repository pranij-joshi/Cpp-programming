#include <iostream>

using namespace std;

class A
{
protected:
    int x;
public:
    A()
    {
        x = 0;
    }

    void setX(int x)
    {
        A::x = x;
    }
};

class B
{
protected:
    int y;
public:
    B()
    {
        y = 0;
    }

    void setY(int y)
    {
        B::y = y;
    }
};

class C : A,B //multiple inheritance
{
public:
    int add()
    {
        return x + y;
    }
};


int main()
{
    A a;
    a.setX(20);
    B b;
    b.setY(30);

    C c;
    int sum = c.add();
    cout << "Addition = " << sum << endl;


    return 0;
}

