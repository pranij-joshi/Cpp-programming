#include <iostream>

using namespace std;

class Book
{
    protected:
        string title;
        string author;

    public:
        Book(string t = "", string a = "")
        {
            title = t;
            author = a;
        }

        void setTitle(string t)
        {
            title = t;
        }

        void setAuthor(string a)
        {
            author = a;
        }

        void displayBook()
        {
            cout << "Tile: " << title << endl;
            cout << "Author: " << author << endl;
        }

};

class Fiction : public Book
{
    private:
        int grade_level;

    public:
        Fiction(int l, string t, string a) : Book(t, a)
        {
            grade_level = l;
        }

        void displayFiction()
        {
            Book::displayBook();
            cout << "Numeric Grade Reading Level: " << grade_level << endl;
        }
};


class NonFiction : public Book
{
    private:
        int pages;

    public:
        NonFiction(int p, string t, string a) : Book(t, a)
        {
            pages = p;
        }

        void displayNonFiction()
        {
            Book::displayBook();
            cout << "Number of pages: " << pages << endl;
        }
};


int main()
{
    Book b("Starting out with C++", "Tony Gaddis");
    b.displayBook();

    cout << endl;

    Fiction f(7, "Harry Potter", "J.K. Rowling");
    f.displayFiction();

    cout << endl;

    NonFiction n(368, "The monk who sold his Ferrari", "Robin Sharma");
    n.displayNonFiction();

    return 0;
}
