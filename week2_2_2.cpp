//2.	Write a program for a furniture company. Ask the user to choose P for pine, O for oak, or M for mahogany.
//Then ask the user how many pieces do you want? Then show the total billing price of a table/s manufactured with
//the chosen wood as the format shown below.
//Pine tables cost $100, oak tables cost $225, and mahogany tables cost $310.
//[ Hint : Declare 3 numeric constant values  to store the wood costs]		[20 marks]

//Sample Output:
//=====================================
//Italian Woods Furniture Company
//=====================================
//Enter P for pine, O for oak or M for mahogany : M
//How many tables do you want : 3

//Wood Selected	No of tables		Total cost
//------------------		---------------		------------
//Mahogany		3			$930

//Thank you for visiting us.
//=====================================
//Hint: use switch case

#include <iostream>
#include <cctype>

//declaring constants for price of pine, oak and mahogany.
const int P = 100;
const int O = 225;
const int M = 310;

using namespace std;

main()
{
    char type;              //declaring char type for type of wood.
    int table_num, total;   //declaring int table_num and total for number of tables and the total amount.


        cout << "=====================================" << endl;
        cout << "Italian Woods Furniture Company" << endl;
        cout << "=====================================" << endl;

        //User inputs.
        cout << "Enter P for pine, O for oak or M for mahogany: ";
        cin >> type;

        cout << "How many tables do you want: ";
        cin >> table_num;

        cout  << endl;

        cout << "Wood Selected\tNo. of tables\tTotal cost" << endl;
        cout << "--------------------------------------------\n";

        //switch case for the type of wood.
        switch(toupper(type))
        {
        case 'P':
            total = table_num * P;
            cout << "Pine\t\t" << table_num << "\t\t" << total << endl;
            break;

        case 'O':
            total = table_num * O;
            cout << "Oak\t\t" << table_num << "\t\t" << total << endl;
            break;

        case 'M':
            total = table_num * M;
            cout << "Mahogany\t" << table_num << "\t\t" << total << endl;
            break;

        default:
            cout << "Wrong input" << endl;
            break;
        }

        cout << "\nThank you for visiting us.\n";
        cout << "=====================================\n";
}
