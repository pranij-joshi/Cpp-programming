#include<iostream>

using namespace std;

class Meter
{
    int m;
    int cm;

public:
    Meter()
    {
        m = cm = 0;
    }

    Meter(int m, int cm)
    {
        Meter::m = m;
        Meter::cm = cm;
    }
    void display()
    {
        cout << "Meter = " << m << endl;
        cout << "Centimeter = " << cm << endl;
    }

    Meter operator +(Meter n)
    {
        Meter temp;

        int x;
        int y;
        x = cm + n.cm;
        temp.cm = x%100;
        y = x/100;
        temp.m = y + m + n.m;
        return temp;
    }
};



int main()
{
    Meter m1(2, 35);
    Meter m2(5, 87);

    Meter m3;

    m3 = m1 + m2; //add two objects

    m1.display();
    m2.display();
    m3.display();


    return 0;
}

