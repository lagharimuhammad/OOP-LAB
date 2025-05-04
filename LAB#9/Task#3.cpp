#include <iostream>
using namespace std;
#include "Task#3.h"
Book::Book(const string &title, const string &author, const string &ISBN) : title(title), author(author), ISBN(ISBN) {}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getISBN() const
{
    return ISBN;
}
int main()
{
    Book book1("2001", "C++ - A beginer's guide to coding", "123-01234451");
    cout << "Book Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "ISBN: " << book1.getISBN() << endl;

    return 0;
}