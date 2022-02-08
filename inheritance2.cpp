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

class  B : public A
{
    //int z = 20; //becomes private
public:
    //int y = 10; //becomes public

    void display()
    {

        cout << "Y = " << y << endl;
        cout << "Z = " << z << endl;
    }
};


class C : B
{
public:
    void show()
    {
        y = 50;
        cout << "Y = " << y << endl;
        z = 100;
        cout << "Z = " << z << endl;
    }
};

int main()
{
    B b;
    b.display();

    cout << endl << endl;

    C c;
    c.show();
}



