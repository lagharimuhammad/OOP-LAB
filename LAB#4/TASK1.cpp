#include <iostream>
using namespace std;

class Book
{
    public:
    string title; 
    string author;
    int price;

    Book()
    {
        title= "Untitled";
        author= "Anonymous";
        price= 0;
    }

    Book(string title, string author, int price)
    {
        this->author=author;
        this->title=title;
        this->price=price;
    }

    Book(Book& obj)
    {
        title = obj.title;
        author= obj.author;
        price = obj.price;
    }

    Book(string title)
    {
        title = this->title;
        author = "unknown";
        price = 0;
    }

    void display()
    {
        cout << title << endl;
        cout << author << endl;
        cout << price << endl;
    }
};

int main()
{
    Book b1;
    Book b2("Road that leads to heaven", "james", 1500);
    b2.display();
    Book b3("rich father poor father", "me", 2000);
    b3.display();
    Book b4("finite life");
    b4.display();
    Book b5;
    b5 = b3;
    b5.display();
}
