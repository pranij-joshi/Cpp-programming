#include<iostream>
using namespace std;
class Polygon{
      protected:
            int length;
            int breadth;
      public:
            Polygon() {
                  length = 20; breadth = 30;
                   cout<< "Polygon constructor is called" << endl;
            }
            ~Polygon() {
                  cout << "Polygon destructor is called" << endl;
            }
            void setValue(int l, int b) {
                  length = l; breadth = b;
             }
};
class Rectangle : Polygon{
         public:
               Rectangle() {
                         cout << "Rectangle constructor is called" << endl;
               }
               ~Rectangle() {
                        cout << "Rectangle destructor is called" << endl;
                 }
                  int area() {
                           return length*breadth;
                  }
};
int main(){
         Rectangle r; // default constructor
         return 0;
}
