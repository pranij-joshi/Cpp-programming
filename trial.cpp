#include <iostream>
#include <fstream>


using namespace std;

int main()

{

   ofstream ofile;

   ofile.open ("find.txt");

   ofile << "letsfindcourse" << endl;

   cout << "Data written to file" << endl;

   ofile.close();

   return 0;

}
