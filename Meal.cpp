/****************************************
-This program demonstrates a Meal class.
-It will add the calories and display the result.
-insertion, extraction and addition operator
 overloading is also showcased.
//@author Pranij Joshi
//Date of creation: 9th July, 2021
*****************************************
*/

#include <iostream>

using namespace std;

//Meal class declaration
class Meal
{
    private:
        //private data members
        string entree;
        int calories;

    public:
        //member function prototypes.
        Meal(string, int);
        void display();
        friend ostream &operator <<(ostream &, Meal &);
        friend istream &operator >>(istream &, Meal &);
        Meal operator +(Meal);
};


//***********************************************
//Constructor for Meal class.
//accepts both parameterized and non parameterized values.
//***********************************************
Meal::Meal(string entree = "", int calories = 0)
{
    Meal:: entree = entree;
    Meal::calories = calories;
}


//***********************************************
//display the values in the Meal class.
//***********************************************
void Meal::display()
{
    cout << "Meal: " << entree << endl;
    cout << "Calories: " << calories << endl;
}


//***********************************************
//friend function to overload the << insertion operator.
//it will display the values in the object passed.
//***********************************************
ostream &operator <<(ostream &out, Meal &m)
{
    out << "Meal: " << m.entree << endl;
    out << "Calories: " << m.calories << endl;
}


//***********************************************
//friend function to overload the >> extraction operator.
//it will read the values from the user for the object passed.
//***********************************************
istream &operator >>(istream &in, Meal &m)
{
    cout << "Meal: ";
    in >> m.entree;
    cout << "Calories: ";
    in >> m.calories;
}


//***********************************************
//friend function to overload the + addition operator.
//it will add the calories and return an object.
//***********************************************
Meal Meal::operator +(Meal m)
{
    Meal temp;
    temp.entree = "Daily Total";
    temp.calories = calories + m.calories;

    return temp;
}


//***********************************************
//Function main
//***********************************************
int main()
{
    //creating three parameterized objects for Meal class.
    Meal breakfast("Eggs and Waffle", 527);
    Meal lunch("Lobster Roll", 436);
    Meal dinner("Surf and Turf", 390);

    //creating an object
    Meal day_total;

    //add the calories.
    day_total = breakfast + lunch + dinner;

    //displays the result.
    cout << "Breakfast: " << endl;;
    cout << breakfast;
    cout << "******************************************" << endl;
    cout << "Lunch: " << endl;
    cout << lunch;
    cout << "******************************************" << endl;
    cout << "Dinner: " << endl;
    cout << dinner;
    cout << "******************************************" << endl;
    cout << "Day total: " <<endl;
    cout << day_total;
    cout << "******************************************" << endl;


    return 0;
}
