#include<iostream>

using namespace std;

class Count
{
    int x;
public:
    Count() : x(20)
    {

    }

    void display()
    {
        cout << "x = " << x << endl;
    }

    void operator ++() //prefix
    {
        ++x;
    }

    void operator ++(int) //postfix
    {
        x++;
    }

    Count operator --()
    {
        Count temp;
        temp.x = --x;
        return temp;
    }
};

int main()
{
    Count c; //calls the default constructor : x= 20
    c.display();

    ++c; //increment the object
    c.display();

    c++; //increment the object
    c.display();

    --c;
    c.display();

    return 0;
}
