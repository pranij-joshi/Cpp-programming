#include<iostream>

using namespace std;

const int monthDays[12] = {31, 28, 31, 30, 31, 30,

                          31, 31, 30, 31, 30, 31};



const string monthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};



bool checkYear(int year)

{

   // If a year is multiple of 400,

   // then it is a leap year

   if (year % 400 == 0)

       return true;



   // Else If a year is muliplt of 100,

   // then it is not a leap year

   if (year % 100 == 0)

       return false;



   // Else If a year is muliplt of 4,

   // then it is a leap year

   if (year % 4 == 0)

       return true;

   return false;

}



class Date{

  public:

     int month;

     int date;

     int year;

     Date()

     {

        month = 0;

        date = 0;

        year = 0;

     }

     void setDate()

     {

        cout<<"Enter Year : ";

        cin>>year;

        while(true)

        {

           cout<<"Enter Month : ";

           cin>>month;

           if(month>=1 && month<=12)

           {

              break;

           }

           else

           {

              cout<<"Month should be between 1 and 12\n";

           }

        }

        while(true)

        {

           cout<<"Enter Date : ";

           cin>>date;

           if(date>=1 && date<= monthDays[month-1])

           {

              break;

           }

           else if(date>=1 && checkYear(year) && month==2 && date<=monthDays[month-1]+1)

           {

              break;

           }

           else

           {

              cout<<"Day not valid!!\n";

           }

        }

     }

     void operator++()

     {

        date++;

        if(date>monthDays[month-1] && checkYear(year) && month==2)

        {

           ;

        }

        else if(date>monthDays[month-1])

        {

           date = 1;

           month++;

           if(month>12)

           {

              date = 1;

              month = 1;

              year++;

           }

        }

     }



     void operator--()

     {

        date--;

        if(date<1)

        {

           month--;

           date = monthDays[month-1];

           if(month<1)

           {

              month = 12;

              year--;

           }

        }

     }



     int operator-(Date d)

     {

        long int n1 = year*365 + date;



         // Add days for months in given date

         for (int i=0; i<month - 1; i++)

             n1 += monthDays[i];



         // Since every leap year is of 366 days,

         // Add a day for every leap year

         int years = year;

         if (month <= 2)

              years--;



         n1 += years / 4 - years / 100 + years / 400;



         // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'



         long int n2 = d.year*365 + d.date;

         for (int i=0; i<d.month - 1; i++)

             n2 += monthDays[i];

         years = d.year;

         if(d.month<=2)

           year--;

         n2 += years / 4 - years / 100 + years / 400;



         // return difference between two counts

         return (n2 - n1);

     }



     void print_ddmmyy()

     {

        cout<<date<<"/"<<month<<"/"<<year<<"\n";

     }



     void printmonthddyyyy()

     {

        cout<<monthNames[month-1]<<" "<<date<<","<<year<<"\n";

     }



     void printddmonthyyyy()

     {

        cout<<date<<" "<<monthNames[month-1]<<" "<<year<<"\n";

     }

};

int main()

{

  Date d1;

  Date d2;

  int days;

  d1.setDate();

  cout<<endl<<endl;

  system("cls");

  d1.print_ddmmyy();

  d1.printddmonthyyyy();

  d1.printmonthddyyyy();

  int choice;

  while(true)

  {

     cout<<"1 to increament date \n2 to decreament date \n3 to get days between to date\nEnter choice : ";

     cin>>choice;

     system("cls");

     switch(choice)

     {

        case 1: --d1;

           d1.print_ddmmyy();

           d1.printddmonthyyyy();

           d1.printmonthddyyyy();

           break;

        case 2: ++d1;

           d1.print_ddmmyy();

           d1.printddmonthyyyy();

           d1.printmonthddyyyy();

           break;

        case 3:

           cout<<"Enter second date to find difference : \n";

           d2.setDate();

           days = d1-d2;

           cout<<"Difference is "<<days<<"\n";

           d1.print_ddmmyy();

           d1.printddmonthyyyy();

           d1.printmonthddyyyy();

           break;

        default:

           {

           cout<<"Incorrect Choice \n";

           d1.print_ddmmyy();

           d1.printddmonthyyyy();

           d1.printmonthddyyyy();

           break;

        }

     }

  }

}
