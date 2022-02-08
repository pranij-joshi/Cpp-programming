#include <iostream>

using namespace std;

//declaring a class, Persona_Information
class Personal_Information
{
    private:
        string name;
        string address;
        int age;
        string phone_number;

    public:
        //constructor with no arguments
        Personal_Information()
        {
            name = "";
            address = "";
            age = 0;
            phone_number = "";
        }

        //constructor with multiple arguments
        Personal_Information(string str, string add, int year, string number)
        {
            name = str;
            address = add;
            age = year;
            phone_number = number;
        }

        //mutator function to set the name
        void setName(string str)
        {
            name = str;
        }

        //mutator function to set the address
        void setAddress(string add)
        {
            address = add;
        }

        //mutator function to set the age
        void setAge(int year)
        {
            age = year;
        }

        //mutator function to set the phone number
        void setPhoneNumber(string number)
        {
            phone_number = number;
        }

        //accessor function to get the name
        string getName()
        {
            return name;
        }

        //accessor function to get the address
        string getAddress()
        {
            return address;
        }

        //accessor function to get the age
        int getAge()
        {
            return age;
        }

        //accessor function to get the phone number
        string getPhoneNumber()
        {
            return phone_number;
        }

        //function to display the data
        void displayData()
        {
            cout << "Name:\t\t" << name << endl;
            cout << "Address:\t" << address << endl;
            cout << "Age:\t\t" << age << endl;
            cout << "Phone Number:\t" << phone_number << endl;
        }

};

int main()
{
    //creating objects for the class Personal_information
    Personal_Information my("James Bond", "OO7", 45, "9297777777");
    Personal_Information friends("Bruce Wayne", "Gotham", 39, "4054443333");
    Personal_Information family("Tony Stark", "New York", 35, "9294568888");

    //Displaying the output
    cout << "My info:" << endl;
    my.displayData();
    cout << endl;
    cout << "My Friend:" << endl;
    friends.displayData();
    cout << endl;
    cout << "My family:" << endl;
    family.displayData();

    return 0;
}
