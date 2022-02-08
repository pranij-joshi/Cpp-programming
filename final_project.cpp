#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>

using namespace std;

class Account
{
    protected:
        int acc_num;
        float balance;
        int num_deposit;
        int num_withdraw;
        float interest;
        float ser_charge;

    public:
        Account(float b = 0, float i = 2.5)
        {
            balance = b;
            interest = i;
        }

        virtual void makeDeposit(float d)
        {
            int num, r = 0;

            num = acc_num;

            fstream file;


            file.open("account.txt", ios::in|ios::out|ios::binary);
            file.seekg(0);
            if(!file)
            {
                cout << "Error could not find the file." << endl;
            }

            else
            {

                file.read((char*)this, sizeof(*this));
                while(!file.eof())
                {
                    r++;

                    if(num == acc_num)
                    {
                        balance = balance + d;
                        num_deposit++;

                        file.seekp((r-1)*sizeof(Account), ios::beg);
                        file.write((char*)this,sizeof(*this));

                        break;

                    }

                    file.read((char*)this, sizeof(*this));

                }
            }
        }

        virtual void makeWithdrawal(float w)
        {
            int num, r = 0;
            float b;

            num = acc_num;
            b = balance;

            fstream file;


            file.open("account.txt", ios::in|ios::out|ios::binary);
            file.seekg(0);
            if(!file)
            {
                cout << "Error could not find the file." << endl;
            }

            else
            {

                file.read((char*)this, sizeof(*this));
                while(!file.eof())
                {
                    r++;

                    if(num == acc_num)
                    {


                        if(balance >= w)
                        {
                            balance = balance - w;
                            num_withdraw++;
                        }
                        else
                        {
                            balance = b;
                        }


                        file.seekp((r-1)*sizeof(Account), ios::beg);
                        file.write((char*)this,sizeof(*this));

                        break;

                    }

                    file.read((char*)this, sizeof(*this));

                }
            }

            balance = balance;
            num_withdraw++;
        }

        virtual void calcInt()
        {
            float mon_int;
            mon_int = interest/12;
            mon_int = mon_int * balance;
            balance = balance + mon_int;
        }

        virtual void monthlyProc()
        {
            int num, r = 0;
            float charge;
            charge = ser_charge;
            num = acc_num;

            fstream file;


            file.open("account.txt", ios::in|ios::out|ios::binary);
            file.seekg(0);
            if(!file)
            {
                cout << "Error could not find the file." << endl;
            }

            else
            {

                file.read((char*)this, sizeof(*this));
                while(!file.eof())
                {
                    r++;

                    if(num == acc_num)
                    {
                        balance = balance - charge;
                        Account::calcInt();
                        num_deposit = 0;
                        num_withdraw = 0;
                        ser_charge = 0;


                        file.seekp((r-1)*sizeof(Account), ios::beg);
                        file.write((char*)this,sizeof(*this));

                        break;

                    }

                    file.read((char*)this, sizeof(*this));

                }

            }
        }


        void search_acc()
        {
            ifstream fin;
            int num, flag = 0;
            fin.open("account.txt", ios::in | ios::binary);
            cout << "Enter your Account Number: ";
            fflush(stdin);
            cin >> num;
            if (!fin)
            {
                cout << "File not found";
            }
            else
            {
                fin.read((char*)this ,sizeof(*this));
                while(!fin.eof())
                {
                    if (acc_num == num)
                    {
                        flag = 1;
                        break;
                    }
                    fin.read((char*)this ,sizeof(*this));
                }
                if (flag == 0)
                {
                    cout << "Account not found not found";
                }

            }
        }


        void show_header()
        {
            cout << left;
            cout << endl << setw(20) << "Account Number" << setw(20) << "Balance" << setw(20) << "Deposits" << setw(20) << "Withdrawals" << setw(20) << "Service charges" << endl;
        }

        void show_acc()
        {
            cout << left;
            cout << setw(20) << acc_num << setw(20) << balance << setw(20) << num_deposit << setw(20) << num_withdraw << setw(20) << ser_charge << endl;
        }

        int allocate_acc_num()
        {
            ifstream file;

            int num = 0;
            file.open("account.txt", ios::in|ios::binary);
            if (!file)
            {
                return (num + 1);
            }
            else
            {
                file.read((char*)this, sizeof(*this));
                while(!file.eof())
                {
                    num = acc_num;
                    file.read((char*)this, sizeof(*this));
                }
                num++;
                return num;
            }
        }

        void get_acc_details()
        {

            acc_num = allocate_acc_num();


            cout << "Enter the balance: ";
            cin >> balance;
            while(balance < 0)
            {
                cout << "Error!! Balance cannot be negative." << endl;
                cout << "Enter the balance: ";
                cin >> balance;
            }

            num_deposit = 0;
            num_withdraw = 0;
            ser_charge = 0;

        }

        void open_acc()
        {
            ofstream file;
            file.open("account.txt", ios::out | ios::app | ios::binary);
            if(!file)
            {
                cout << "File not found" << endl;;
            }
            else
            {
                Account::get_acc_details();
                file.write((char*)this,sizeof(*this));
            }
        }

        void view_acc()
        {
            ifstream file;

            file.open("account.txt", ios::in|ios::binary);

            if(!file)
            {
                cout << "Error!! File not found!!";
            }

            else
            {
                file.read((char*)this, sizeof(*this));
                Account::show_header();

                while(!file.eof())
                {
                    Account::show_acc();
                    file.read((char*)this, sizeof(*this));
                }
            }

            file.close();
        }

        void delete_acc()
        {
            ifstream ifile;
            ofstream ofile;
            int num;
            char ch;
            ifile.open("account.txt", ios::in | ios::binary);
            ofile.open("temp.txt", ios::out | ios::app | ios::binary);
            cout << "Enter Account Number to delete: ";
            cin >> num;
            if (!ifile)
            {
                cout << "File not found" << endl;
            }
            else
            {
                ifile.read((char*)this, sizeof(*this));
                while(!ifile.eof())
                {
                    if(acc_num == num)
                    {
                        cout << "Account you want to delete is:" << endl;
                        show_header();
                        show_acc();
                        cout << "\nAre you sure you want to delete this record(y/n): ";
                        fflush(stdin);
                        cin >> ch;
                        if (ch == 'n')
                        {
                            ofile.write((char*)this, sizeof(*this));
                            ifile.read((char*)this, sizeof(*this));
                        }
                        else
                        {
                            ifile.read((char*)this, sizeof(*this));
                            if(ifile.eof())
                                break;

                        }

                    }
                    ofile.write((char*)this, sizeof(*this));
                    ifile.read((char*)this, sizeof(*this));
                }

                ifile.close();
                ofile.close();

                system("erase account.txt");
                system("rename temp.txt account.txt");
            }
        }





};


class Saving : public Account
{
    protected:
        bool status = true;
    public:
        Saving()
        {

        }

        bool get_status()
        {
            if(balance < 25)
                return false;

            else
                return true;
        }

        void makeDeposit(float d)
        {
            search_acc();
            status = get_status();
            cout << "Enter the amount of deposit: ";
            cin >> d;
            Account::makeDeposit(d);

            if(status == false)
            {
                if(balance > 25)
                {
                    status = true;
                }
            }
        }



        void makeWithdrawal(float w)
        {
            search_acc();
            status = get_status();
            if (status == false)
            {
                cout << "Insufficient Fund for transaction!\nAccount is in active." << endl;
            }
            else
            {
                cout << "Enter the amount of withdrawal: ";
                cin >> w;
                Account :: makeWithdrawal(w);
            }

            status = get_status();
        }



        void monthlyProc()
        {
            search_acc();
            status = get_status();

            if(num_withdraw > 4)
            {
                for(int i = 5; i <= num_withdraw; i++)
                {
                    ser_charge = ser_charge + 1;
                }
                status = get_status();
            }

            Account::monthlyProc();
            status = get_status();
        }



};


class Checking : public Account
{
    public:
        Checking()
        {

        }
        void makeDepost(float d)
        {
            search_acc();
            cout << "Enter the amount of deposit: ";
            cin >> d;
            Account::makeDeposit(d);

        }

        void makeWithdrawal(float w)
        {
            search_acc();
            cout << "Enter the amount of withdrawal: ";
            cin >> w;
            if(balance < w)
            {
                balance = balance - 15;
                Account::makeWithdrawal(w);
            }

            else
            {
                Account::makeWithdrawal(w);
            }

        }

        void monthlyProc()
        {
            search_acc();
            ser_charge = 5.0;
            for(int i = 0; i < num_withdraw; i++)
            {
                ser_charge = ser_charge + 0.10;
            }
            Account::monthlyProc();


        }
};


int menu()
{

}

int main()
{
    Saving s;
    Account *a;
    Account *b;
    Account i;
    Checking c;
    b = &c;
    a = &s;
    //a->view_acc();
    //a->makeDeposit();
    //a->view_acc();
    //a->open_acc();
    //b->monthlyProc();
    //a->makeDeposit();
    //a->monthlyProc();
    b->view_acc();
    return 0;
}
