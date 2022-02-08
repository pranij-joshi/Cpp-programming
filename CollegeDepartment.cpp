/****************************************
-This program demonstrates a CollegeDepartment
 class.
-It will use insertion operator overloading, less than
 operator overloading, greater than operator overloading
 and the equal to operator overloading.
//@author Pranij Joshi
//Date of creation: 9th July, 2021
*****************************************
*/

#include <iostream>

using namespace std;

//CollegeDepartment class declaration
class CollegeDepartment
{
    private:
        //private data members
        string deptName;
        string chairName;
        int numClasses;
        string *courses;

    public:
        //member function prototypes
        CollegeDepartment();
        CollegeDepartment(string, string, int);
        friend ostream& operator <<(ostream &, CollegeDepartment &);
        friend bool operator >(CollegeDepartment &, CollegeDepartment &);
        friend bool operator <(CollegeDepartment &, CollegeDepartment &);
        void operator =(CollegeDepartment &);
};


//***********************************************
//Default Constructor for Meal class.
//***********************************************
CollegeDepartment::CollegeDepartment()
{
    deptName = "Mathematics";
    chairName = "Lewis";
    numClasses = 10;

    //dynamically allocating memory for courses.
    courses = new string[numClasses];
    for(int i = 0; i < numClasses; i++)
    {
        *(courses + i) = "N/A";
    }
}


//***********************************************
//Parameterized Constructor for Meal class.
//***********************************************
CollegeDepartment::CollegeDepartment(string department, string head, int number)
{
    deptName = department;
    chairName = head;
    numClasses = number;

    //dynamically allocating memory for courses.
    courses = new string[numClasses];
    cout << endl << "Enter the courses in the department:" << endl;

    //loop to read the course list form user.
    for(int i = 0; i < numClasses; i++)
    {
        cout << "Enter course " << i+1 << ": ";
        cin >> *(courses + i);
    }
}


//***********************************************
//friend function which overloads the << operator and displays
//the values in the CollegeDepartment class.
//***********************************************
ostream& operator <<(ostream &out, CollegeDepartment &c)
{
    out << "Department Name: " << c.deptName << endl;
    out << "Department Chair's Name: " << c.chairName << endl;
    out << "Number of classes offered: " << c.numClasses << endl;
    out << "List of courses:" << endl;

    //loop to display the courses list.
    for(int i = 0; i < c.numClasses; i++)
    {
        out << "\t" << i+1 << ". " << *(c.courses + i) << endl;
    }
}


//************************************************************
//friend function which overloads the < operator and returns true
//if the number of classes of the object on left is less than the
//number of classes of the object on the right. else it will return
//false.
//************************************************************
bool operator <(CollegeDepartment &c1, CollegeDepartment &c2)
{
    return c1.numClasses < c2.numClasses;
}


//************************************************************
//friend function which overloads the > operator and returns true
//if the number of classes of the object on left is greater than the
//number of classes of the object on the right. else it will return
//false.
//************************************************************
bool operator >(CollegeDepartment &c1, CollegeDepartment &c2)
{
    return c1.numClasses > c2.numClasses;
}


//************************************************************
//friend function which overloads the = operator and assigns the
//value stored in passed the object to class object.
//************************************************************
void CollegeDepartment::operator =(CollegeDepartment &c)
{
    deptName = c.deptName;
    chairName = c.chairName;
    numClasses = c.numClasses;

    //to assign the courses.
    for(int i = 0; i < numClasses; i++)
    {
        *(courses + i) = *(c.courses + i);
    }
}


//************************************************************
//Function main
//************************************************************
int main()
{
    //creating an array of object for CollegeDepartment class.
    CollegeDepartment c[4];

    string name, head; //string to store dept. name and chair's name
    int number; // int to store the number of classes.

    //to read the data from user and copy the object
    for(int i = 0; i < 4; i++)
    {
        cout << "Enter the Department name: ";
        cin >> name;
        cout << "Enter the Department Chair's name: ";
        cin >> head;
        cout << "Enter the number of courses: ";
        cin >> number;

        //temporary object to store the user input.
        CollegeDepartment temp(name, head, number);

        //assigns the temp object values to c[i] object.
        c[i] = temp;
        cout << "***********************************************" << endl;
        cout << "***********************************************" << endl;
    }

    cout << "\n\nThe list of Departments and the courses if offers are:\n";

    //displays the values stored in the object.
    for(int i = 0; i < 4; i++)
    {
        //displays the value stored in c[i]
        cout << c[i];
        cout << "***********************************************" << endl;
        cout << "***********************************************" << endl;
    }



    return 0;
}
