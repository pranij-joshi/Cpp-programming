//3.	Create a structure named Apartment that contains data fields to hold the number of bedrooms,
//the number of baths, and the monthly rent for the Apartment. Write a program that creates an
//Apartment object and prompts the user for number of bedrooms and baths desired. Determine the rent
//from the following table and set the rent field appropriately. If a requested apartment type is not
//available, set the rent field to 0.

//Display all the data including an error message if the entered data is invalid,
//or if no apartments are available with the requested combination.

#include<iostream>

using namespace std;

//declaring structure named Apartments.
struct Apartment
{
    int no_of_bedrooms;
    int no_of_baths;
    int rent;
};

main()
{
    //Creating an object for Apartments.
    Apartment a1;

    //Displaying the availability of apartments.
    cout << "\tApartments Availability" << endl;
    cout << "\t\t1 bath \t\t2 bath" << endl;
    cout << "1 bedroom\t$ 650.00\tNot available" << endl;
    cout << "2 bedroom\t$ 829.00\t$925.00" << endl;
    cout << "3 bedroom\tNot available\t1075.00" << endl;
    cout << "\n************************************************************\n";

    //asking for user input.
    cout << "Enter the following details for the aparment: " << endl;
    cout << "Number of bedrooms: ";
    cin >> a1.no_of_bedrooms;
    cout << "number of baths: ";
    cin >> a1.no_of_baths;
    cout << "\n************************************************************\n\n";

    //switch case for number of bedrooms.
    switch(a1.no_of_bedrooms)
    {
    //Case if the number of bedroom is 1.
    case 1:
        //switch case for number of bathrooms.
        switch(a1.no_of_baths)
        {
        //case if the number of bathroom is 1.
        case 1:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 650.00" << endl;
            break;

        //case if the number of bathroom is 2.
        case 2:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 00.00" << endl;
            cout << "Apartment is not available with the requested combination." << endl;
            break;

        //case if the number of bathroom does not meet the criteria.
        default:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 00.00" << endl;
            cout << "Apartment is not available with the requested combination." << endl;
            break;
        }
        break;

    //Case if the number of bedroom is 2.
    case 2:
        //switch case for number of bathrooms.
        switch(a1.no_of_baths)
        {
        //case if the number of bathroom is 1.
        case 1:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 829.00" << endl;
            break;

        //case if the number of bathroom is 2.
        case 2:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 925.00" << endl;
            break;

        //case if the number of bathroom does not meet the criteria.
        default:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 00.00" << endl;
            cout << "Apartment is not available with the requested combination." << endl;
            break;
        }
        break;

    //Case if the number of bedroom is 3.
    case 3:
        //switch case for number of bathrooms.
        switch(a1.no_of_baths)
        {
        //case if the number of bathroom is 1.
        case 1:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 00.00" << endl;
            cout << "Apartment is not available with the requested combination." << endl;
            break;

        //case if the number of bathroom is 2.
        case 2:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 1075.00" << endl;
            break;

        //case if the number of bathroom does not meet the criteria.
        default:
            cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
            cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
            cout << "Rent: \t\t\t$ 00.00" << endl;
            cout << "Apartment is not available with the requested combination." << endl;
            break;
        }
        break;

    //case if the number of bedrooms does not meet the criteria.
    default:
        cout << "Number of Bedrooms: \t" << a1.no_of_bedrooms << endl;
        cout << "Number of Bathrooms: \t" << a1.no_of_baths << endl;
        cout << "Rent: \t\t\t$ 00.00" << endl;
        cout << "Apartment is not available with the requested combination." << endl;
        break;

    }
}
