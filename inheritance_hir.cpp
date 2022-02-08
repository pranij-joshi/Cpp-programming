#include <iostream>

using namespace std;

class Polygon
{
    protected:
        int length;
        int breadth;
    public:
        Polygon()
        {
            length = 5;
            breadth = 10;
        }
        void setValue(int l, int b)
        {
            length = l;
            breadth = b;
        }
};

class Rectangle : Polygon
{
    public:
        int area()
        {
            return length*breadth;
        }
};

class Triangle : Polygon
{
    public:
    int area()
    {
        return (length * breadth)/2;
    }
};

int main()
{
    Polygon p;
    p.setValue(20, 30);

    Rectangle r;
    cout << "Area of rectangle : " << r.area() << endl;

    Triangle t;
    cout << "Area of triangle : " << t.area() << endl;
    return 0;
}
