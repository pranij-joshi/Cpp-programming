/****************************************
This program demonstrates a Person class
//@author Pranij Joshi
//Date of creation: 26th June, 2021
*****************************************
*/

#include <iostream>

using namespace std;

//Person class declaration
class Person
{
    private:
        string first;
        string last;
        string zip;

    public:
        //Default constructor
        Person(string first = "X", string last = "X", string zip = "X")
        {
            Person::first = first;
            Person::last = last;
            Person::zip = zip;
        }

        void display();

        //Destructor for Person class
        ~Person()
        {

        }
};

//*************************************************
//Function to display the data
//*************************************************
void Person::display()
{
    cout << "The details of the person is as follows: " << endl;
    cout << "First name:\t" << first << endl;
    cout << "Last name:\t" << last << endl;
    cout << "Zip code:\t" << zip << endl;
}


//*************************************************
//Function main
//*************************************************
int main()
{
    //creating an instance of person class with default values
    Person p1;
    //displaying the data
    p1.display();

    cout << endl << endl;

    //creating an instance of person class with arguments
    Person p2("Pranij", "Joshi", "21842");
    //displaying the data
    p2.display();

    return 0;
}
