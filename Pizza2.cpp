/****************************************
This program demonstrates a Pizza class.
//Date of creation: 2nd July, 2021
*****************************************
*/

#include <iostream>
#include <string>

using namespace std;

//Pizza class declaration.
class Pizza
{
    private:
        //private variable declaration.
        string topping;
        int diameter;
        double price;

        //static variables declaration.
        const static string STDTOP;
        const static int STDSIZE;
        const static double STDPRICE;
    public:
        //member function prototypes for Pizza class.
        Pizza(const string = STDTOP, const int  = STDSIZE, const double = STDPRICE);
        void setValues();
        void displayValues();
};

//assigning value to static STDTOP.
const string Pizza::STDTOP = "cheese";

//assigning value to static int STDSIZE.
const int Pizza::STDSIZE = 12;

//assigning value to static double STDPRICE.
const double Pizza::STDPRICE = 8.99;

//**********************************************
//Constructor for Pizza class.
//**********************************************
Pizza::Pizza(const string top, const int size, const double price)
{
    topping = top;
    diameter = size;
    this->price = price; //using pointer
}

//**********************************************
//function to display the data for Pizza class.
//**********************************************
void Pizza::displayValues()
{
    cout << "a " << diameter << " inch " << topping << " pizza. Price $" << price << endl;
}

//**********************************************
//function to set the values to the member function of Pizza class.
//**********************************************
void Pizza::setValues()
{
    const double TOPPINGPREMIUM = 1.00;
    const double SIZEPREMIUM = 1.50;
    cout << "Enter topping ";
    cin >> topping;
    if(topping != STDTOP)
        price = STDPRICE + TOPPINGPREMIUM;
    cout << "Enter size ";
    cin >> diameter;
    if(diameter > STDSIZE)
        price += SIZEPREMIUM;
}


//**********************************************
//main function.
//**********************************************
int main()
{
    //creating an default instance for pizza class.
    Pizza stdPizza;
    //creating an instance for pizza class with one arguments.
    Pizza special("pineapple");
    //creating an instance for pizza class with two arguments.
    Pizza deluxeSpecial("sausage", 16);
    //creating an instance for pizza class with three arguments.
    Pizza veryDeluxeSpecial("lobster", 20, 17.99);

    cout << "The standard pizza is: ";
    //displays the values for a standard pizza.
    stdPizza.displayValues();
    cout << "Today's special is ";
    //displays the values for a special pizza.
    special.displayValues();
    cout << "The deluxe special is ";
    //displays the values for a deluxe special pizza.
    deluxeSpecial.displayValues();
    cout << "And the very deluxe special is ";
    //displays the values for a very deluxe special pizza.
    veryDeluxeSpecial.displayValues();
    return 0;
}

