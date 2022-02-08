/**********************************************
This program demonstrates a Student Class
//@author Sukant Kumar Sahu
//Date of Creation: 15th June 2021
***********************************************
*/
#include<iostream>
#include<string.h>
using namespace std;

//Student class declaration
class Student
{
	int roll;
	string name;
	public:
        //default constructor that accepts parameterized and non- parameterized object.
		Student(int roll = 500, string name = "Kathmandu")
		{
		    //explicitly mentions that left sides takes value for the Student class.
			Student::roll = roll;
			Student::name = name;
		}
		//copy Constructor that takes the value of the object passed.
		Student(Student &std)
		{
			roll = std.roll;
			name = std.name;
		}

		//function to display the data.
		void display()
		{
			cout << "Student Rollno = " << roll << endl;
			cout << "Student Name = " << name << endl;
		}
};
int main()
{

	Student s1; //Defines an instance of Student class
	s1.display(); //displays the data stored in the default constructor

	int x = 100; //Local int variable that is set to 100
	string s = "Ram"; //Local string variable that is set to "Ram"
	Student s2(x,s); //Defines an instance of student class
	s2.display(); //Displays the output

	Student s4(200,"Ramesh");// parameters are constants

	Student s3; //Defines an instance of Student class
	s3 = s2; // copying data of one object to other object
	cout << "The  copied data in student s3 = \n";
	s3.display(); // Displays the data.
	cout << "Data stored in S-5 : \n";

	Student s5(s4);//defines an instance of Student class that
	//passes the value of object s4.
	s5.display(); //Displays the output

	cout << endl << "Details of S-6 : \n";
	Student s6(s5);//defines an instance of Student class that
	//passes the value of object s5.
	s6.display(); //Displays the output

	return 0;
}
