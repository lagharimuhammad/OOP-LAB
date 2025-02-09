#include <iostream>
#include <string>
using namespace std;

struct Book 
{
    string title;
    string author;
    int publication_year;
    string genre;
};

void add(Book book[], int &count);
void display(const Book book[], int count);
void update(Book book[], int count);
void search(const Book book[], int count);

int main() 
{
    Book book[100];
    int count = 0;
    int choice;

    do {
        cout << "1. Add Book";
        cout << "2. Display Book";
        cout << "3. Update Book";
        cout << "4. Search Book";
        cout << "5. Exit";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                add(book, count);
                break;
            case 2:
                display(book, count);
                break;
            case 3:
                update(book, count);
                break;
            case 4:
                search(book, count);
                break;
            case 5:
                break;
            default:
                cout << "invalid choice";
        }
    } while (choice != 5);

    return 0;
}

void add(Book book[], int &count) 
{
    if (count >= 100) 
    {
        cout << "library is full";
        return;
    }

    cout << "enter title: ";
    getline(cin, book[count].title);

    cout << "enter author: ";
    getline(cin, book[count].author);

    cout << "enter publication year: ";
    cin >> book[count].publication_year;

    cout << "enter genre: ";
    getline(cin, book[count].genre);

    count++;
    cout << "cook added ";
}

void display(const Book book[], int count) 
{
    if (count == 0) 
    {
        cout << "no book";
        return;
    }
    for (int i = 0; i < count; i++) 
    {
        cout << "book " << i + 1 << endl;
        cout << "title: " << book[i].title << endl;
        cout << "author: " << book[i].author << endl;
        cout << "publication Year: " << book[i].publication_year << endl;
    }
}

void update(Book book[], int count) 
{
    string name_to_search;

    cout << "enter the title of the book to update: ";
    getline(cin, name_to_search);

    for (int i = 0; i < count; i++) 
    {
        if (book[i].title == name_to_search) 
        {
            cout << "new title: ";
            getline(cin, book[i].title);
            cout << "new author: ";
            getline(cin, book[i].author);
            cout << "new publication year: ";
            cin >> book[i].publication_year;
            cout << "new genre: ";
            getline(cin, book[i].genre);
            return;
        }
    }
    cout << "not found.\n";
}

void search(const Book book[], int count) 
{
    string word;
    cout << "enter title or author to search: ";
    getline(cin, word);

    bool flag = false;
    for (int i = 0; i < count; i++) {
        if (book[i].title == word || book[i].author == word) {
            cout << "title: " << book[i].title << "\n";
            cout << "auuthor: " << book[i].author << "\n";
            cout << "publication Year: " << book[i].publication_year << "\n";
            cout << "genre: " << book[i].genre << "\n";
            flag = true;
        }
    }
    if (!flag) {
        cout << "No matching book found.\n";
    }
}

