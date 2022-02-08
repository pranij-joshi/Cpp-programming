#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

class Account
{
    float Balance;
    int NumOfDeposits ;
    int NumOfWithdrawal ;
    float interest;
    float charge;
    int accountNum;
public:
    Account()
    {

    }
    int allotAccnum()
    {
        ifstream fin;
        Account temp;
        int num = 0;
        fin.open("Bank.txt",ios::in | ios::binary);
        if (!fin)
        {
            return(num + 1);
        }
        else
        {
            fin.read((char*)&temp, sizeof(temp));
            while(!fin.eof())
            {
                num = temp.accountNum;
                fin.read((char*)&temp, sizeof(temp));
            }
            num++;
            return(num);
        }
    }
    Account(float amount, float _interest)
    {
        Balance = amount;
        interest = _interest;
    }
    void setBalance(float amount)
    {
        Balance = amount;
    }
    int getBalance()
    {
        return Balance;
    }
    int getWithdrawal()
    {
        return NumOfWithdrawal;
    }
    void setCharges(int _chg)
    {
        charge = charge + _chg;
    }
    void setInterest(float num)
    {
        interest = num;
    }
    void getAcc()
    {
        cout << "Enter Balance:";
        cin >> Balance;
        cout << "Enter Interest: ";
        cin >> interest;
        charge = 0;
        NumOfDeposits = 0;
        NumOfWithdrawal = 0;
        accountNum = allotAccnum();
    }
    virtual void makeDeposit()
    {
        int num, r = 0;
        fstream file;
        file.open("Bank.txt", ios::in | ios::out | ios::ate | ios::binary);
        cout << "Enter Account No.: ";
        cin >> num;
        file.seekg(0);

        if (!file.eof())
        {
            cout << "File not found" << endl;
        }
        else
        {
            file.read((char*)this, sizeof(*this));
            while (!file.eof())
            {
                r++;
                if (accountNum == num)
                {
                    int amount;
                    cout << "Enter amount you want to deposit";
                    cin >> amount;
                    fflush(stdin);
                    Balance = Balance + amount;
                    NumOfDeposits++;
                    file.seekp((r-1)*sizeof(Account), ios::beg);
                    file.write((char*)this,sizeof(*this));
                    break;
                }
            }
            file.read((char*)this, sizeof(*this));
        }
        file.close();
    }
    virtual void makeWithdrawal()
    {
        int num, r = 0;
        fstream file;
        file.open("Bank.txt", ios::in | ios::out | ios::ate | ios::binary);
        cout << "Enter Account No.: ";
        cin >> num;
        file.seekg(0);
        if (!file)
        {
            cout << "File not found" << endl;
        }
        else
        {
            file.read((char*)this, sizeof(*this));
            while (!file.eof())
            {
                r++;
                if (accountNum == num)
                {
                    int amount;
                    cout << "Enter amount you want to deposit";
                    cin >> amount;
                    fflush(stdin);
                    Balance = Balance - amount;
                    NumOfWithdrawal++;
                    file.seekp((r-1)*sizeof(Account), ios::beg);
                    file.write((char*)this,sizeof(*this));
                    break;
                }
                file.read((char*)this, sizeof(*this));
            }
        }
        file.close();
    }
    virtual void calcInt()
    {
        int monthlyInterest;
        monthlyInterest = interest / 12;
        monthlyInterest = Balance * monthlyInterest;
        Balance = Balance + monthlyInterest;
    }
    virtual void monthlyProc()
    {
        int num, r = 0;
        fstream file;
        file.open("Bank.txt", ios::in | ios::out | ios::ate | ios::binary);
        cout << "Enter Account No.: ";
        cin >> num;
        file.seekg(0);
        if (!file.eof())
        {
            cout << "File not found" << endl;
        }
        else
        {
            file.read((char*)this, sizeof(*this));
            while (!file.eof())
            {
                r++;
                if (accountNum == num)
                {
                    Balance = Balance - charge;
                    calcInt();
                    NumOfDeposits = 0;
                    NumOfWithdrawal = 0;
                    charge = 0;
                    file.seekp((r-1)*sizeof(Account), ios::beg);
                    file.write((char*)this,sizeof(*this));
                    break;
                }
            }
            file.read((char*)this, sizeof(*this));
        }
        file.close();
    }
    void searchAcc()
    {
        ifstream fin;
        int num;
        fin.open("Bank.txt", ios::in | ios::binary);
        cout << "Enter your Account Number: ";
        fflush(stdin);
        cin >> num;
        if (!fin)
        {
            cout << "File not found";
        }
        else{
            fin.read((char*)this ,sizeof(*this));
            while(!fin.eof())
            {
                if (this ->accountNum == num)
                {
                    showheader();
                    showAcc();
                    break;
                }
                fin.read((char*)this ,sizeof(*this));
            }
            if (fin.eof())
                cout << "\n Record not found";
        }
    }
    void addAcc()
    {
        ofstream file;
        file.open("Bank.txt", ios::out | ios::app | ios::binary);
        if(!file)
        {
            cout << "File not found";
        }
        else
        {
            file.write((char*)this,sizeof(*this));
        }
    }
    void showheader()
    {
        cout << left;
        cout << "\n" << setw(10) << "Account Number" << setw(10) << "Balance" << setw(10) << "Interest" << endl;
    }
    void showAcc()
    {
        cout << left;
        cout << endl <<setw(10) << accountNum << setw(15) << Balance << setw(10) <<  interest << endl;
    }
    void viewacc()
    {
        ifstream fin;
        fin.open("Bank.txt", ios::in | ios::binary);
        if(!fin)
        {
            cout << "FIle not found";
        }
        else
        {
            fin.read((char*)this,sizeof(*this));
            showheader();
            while(!fin.eof())
            {
                showAcc();
                fin.read((char*)this, sizeof(*this));
            }
        }
    }
    void deleteAcc()
    {
        ifstream fin;
        ofstream fout;
        int num;
        char x;
        fin.open("Bank.txt", ios::in | ios::binary);
        fout.open("temp.txt", ios::out | ios::app | ios::binary);
        cout << "Enter Account Number to delete";
        cin >> num;
        if (!fin)
        {
            cout << "File not found";
        }
        else
        {
            fin.read((char*)this, sizeof(*this));
            while(!fin.eof())
            {
                if(this -> accountNum == num)
                {
                    cout << "Account you want to delete is: \n\n";
                    showheader();
                    showAcc();
                    cout << "\nAre you sure you want to delete this record(y/n): ";
                    fflush(stdin);
                    cin >> x;
                    if (x=='n')
                        fout.write((char*)this, sizeof(*this));
                    else
                        fout.write((char*)this, sizeof(this));
                    fin.read((char*)this, sizeof(*this));
                }
                fin.close();
                fout.close();

            system("erase Bank.txt");
            system("rename temp.txt Bank.txt");
            }
        }
    }
};
class SavingAccount : public Account
{
    bool status = true;
public:
    SavingAccount()
    {
        int x = getBalance();
        if (x < 25)
        {
            status = false;
        }
        else
            status = true;
    }
    void makeWithdrawal(float amount)
    {
        if (status = false)
        {
            cout << "Insufficient Fund for transaction!" << endl;
        }
        else
        {
            Account :: makeWithdrawal();
        }
    }
    void makeDeposit(float amount)
    {
        if (status == false)
        {
            if (amount + getBalance() > 25)
            {
                status = true;
                Account :: makeDeposit();
            }
        }
        else
            Account :: makeDeposit();

    }
    void monthlyProc()
    {
        int num, net;
        num = getWithdrawal();
        if(num > 4)
        {
            net = num - 4;
            setCharges(net);
        }
        if (getBalance() < 25)
        {
            status = false;
        }
    }

};
class CheckingAccount : public Account
{
public:
    void makeWithdrawal(float amount)
    {
        if ((getBalance() - amount) < 0)
        {
            setCharges(15);
            cout << "Bank Balance Insufficient! Withdrawal not possible";
        }
        else
            Account :: makeWithdrawal();
    }
    void monthlyProc()
    {
        int _chg;
        _chg = 5 + (0.10 * getWithdrawal());
        setCharges(_chg);
        Account :: monthlyProc();
    }
};
int menu()
{
    cout << endl << "1. Add New Account: ";
    cout << endl << "2. View New Account: ";
    cout << endl << "3. Search New Account: ";
    cout << endl << "4. Make Deposit Account: ";
    cout << endl << "5. Make Withdrawal Account: ";
    cout << endl << "6. Terminate Account: ";
    cout << endl << "7. Exit";
    int ch;
    cin >> ch;
    return(ch);
}
int main()
{
    Account *A;
    int ch;
    SavingAccount s;
    A = &s;
    A->viewacc();
    A->makeDeposit();
    /*while(1)
    {
        ch = menu();
        switch(ch)
        {
        case 1:
            A.getAcc();
            A.addAcc();
            break;
        case 2:
            A.viewacc();
            break;
        case 3:
            A.searchAcc();
            break;
        case 4:
            A.makeDeposit();
            break;
        case 5:
            A.makeWithdrawal();
            break;
        case 6:
            A.deleteAcc();
            break;
        case 7:
            exit(0);
        }
    }*/
}
