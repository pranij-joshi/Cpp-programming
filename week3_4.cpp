#include <iostream>

using namespace std;

//declaring a class RetailItem
class RetailItem
{
    private:
        string description;
        int unitsOnHand;
        double price;

    public:
        //constructor with no arguments
        RetailItem()
        {
            description = "";
            unitsOnHand = 0;
            price = 0.0;
        }

        //constructor with multiple arguments
        RetailItem(string desc, int unit, double cost)
        {
            description = desc;
            unitsOnHand = unit;
            price = cost;
        }

        //mutator function to set the description
        void setDescription(string desc)
        {
            description = desc;
        }

        //mutator function to set the units on hand
        void setUnitsOnHand(int unit)
        {
            unitsOnHand = unit;
        }

        //mutator function to set the price
        void setPrice(double cost)
        {
            price = cost;
        }

        //accessor function to get the description
        string getDescription()
        {
            return description;
        }

        //accessor function to get the units on the hand
        int getUnitsOnHand()
        {
            return unitsOnHand;
        }

        //accessor function to get the price
        double getPrice()
        {
            return price;
        }

        //function to display the data
        void displayData()
        {
            cout << "Item Description: " << getDescription() << endl;
            cout << "Units on Hand: " << getUnitsOnHand() << endl;
            cout << "Price: $" << getPrice() << endl;
            cout << "\n===========================================\n";
        }
};

int main()
{
    //creating instances for the class RetailItem
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    //displaying the item data
    item1.displayData();
    item2.displayData();
    item3.displayData();

    return 0;
}
