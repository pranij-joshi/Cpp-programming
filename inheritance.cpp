#include <iostream>

using namespace std;

class A
{
private:
    int x = 5;

protected:
    int z = 20;

public:
    int y = 10;
};

class  B : A //default mode private
{
public:
    //int y = 10; //becomes private
    //int z = 20; //becomes private
    void display()
    {
        //cout << "X = " << x << endl; //will show error because it is private in parent class.
        cout << "Y = " << y << endl;
        cout << "Z = " << z << endl;
    }
};


class C : B
{
public:
    void show()
    {
        display();
    }
};

int main()
{
    B b;
    b.display();
}



