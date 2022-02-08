/**********************************************
This program demonstrates a Book Class
//@author Sukant Kumar Sahu
//Date of Creation: 11th June 2021
***********************************************
*/

#include<iostream>
using namespace std;

//Book class declaration
class Book{
	private:
		int bookID;

	public:
		Book() // Default constructor which sets the default bookID to 500
		{
			bookID=500;
		}

		Book( int id)// Parameterized constructor which takes in the value of bookID
		{
			bookID=id;
		}

		//setBookID assigns a value to the bookID member.
		void setBookID(int id)
		{
			bookID=id;
		}

		// getBookID returns the value of the bookID member.
		int getBookID()
		{
			return bookID;

		}

		//function for print of the data entered.
		void printData();

};

//************************************************************
//fuction will print the bookId.  *
//************************************************************
void Book::printData()
{
	cout<<"Book ID: "<<bookID<<endl; //displays the values stored in bookID.
}

//************************************************************
//Function main
//************************************************************
int main()
{
	Book b; //Define an instance of the Book class and calls the
	//default constructor.
	//displays the bookId 500 as it calls the default constructor.
	b.printData();

	b.setBookID(1000); //assigning new value of bookID
	b.printData(); //displays the bookID.

	b.setBookID(1200);//assigning a new value for booID;
	cout<<"Book Id: "<<b.getBookID()<<endl; //displays the assigned value

	Book b1(5000); //Defines an instance and calls the parameterized constructor
	b1.printData(); //Displays the data.


	return 0;

}

