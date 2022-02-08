/****************************************
-This program demonstrates a Meal class.
-It will add the calories for 21 meals and
 display the result.
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
    temp.entree = "Weekly Total";
    temp.calories = calories + m.calories;

    return temp;
}


//***********************************************
//Function main
//***********************************************
int main()
{
    //creating an array of object for Meal class.
    Meal m[21];

    //creating a object to store the total calories for week.
    Meal week_total;

    int c = 0; //integer variable.

    //asks the user for the Meals.
    cout << "Enter the following details: " << endl;
    //For the days in the week.
    for(int i = 0; i < 7; i ++)
    {
        cout << "\tFor day " << i+1 << ": " << endl;

        //For the meals in a day.
        for(int j = 0; j < 3; j ++)
        {
            cout << "Meal " << j+1 << ":" << endl;
            cin >> m[c];
            cout << endl;

            //adds the calories.
            week_total = week_total + m[c];

            ++c;
        }
        cout << "******************************************" << endl;
    }

    c = 0;

    //Display the Meals in a week.

    //For the days in a week.
    for(int i = 0; i < 7; i ++)
    {
        cout << "\tFor day " << i+1 << ": " << endl;

        //For the meals in the week.
        for(int j = 0; j < 3; j ++)
        {
            cout << "Meal " << j+1 << ":" << endl;
            cout << m[c];
            cout << endl;

            ++c;
        }
        cout << "******************************************" << endl;
    }

    //Displays the total calories in a week.
    cout << "The weekly total is: " << endl;
    cout << week_total;

    return 0;
}

