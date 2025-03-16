#include <iostream>
#include <string>
using namespace std;

class Book 
{
protected:
    string title;
    string author;
    string publisher;
public:
    Book(string title, string author, string publisher) : title(title), author(author), publisher(publisher) {}
    void display() 
    {
        cout << "title: " << title << endl << "author: " << author<< endl << "publisher: " << publisher << endl;
    }
};

class FictionBook : public Book 
{
private:
    string genre;
    string protagonist;
public:
    FictionBook(string title, string author, string publisher, string genre, string protagonist) : Book(title, author, publisher), genre(genre), protagonist(protagonist) {}

    void display() 
    {
        Book::display();
        cout << "genre: " << genre << endl << "protagonist: " << protagonist << endl;
    }
};

int main() 
{
    FictionBook book("One Piece", "Eiichiro Oda", "Toei", "Adventure, Action", "Monkey D. Luffy");
    book.display();
    return 0;
}
