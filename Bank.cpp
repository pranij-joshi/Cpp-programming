#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>


using namespace std;

//Bank class declaration.
//base class for Checking and Saving class.
class Bank
{
    protected:
        //protected members
        int acc_num;
        string acc_name;
        string fname;
        string lname;
        string phone;
        string add;
        float balance;
        float annual_int_rate;
        float ser_charge;
        int numdeposit;
        int numwithdraw;


    public:

        Bank(float, float);

        //virtual function declaration.
        virtual int get_acc_number() = 0;
        virtual void show_header() = 0;
        virtual void show_acc() = 0;
        virtual void open_acc() = 0;
        virtual void show_all() = 0;
        virtual void makeDeposit() = 0;
        virtual void makeWithdrawal() = 0;
        virtual float calcInt(float) = 0;
        virtual void monthlyProc() = 0;
};

//constructor for Bank class
Bank::Bank(float b = 0, float i = 7.5)
{
    balance = b;
    annual_int_rate = i;
    acc_num = 0;
    numdeposit = 0;
    numwithdraw = 0;
    ser_charge = 0;
}

//Saving class declaration
//inherits Bank class as public.
class Saving : public Bank
{
    public:
        Saving(float b = 0, float a = 7.5) : Bank(balance, annual_int_rate)
        {
            balance = b;
            annual_int_rate = a;
        }

        int get_acc_number();
        void show_header();
        Saving get_acc();
        void show_acc();
        void open_acc();
        void show_all();
        bool status(float);
        void makeDeposit();
        void makeWithdrawal();
        float calcInt(float);
        void monthlyProc();
        friend ostream& operator <<(ostream &, Saving &);


};

//************************************************************
//gets the account number from the file.
//It reads the file and adds increments the last account in the
//file for the new account number.
//************************************************************
int Saving::get_acc_number()
{
    //declaring a file to read
    ifstream file;
    Saving temp; //temporary object for saving class.
    int num = 0;


    //opening the saving.txt file
    file.open("saving.txt");

    if(!file)
    {
        return (num + 1);
    }

    else
    {
        file >> temp.acc_num >> temp.acc_name >> temp.fname >> temp.lname >> temp.phone >> temp.add >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;
        while(!file.eof())
        {
            num = temp.acc_num;
            file >> temp.acc_num >> temp.acc_name >> temp.fname >> temp.lname >> temp.phone >> temp.add >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;

        }

        num++;
        file.close();
        return (num);//returns the account number.
    }



}

//************************************************************
//Function to show the header files.
//************************************************************
void Saving::show_header()
{
    cout << left;
    cout << endl << setw(20) << "Account Number" << setw(20) << "Account Name" << setw(20) << "First name" << setw(20) << "Last name" << setw(20) << "Phone" << setw(20) << "Address" << setw(20) << "Balance" << setw(20) << "Deposits" << setw(20) << "Withdrawals" << setw(20) << "Service charges" << endl;
}


//************************************************************
//Function show a specific account and display it.
//************************************************************
void Saving::show_acc()
{
    Saving t; //object of saving class
    int number;
    bool flag = false;
    cout << "Enter the account number you want to search for: ";
    cin >> number;

    //file declaration for to read.
    ifstream file;

    //opening the file.
    file.open("saving.txt");

    //reads from the file.
    file >> t.acc_num >> t.acc_name >> t.fname >> t.lname >> t.phone >> t.add >> t.balance >> t.numdeposit >> t.numwithdraw >> t.ser_charge;
    while(!file.eof())//while not end of file.
    {
        if(number == t.acc_num)
        {
            flag = true;
            Saving::show_header();
            cout << t;
        }
        //reads from the file.
        file >> t.acc_num >> t.acc_name >> t.fname >> t.lname >> t.phone >> t.add >> t.balance >> t.numdeposit >> t.numwithdraw >> t.ser_charge;
    }

    //if the account number is not found.
    if(!flag)
    {
        cout << "Account could not be found." << endl;
    }

    file.close();
}


//************************************************************
//Function to get the account from the user.
//************************************************************
Saving Saving::get_acc()
{
    Saving s;
    cout << "Enter the account name: ";
    fflush(stdin);
    cin >> s.acc_name;
    cout << "Enter first name: ";
    cin >> s.fname;
    cout << "Enter last name: ";
    cin >> s.lname;
    cout << "Enter phone number: ";
    cin >> s.phone;
    cout << "Enter address: ";
    cin >> s.add;
    cout << "Balance: ";
    cin >> s.balance;
    while(s.balance < 0)
    {
        cout << "Balance cannot be negative.";
        cout << "Balance: ";
        cin >> s.balance;

    }
    s.acc_num = get_acc_number();
    s.numdeposit = 0;
    s.numwithdraw = 0;
    s.ser_charge = 0;

    return s;

}


//************************************************************
//Function to open new account for saving class.
//************************************************************
void Saving::open_acc()
{
    Saving s;
    ofstream file;

    //opens the file for ouptut and appends on it.
    file.open("saving.txt", ios::out|ios::app);

    if(!file)
    {
        cout << "File cannot be found!!" << endl;
    }

    else
    {
        //gets the account info and stores it in s object
        s = Saving::get_acc();
        Saving::show_header();

        cout << s;

        //writes the account info in the file.
        file << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.fname << setw(20) << s.lname << setw(20) << s.phone << setw(20) << s.add << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;

    }

    file.close();



}


//************************************************************
//overloading the << operator
//************************************************************
ostream& operator <<(ostream &out, Saving &s)
{
    cout << setw(20) << s.acc_num << setw(20) << s.acc_name  << setw(20) << s.fname << setw(20) << s.lname << setw(20) << s.phone << setw(20) << s.add << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;

}

//************************************************************
//function to show all account in the saving.txt file
//************************************************************
void Saving::show_all()
{
    Saving s;//creating an object of saving class
    ifstream file; //declaring a file for reading.
    file.open("saving.txt", ios::in);//opening a file to read from.

    //reads from the file.
    file >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    Saving::show_header();
    while(!file.eof())
    {
        //prints the output to the screen.
        cout << s;

        //reads from the file
        file >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;

    }

    //closes the file
    file.close();
}


//************************************************************
//function to check the status of the account.
//************************************************************
bool Saving::status(float b)
{
    if(b < 25)
    {
        //returns false if the balance is below 25
        return false;
    }
    else
    {
        //else it returns true.
        return true;
    }
}


//************************************************************
//Makes a deposit to the saving account
//************************************************************
void Saving::makeDeposit()
{
    Saving s;//creating an object
    double deposit;
    int number;
    bool flag = false;

    //asks the user for the account to make the deposit
    cout << "Enter the account number you want to make a deposit: ";
    cin >> number;

    //asks deposit to be made to the account
    cout << "Enter the amount of deposit: ";
    cin >> deposit;

    ifstream rfile;// open a read only file
    ofstream ofile;//opening a write only temporary file.

    rfile.open("saving.txt");//opens file
    ofile.open("temp.txt");//opens file

    rfile >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    while(!rfile.eof())
    {
        if(number == s.acc_num)
        {
            //checks the status of the account
            if(!status(s.balance))
            {
                cout << "Your account is inactive!!" << endl;
            }

            flag = true;
            s.balance = s.balance + deposit;
            s.numdeposit++;
            cout << "Account details after making the deposit:" << endl;
            Saving::show_header();
            cout << s;

            //checks status after making a deposit.
            if(!status(s.balance))
            {
                cout << "After making a deposit of " << deposit << "Your account is still inactive!!" << endl;
            }

            else
            {
                cout << "After making a deposit of " << deposit << "Your account is now active!!" << endl;
            }
        }
        //writes to the temp file
        ofile << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.fname << setw(20) << s.lname << setw(20) << s.phone << setw(20) << s.add << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;
        //reads from saving.txt
        rfile >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    }

    //if the account number is not found
    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    rfile.close();//closes the file
    ofile.close();//closes the file


    system("erase saving.txt"); //erases saving.txt
    system("rename temp.txt saving.txt"); //renames temp.txt to saving.txt
}


//************************************************************
//makes a withdrawal from the saving account.
//************************************************************
void Saving::makeWithdrawal()
{
    Saving s;//object declaring
    double withdraw;
    int number;
    bool flag = false;

    //account to be deposited to
    cout << "Enter the account number you want to make a withdraw: ";
    cin >> number;

    //the amount to withdraw
    cout << "Enter the amount of withdraw: ";
    cin >> withdraw;

    ifstream rfile;//open a read file
    ofstream ofile;//opens a write file

    rfile.open("saving.txt");//opens the saving.txt file
    ofile.open("temp.txt"); //opens the temp.txt file

    rfile >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    while(!rfile.eof())
    {
        //matches the account number to the file.
        if(number == s.acc_num)
        {

            flag = true;
            //checks the status of the file.
            if(!status(s.balance))
            {
                cout << "Sorry cannot withdraw money. Account is inactive." << endl;
            }
            else
            {
                //condition for withdraws from the account.
                if(withdraw > s.balance)
                {
                    cout << "Insufficient funds." << endl;
                }
                else
                {
                    s.balance = s.balance - withdraw;
                    s.numwithdraw++;
                    cout << "Account details after making the withdrawal is:" << endl;
                    Saving::show_header();
                    cout << s;
                }

            }

        }
        //writes to the temp.txt file
        ofile << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.fname << setw(20) << s.lname << setw(20) << s.phone << setw(20) << s.add << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;
        //reads from saving.txt file
        rfile >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    }

    //if account number is not found.
    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    //closes the files
    rfile.close();
    ofile.close();


    system("erase saving.txt");//erases the saving.txt file
    system("rename temp.txt saving.txt"); //renames temp.txt to saving.txt
}


//************************************************************
//returns the balance after calculating the interest.
//************************************************************
float Saving::calcInt(float balance)
{
    balance = balance + (balance * (annual_int_rate/12));
    return balance;
}


//************************************************************
//Function to calculate the monthly proc
//************************************************************
void Saving::monthlyProc()
{
    Saving s;
    double charge = 0;
    ifstream rfile;
    ofstream ofile;

    rfile.open("saving.txt");
    ofile.open("temp.txt");

    if(!rfile)
    {
        cout << "File could not be found!!" << endl;
        exit(1);
    }
    //calls the show header file.
    Saving::show_header();

    //reads from the file.
    rfile >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;

    while(!rfile.eof())//while not end of file
    {
        if(s.numwithdraw > 4) //if withdraw is more than 4.
        {
            for(int i = 5; i <= numwithdraw; i++)
            {
                charge = charge + 1;
            }
            s.balance = calcInt(s.balance);
            s.balance = s.balance - charge;
            s.numdeposit = 0;
            s.numwithdraw = 0;
            s.ser_charge = 0;
            cout << s;
            if(!status(s.balance))
            {
                cout << "Account number " << s.acc_num << " is now inactive." << endl;
            }


        }

        //writes to temp.txt
        ofile << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.fname << setw(20) << s.lname << setw(20) << s.phone << setw(20) << s.add << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;
        //reads from saving.txt
        rfile >> s.acc_num >> s.acc_name >> s.fname >> s.lname >> s.phone >> s.add >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    }

    //closes the files
    rfile.close();
    ofile.close();


    system("erase saving.txt");//erases the saving.txt
    system("rename temp.txt saving.txt"); //renames the temp.txt to saving.txt

}


//Checking class declaration
//inherits the bank class as public.
class Checking : public Bank
{
    public:
        Checking(float b = 0, float a = 1.5) : Bank(balance, annual_int_rate)
        {
            balance = b;
            annual_int_rate = a;
        }
        float getAnnualInterestRate(float r);
        int get_acc_number();
        void show_header();
        Checking get_acc();
        void show_acc();
        void open_acc();
        void show_all();
        void makeDeposit();
        void makeWithdrawal();
        float calcInt(float);
        void monthlyProc();
        friend ostream& operator <<(ostream &, Checking &);


};


//************************************************************
//function to overload the << operator
//************************************************************
ostream& operator <<(ostream &out, Checking &c)
{
    cout << setw(20) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.fname << setw(20) << c.lname << setw(20) << c.phone << setw(20) << c.add << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;

}



//************************************************************
//gets the account number from the file.
//It reads the file and adds increments the last account in the
//file for the new account number.
//************************************************************
int Checking::get_acc_number()
{
    ifstream file; //declaring file to read from
    Checking temp;
    int num = 0;

    file.open("checking.txt", ios::in);//opening the file

    if(!file)
    {
        return (num + 1);
    }

    else
    {
        file >> temp.acc_num >> temp.acc_name >> temp.fname >> temp.lname >> temp.phone >> temp.add >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;
        while(!file.eof())
        {
            num = temp.acc_num;
            file >> temp.acc_num >> temp.acc_name >> temp.fname >> temp.lname >> temp.phone >> temp.add >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;
        }

        num++;
        file.close();//closes the file
        return (num);
    }



}

//************************************************************
//Function to show the header files.
//************************************************************
void Checking::show_header()
{
    cout << left;
    cout << endl << setw(20) << "Account Number" << setw(20) << "Account Name" << setw(20) << "First name" << setw(20) << "Last name" << setw(20) << "Phone" << setw(20) << "Address" << setw(20) << "Balance" << setw(20) << "Deposits" << setw(20) << "Withdrawals" << setw(20) << "Service charges" << endl;
}


//************************************************************
//Function to show a specific account.
//************************************************************
void Checking::show_acc()
{
    Checking c;
    int number;
    bool flag = false;
    cout << "Enter the account number you want to search for: ";
    cin >> number;

    ifstream file;

    file.open("checking.txt");

    file >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    while(!file.eof())
    {
        if(number == c.acc_num)
        {
            flag = true;
            Checking::show_header();
            cout << c;
        }
        file >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    }

    if(!flag)
    {
        cout << "Account could not be found." << endl;
    }

    file.close();
}


//************************************************************
//Function to get the account details.
//************************************************************
Checking Checking::get_acc()
{
    Checking c; //creating an object
    cout << "Enter the account name: ";
    fflush(stdin);
    cin >> c.acc_name;
    cout << "Enter first name: ";
    cin >> c.fname;
    cout << "Enter last name: ";
    cin >> c.lname;
    cout << "Enter phone number: ";
    cin >> c.phone;
    cout << "Enter address: ";
    cin >> c.add;
    cout << "Balance: ";
    cin >> c.balance;
    c.acc_num = get_acc_number();
    c.numdeposit = 0;
    c.numwithdraw = 0;
    c.ser_charge = 0;

    return c;
}


//************************************************************
//Function to open a new account.
//************************************************************
void Checking::open_acc()
{
    Checking c;//creating an object
    ofstream file;


    file.open("checking.txt", ios::out|ios::app);//opening the file .

    if(!file)
    {
        cout << "File cannot be found!!" << endl;
    }

    else
    {
        c = Checking::get_acc();

        cout << "The entered account details are as follows: " << endl;
        Checking::show_header();
        cout << c;//printing output

        //writing to the file
        file << setw(10) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.fname << setw(20) << c.lname << setw(20) << c.phone << setw(20) << c.add << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;

    }

    file.close();//closing the file



}


//************************************************************
//Function to show all the account
//************************************************************
void Checking::show_all()
{
    Checking c;//creating an object
    ifstream file;//declaring a file to read from
    file.open("checking.txt", ios::in);//opening a file

    //reads from the file
    file >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    show_header();
    while(!file.eof())
    {
        cout << c;//prints the output

        file >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;

    }

    file.close();//closes the file
}


//************************************************************
//Function to make a deposit to checking account
//It updates the file and stores it.
//************************************************************
void Checking::makeDeposit()
{
    Checking c;//creating an object
    double deposit;
    int number;
    bool flag = false;


    //asks the user for the account number to make the deposit
    cout << "Enter the account number you want to make a deposit: ";
    cin >> number;

    //asks the user for deposit amount
    cout << "Enter the amount of deposit: ";
    cin >> deposit;


    ifstream rfile;//read from the file declaration
    ofstream ofile;//write to the file declaration

    rfile.open("checking.txt"); //opens the file
    ofile.open("temp.txt");//opens the file

    rfile >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    while(!rfile.eof())
    {
        //if account number is found
        if(number == c.acc_num)
        {
            flag = true;
            c.balance = c.balance + deposit;
            c.numdeposit++;
            Checking::show_header();
            cout << c;

        }
        //writes to the temp.file
        ofile << setw(10) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.fname << setw(20) << c.lname << setw(20) << c.phone << setw(20) << c.add << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;
        //reads from the file
        rfile >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    }

    //Account is not found
    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    rfile.close();
    ofile.close();


    system("erase checing.txt");//erases the saving.txt
    system("rename temp.txt checking.txt"); //renames the temp.txt to saving.txt
}


//************************************************************
//Function to to make a withdrawal
//it updates the file and stores it.
//************************************************************
void Checking::makeWithdrawal()
{
    Checking c;//creating an object
    double withdraw;
    int number;
    bool flag = false;

    //asks the account number to make the withdrawal from
    cout << "Enter the account number you want to make a withdraw: ";
    cin >> number;

    //asks the withdrawal amount
    cout << "Enter the amount of withdraw: ";
    cin >> withdraw;

    ifstream rfile;//ifstream to read from the file
    ofstream ofile;//to write to the file

    rfile.open("checking.txt");//opening the file
    ofile.open("temp.txt");//opening the file

    rfile >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    while(!rfile.eof())
    {
        if(number == c.acc_num)
        {

            flag = true;
            if(withdraw > c.balance)
            {
                c.balance = c.balance - 15;
                cout << "Insufficient funds." << endl;
                c.numwithdraw++;
            }
            else
            {
                c.balance = c.balance - withdraw;
                c.numwithdraw++;
            }


        }
        //write to the file
        ofile << setw(10) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.fname << setw(20) << c.lname << setw(20) << c.phone << setw(20) << c.add << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;
        //read from the file
        rfile >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    }

    //account not found
    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    //closes the files
    rfile.close();
    ofile.close();


    system("erase checking.txt");//erases the saving.txt
    system("rename temp.txt checking.txt"); //renames the temp.txt to saving.txt
}


//************************************************************
//Function calculate the interest and return it.
//************************************************************
float Checking::calcInt(float balance)
{
    balance = balance + (balance * (annual_int_rate/12));
    return balance;
}


//************************************************************
//Function to calculate the monthly proc and update the file
//will add 5 as service charge and 0.10 for every withdrawal
//************************************************************
void Checking::monthlyProc()
{
    Checking c;
    double charge = 0;
    ifstream rfile;
    ofstream ofile;

    rfile.open("checking.txt", ios::in);
    ofile.open("temp.txt", ios::out);

    if(!rfile)
    {
        cout << "File could not be found!!" << endl;
        exit(1);
    }

    Checking::show_header();
    rfile >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    while(!rfile.eof())
    {
        c.ser_charge = 5;
        for(int i = 0; i < numwithdraw; i++)
        {
            c.ser_charge = c.ser_charge + 0.10;
        }

        c.balance = Checking::calcInt(c.balance);
        c.balance = c.balance - c.ser_charge;
        c.numdeposit = 0;
        c.numwithdraw = 0;
        c.ser_charge = 0;

        cout << c;
        ofile << setw(10) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.fname << setw(20) << c.lname << setw(20) << c.phone << setw(20) << c.add << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;
        rfile >> c.acc_num >> c.acc_name >> c.fname >> c.lname >> c.phone >> c.add >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    }

    rfile.close();
    ofile.close();


    system("erase checking.txt");//erases the saving.txt
    system("rename temp.txt checking.txt"); //renames the temp.txt to saving.txt

}


//************************************************************
//Function to ask for the type of account.
//************************************************************
int type()
{
    int t;
    cout << "Enter: " << endl;
    cout << "\t'1' for Saving account." << endl;
    cout << "\t'2' for Checking account." << endl;
    cout << "\t'3' to exit." << endl;

    cout << "Enter your choice: ";
    cin >> t;

    return t;
}


//************************************************************
//Function to get the user choice
//************************************************************
int menu(int t)
{
    int m;
    if(t == 1)
    {
        cout << "You have chosen Saving account.\nHere are the options for saving account:\n\n" << endl;

        cout << "Enter:" << endl;
        cout << "\t '1' to open a new account." << endl;
        cout << "\t '2' to show all account." << endl;
        cout << "\t '3' to show a specific account detail." << endl;
        cout << "\t '4' to add the monthly proc detail." << endl;
        cout << "\t '5' to make a deposit." << endl;
        cout << "\t '6' to make a withdrawal." << endl;
        cout << "\t '7' to end the program." << endl;

        cout << "\nEnter your choice: ";
        cin >> m;
        return m;
    }

    if(t == 2)
    {
        cout << "You have chosen Checking account.\nHere are the options for checking account:\n\n" << endl;

        cout << "Enter:" << endl;
        cout << "\t '1' to open a new account." << endl;
        cout << "\t '2' to show all account." << endl;
        cout << "\t '3' to show a specific account detail." << endl;
        cout << "\t '4' to add the monthly proc detail." << endl;
        cout << "\t '5' to make a deposit." << endl;
        cout << "\t '6' to make a withdrawal." << endl;
        cout << "\t '7' to end the program." << endl;

        cout << "\nEnter your choice: ";
        cin >> m;
        return m;
    }
}


//************************************************************
//Function main
//************************************************************
int main()
{
    Checking c;
    Saving s;
    Bank *b1, *b2;
    int ty, ch;



    while(1)
    {
        ty = type();
        ch = menu(ty);

        switch(ty)
        {
            case 1:

                b1 = &s;

                switch(ch)
                {
                    case 1:
                        b1->open_acc();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 2:
                        b1->show_all();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 3:
                        b1->show_acc();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 4:
                        b1->monthlyProc();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 5:
                        b1->makeDeposit();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 6:
                        b1->makeWithdrawal();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 7:
                        exit(1);
                        break;

                    default:
                        cout << "Wrong input." << endl;
                        ch = menu(ty);
                        break;
                }
                break;


            case 2:


                b2 = &c;

                switch(ch)
                {
                    case 1:
                        b2->open_acc();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 2:
                        b2->show_all();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 3:
                        b2->show_acc();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 4:
                        b2->monthlyProc();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 5:
                        b2->makeDeposit();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 6:
                        b2->makeWithdrawal();
                        cout << endl << "*********************************************************************" << endl;
                        break;

                    case 7:
                        exit(1);
                        break;

                    default:
                        cout << "Wrong input." << endl;
                        ch = menu(ty);
                        break;
                }
                break;


            case 3:
                exit(1);
                break;


            default:
                cout << "Wrong input." << endl;
                ty = type();
                break;

        }


    }
    return 0;
}
