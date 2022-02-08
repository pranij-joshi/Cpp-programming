#include <iostream>

using namespace std;

//declaring a class employee
class Employee
{
    private:
        string name;
        int id;
        string department;
        string position;

    public:
        //construction with no parameters.
        Employee()
        {
            name = "";
            id = 0;
            department = "";
            position = "";
        }

        //constructor that takes two parameters name and Id
        Employee(string str, int num)
        {
            name = str;
            id = num;
            department = "";
            position = "";
        }

        //constructor that takes all the arguments
        Employee(string str, int num, string dept, string pos)
        {
            name = str;
            id = num;
            department = dept;
            position = pos;
        }

        //mutator function for Name
        void setName(string str, int num, string dept, string pos)
        {
            name = str;
        }

        //mutator function for ID
        void setId(int num)
        {
            id = num;
        }

        //mutator function for department
        void setDepartment(string dept)
        {
            department = dept;
        }

        //mutator function for position
        void setPosition(string pos)
        {
            position = pos;
        }

        //accessor function for Name
        string getName()
        {
            return name;
        }

        //accessor function for ID
        int getID()
        {
            return id;
        }

        //accessor function for department
        string getDepartment()
        {
            return department;
        }

        //accessor function for positon
        string getPosition()
        {
            return position;
        }
};


//main function
int main()
{
    //creating three objects E1, E2 and E3 for the class Employee with arguments.
    Employee E1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee E2("Mark Jones", 39119, "IT", "Programming");
    Employee E3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    //Printing all the output.
    cout << "Name\t\tID Number\tDepartment\tPosition" << endl;
    cout<< "===============================================================" << endl;
    cout << E1.getName() << "\t" << E1.getID() << "\t\t" << E1.getDepartment() << "\t" << E1.getPosition() << endl;
    cout << E2.getName() << "\t" << E2.getID() << "\t\t" << E2.getDepartment() << "\t\t" << E2.getPosition() << endl;
    cout << E3.getName() << "\t" << E3.getID() << "\t\t" << E3.getDepartment() << "\t" << E3.getPosition() << endl;

    return 0;
}
