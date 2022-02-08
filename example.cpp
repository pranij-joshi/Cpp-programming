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
        int acc_num;
        string acc_name;
        float balance;
        float annual_int_rate;
        float ser_charge;
        int numdeposit;
        int numwithdraw;


    public:
        Bank(float, float);
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
    ifstream file;
    Saving temp;
    int num = 0;

    file.open("saving.txt", ios::in);

    if(!file)
    {
        return (num + 1);
    }

    else
    {
        file >> temp.acc_num >> temp.acc_name >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;
        while(!file.eof())
        {
            num = temp.acc_num;
            file >> temp.acc_num >> temp.acc_name >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;
        }

        num++;
        file.close();
        return (num);
    }



}

//************************************************************
//Function to show the header
//************************************************************
void Saving::show_header()
{
    cout << left;
    cout << endl << setw(20) << "Account Number" << setw(20) << "Account Name" << setw(20) << "Balance" << setw(20) << "Deposits" << setw(20) << "Withdrawals" << setw(20) << "Service charges" << endl;
}


//************************************************************
//Function show a specific account and display it.
//************************************************************
void Saving::show_acc()
{
    Saving t;
    int number;
    bool flag = false;
    cout << "Enter the account number you want to search for: ";
    cin >> number;

    ifstream file;

    file.open("saving.txt");

    file >> t.acc_num >> t.acc_name >> t.balance >> t.numdeposit >> t.numwithdraw >> t.ser_charge;
    while(!file.eof())
    {
        if(number == t.acc_num)
        {
            flag = true;
            Saving::show_header();
            cout << t;
        }
        file >> t.acc_num >> t.acc_name >> t.balance >> t.numdeposit >> t.numwithdraw >> t.ser_charge;
    }

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
    cout << "Balance: ";
    cin >> s.balance;
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

    file.open("saving.txt", ios::out|ios::app);

    if(!file)
    {
        cout << "File cannot be found!!" << endl;
    }

    else
    {
        s= Saving::get_acc();
        Saving::show_header();

        cout << s;

        file << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;

    }

    file.close();



}


//************************************************************
//overloading the << operator
//************************************************************
ostream& operator <<(ostream &out, Saving &s)
{
    cout << setw(20) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;

}

//************************************************************
//function to show all account in the saving.txt file
//************************************************************
void Saving::show_all()
{
    Saving s;
    ifstream file;
    file.open("saving.txt", ios::in);
    file >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    Saving::show_header();
    while(!file.eof())
    {
        cout << s;
        file >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;

    }

    file.close();
}


//************************************************************
//function to check the status of the account.
//************************************************************
bool Saving::status(float b)
{
    if(b < 25)
    {
        return false;
    }
    else
    {
        return true;
    }
}


//************************************************************
//Makes a deposit to the saving account
//************************************************************
void Saving::makeDeposit()
{
    Saving s;
    double deposit;
    int number;
    bool flag = false;

    cout << "Enter the account number you want to make a deposit: ";
    cin >> number;

    cout << "Enter the amount of deposit: ";
    cin >> deposit;

    ifstream rfile;
    ofstream ofile;

    rfile.open("saving.txt");
    ofile.open("temp.txt");

    rfile >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    while(!rfile.eof())
    {
        if(number == s.acc_num)
        {
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

            if(!status(s.balance))
            {
                cout << "After making a deposit of " << deposit << "Your account is still inactive!!" << endl;
            }

            else
            {
                cout << "After making a deposit of " << deposit << "Your account is now active!!" << endl;
            }
        }
        ofile << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;
        rfile >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    }

    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    rfile.close();
    ofile.close();


    system("erase saving.txt");
    system("rename temp.txt saving.txt");
}


//************************************************************
//makes a withdrawal from the saving account.
//************************************************************
void Saving::makeWithdrawal()
{
    Saving s;
    double withdraw;
    int number;
    bool flag = false;

    cout << "Enter the account number you want to make a withdraw: ";
    cin >> number;

    cout << "Enter the amount of withdraw: ";
    cin >> withdraw;

    ifstream rfile;
    ofstream ofile;

    rfile.open("saving.txt");
    ofile.open("temp.txt");

    rfile >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    while(!rfile.eof())
    {
        if(number == s.acc_num)
        {

            flag = true;
            if(!status(s.balance))
            {
                cout << "Sorry cannot withdraw money. Account is inactive." << endl;
            }
            else
            {
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
        ofile << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;
        rfile >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    }

    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    rfile.close();
    ofile.close();


    system("erase saving.txt");
    system("rename temp.txt saving.txt");
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

    rfile.open("saving.txt", ios::in);
    ofile.open("temp.txt", ios::out);

    if(!rfile)
    {
        cout << "File could not be found!!" << endl;
        exit(1);
    }
    Saving::show_header();
    rfile >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    while(!rfile.eof())
    {
        if(s.numwithdraw > 4)
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


        ofile << setw(10) << s.acc_num << setw(20) << s.acc_name << setw(20) << s.balance << setw(20) << s.numdeposit << setw(20) << s.numwithdraw << setw(20) << s.ser_charge << endl;
        rfile >> s.acc_num >> s.acc_name >> s.balance >> s.numdeposit >> s.numwithdraw >> s.ser_charge;
    }

    rfile.close();
    ofile.close();


    system("erase saving.txt");
    system("rename temp.txt saving.txt");

}


//Checking class declaration
//inherits the base class.
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
    cout << setw(20) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;

}



//************************************************************
//gets the account number from the file.
//It reads the file and adds increments the last account in the
//file for the new account number.
//************************************************************
int Checking::get_acc_number()
{
    ifstream file;
    Checking temp;
    int num = 0;

    file.open("checking.txt", ios::in);

    if(!file)
    {
        return (num + 1);
    }

    else
    {
        file >> temp.acc_num >> temp.acc_name >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;
        while(!file.eof())
        {
            num = temp.acc_num;
            file >> temp.acc_num >> temp.acc_name >> temp.balance >> temp.numdeposit >> temp.numwithdraw >> temp.ser_charge;
        }

        num++;
        file.close();
        return (num);
    }



}


//************************************************************
//Function to show the header files.
//************************************************************
void Checking::show_header()
{
    cout << left;
    cout << endl << setw(20) << "Account Number" << setw(20) << "Account Name" << setw(20) << "Balance" << setw(20) << "Deposits" << setw(20) << "Withdrawals" << setw(20) << "Service charges" << endl;
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

    file >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    while(!file.eof())
    {
        if(number == c.acc_num)
        {
            flag = true;
            Checking::show_header();
            cout << c;
        }
        file >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
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
    Checking c;
    cout << "Enter the account name: ";
    fflush(stdin);
    cin >> c.acc_name;
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
    Checking c;
    ofstream file;


    file.open("checking.txt", ios::out|ios::app);


    if(!file)
    {
        cout << "File cannot be found!!" << endl;
    }

    else
    {
        c = Checking::get_acc();

        cout << "The entered account details are as follows: " << endl;
        Checking::show_header();
        cout << c;

        file.write((char*)&c, sizeof(c));

    }

    file.close();



}


//************************************************************
//Function to show all the account
//************************************************************
void Checking::show_all()
{
    Checking c;
    ifstream file;
    file.open("checking.txt", ios::in);
    file >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    show_header();
    while(!file.eof())
    {
        cout << c;

        file >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;

    }

    file.close();
}


//************************************************************
//Function to make a deposit to checking account
//It updates the file and stores it.
//************************************************************
void Checking::makeDeposit()
{
    Checking c;
    double deposit;
    int number;
    bool flag = false;

    cout << "Enter the account number you want to make a deposit: ";
    cin >> number;

    cout << "Enter the amount of deposit: ";
    cin >> deposit;

    ifstream rfile;
    ofstream ofile;

    rfile.open("checking.txt");
    ofile.open("temp.txt");

    rfile >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    while(!rfile.eof())
    {
        if(number == c.acc_num)
        {
            flag = true;
            c.balance = c.balance + deposit;
            c.numdeposit++;
            Checking::show_header();
            cout << c;

        }
        ofile << setw(10) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;
        rfile >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    }

    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    rfile.close();
    ofile.close();


    system("erase checking.txt");
    system("rename temp.txt checking.txt");
}


//************************************************************
//Function to to make a withdrawal
//it updates the file and stores it.
//************************************************************
void Checking::makeWithdrawal()
{
    Checking c;
    double withdraw;
    int number;
    bool flag = false;

    cout << "Enter the account number you want to make a withdraw: ";
    cin >> number;

    cout << "Enter the amount of withdraw: ";
    cin >> withdraw;

    ifstream rfile;
    ofstream ofile;

    rfile.open("checking.txt");
    ofile.open("temp.txt");

    rfile >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
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
        ofile << setw(10) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;
        rfile >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    }

    if(!flag)
    {
        cout << "Account number could not be found!!" << endl;
    }

    rfile.close();
    ofile.close();


    system("erase checking.txt");
    system("rename temp.txt checking.txt");
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
    rfile >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    while(!rfile.eof())
    {
        c.ser_charge = 5;
        for(int i = 0; i < numwithdraw; i++)
        {
            c.ser_charge = c.ser_charge + 0.10;
        }

        c.balance = Checking::calcInt(c.balance);
        c.balance = c.balance - c.ser_charge;

        cout << c;
        ofile << setw(10) << c.acc_num << setw(20) << c.acc_name << setw(20) << c.balance << setw(20) << c.numdeposit << setw(20) << c.numwithdraw << setw(20) << c.ser_charge << endl;
        rfile >> c.acc_num >> c.acc_name >> c.balance >> c.numdeposit >> c.numwithdraw >> c.ser_charge;
    }

    rfile.close();
    ofile.close();


    system("erase checking.txt");
    system("rename temp.txt checking.txt");

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
                        break;

                    case 2:
                        b1->show_all();
                        break;

                    case 3:
                        b1->show_acc();
                        break;

                    case 4:
                        b1->monthlyProc();
                        break;

                    case 5:
                        b1->makeDeposit();
                        break;

                    case 6:
                        b1->makeWithdrawal();
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
                        break;

                    case 2:
                        b2->show_all();
                        break;

                    case 3:
                        b2->show_acc();
                        break;

                    case 4:
                        b2->monthlyProc();
                        break;

                    case 5:
                        b2->makeDeposit();
                        break;

                    case 6:
                        b2->makeWithdrawal();
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
