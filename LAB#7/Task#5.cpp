#include <iostream>
#include <string>
using namespace std;

class Media {
public:
    string title, release_date, id, publisher;
    bool check_out = false;
    Media(string t, string p_date, string id, string p) : title(t), release_date(p_date), id(id), publisher(p) {}

    virtual void displayInfo() 
    {
        cout << "title: " << title << endl << "publication date: "  << release_date << endl << "id: " << id << endl << "publisher: " << publisher << endl ;
    }

    void checkOut() 
    {
        if (check_out) 
            cout << "checked out already";
        else 
        {
            check_out = true;
            cout << "action done";
        }
    }
                                    
    void returnItem() 
    {
        if (!check_out) 
            cout << "item is in the library.";
        else 
        {
            check_out = false;
            cout << "returned successfully.";
        }
    }
};

class Book : public Media 
{
public:
    string author, ISBN;
    int num_pages;
    Book(string t, string p_date, string id, string pub, string a, string isbn, int pages) : Media(t, p_date, id, pub), author(a), ISBN(isbn), num_pages(pages) {}

    void displayInfo() override 
    {
        Media::displayInfo();
        cout << "author: " << author << endl << "ISBN: " << ISBN << endl << "Pages: " << num_pages << endl;
    }
};

class DVD : public Media 
{
public:
    string dector, rate;
    double time_period;
    DVD(string t, string p_date, string id, string pub, string d, double tp, string r) : Media(t, p_date, id, pub), dector(d), time_period(tp), rate(r) {}

    void displayInfo() override 
    {
        Media::displayInfo();
        cout << "dector: " << dector << endl << "time_period: " << time_period << endl << "rate: " << rate << endl;
    }
};

class CD : public Media 
{
public:
    string artist, genre;
    int num_tracks;
    CD(string t, string p_date, string id, string pub, string a, int tr, string g) : Media(t, p_date, id, pub), artist(a), num_tracks(tr), genre(g) {}

    void displayInfo() override 
    {
        Media::displayInfo();
        cout << "artist: " << artist << endl << "tracks: " << num_tracks << "genre: " << genre << endl;
    }
};

class Magazine : public Media 
{
public:
    int page_number;
    Magazine(string t, string p_date, string id, string pub, int pn) : Media(t, p_date, id, pub), page_number(pn) {}

    void displayInfo() override 
    {
        Media::displayInfo();
        cout << "page numbers: " << page_number << endl;
    }
};

class Library {
public:
    Media* list[100];
    int counter = 0;

    void add(Media* media) 
    {
        if (counter < 100) 
            list[counter++] = media;
        else 
            cout << "liibrary full";
    }

    void search(string title) 
    {
        for (int i = 0; i < counter; i++) 
        {
            if (list[i]->title == title) 
            {
                cout << "item found";
                return;
            }
        }
        cout << "item not found";
    }

    void search(int year) 
    {
        bool found = false;
        for (int i = 0; i < counter; i++) 
        {
            if (list[i]->release_date == to_string(year))
            {
                cout << "Item found:\n";
                list[i]->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "No items found for the year " << year << ".\n";
    }
};

int main() 
{
    Library l;
    Book b1("Rich Dad Poor Dad", "1997", "K0006", "Plata Publishing", "Robert T. Kiyosaki", "9781612680194", 336);
    l.add(&b1);  
    b1.displayInfo();
    return 0;
}