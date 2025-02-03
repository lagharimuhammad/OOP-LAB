#include <iostream>
#include <string>
using namespace std;

struct Product 
{
    int ID;
    string naam;
    double cost;
    int quantity;
};

Product invent[100];
int Count = 0;

void add(int ID, string naam, double cost, int quantity) 
{
    invent[Count++] = {ID, naam, cost, quantity};
}

void display(int ID) 
{
    for (int i = 0; i < Count; i++) 
    {
        if (invent[i].id == id) 
        {
            cout << "product ID: " << invent[i].ID << "\n";
            cout << "name: " << invent[i].naam << "\n";
            cout << "price: $" << invent[i].cost << "\n";
            cout << "quantity: " << invent[i].quantity << "\n";
            return;
        }
    }
    cout << "not found!\n";
}

void update(int ID, string naam, double cost, int quantity) 
{
    for (int i = 0; i < productCount; i++) 
    {
        if (invent[i].id == id) 
        {
            invent[i].name = name;
            invent[i].price = price;
            invent[i].quantity = quantity;
            return;
        }
    }
    cout << "not found!\n";
}

void remove(int ID) 
{
    for (int i = 0; i < Count; i++) 
    {
        if (invent[i].id == id) 
        {
            for (int j = i; j < Count - 1; j++) 
            {
                invent[j] = invent[j + 1];
            }
           Count--;
            cout << "Product removed";
            return;
        }
    }
    cout << "not found!\n";
}

int main() 
{
    int option, ID, quantity;
    string naam;
    double cost;

    while (true) 
    {
        cout << "\n**Product Management System\n**";
        cout << "1. Add ";
        cout << "2. View ";
        cout << "3. Update ";
        cout << "4. Remove ";
        cout << "5. Exit;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) 
        {
            case 1:
                cout << "Enter ID, Name, Price, Quantity: ";
                cin >> ID;
                getline(cin, naam);
                cin >> cost
                cin >> cost >> quantity;
                addProduct(ID, naam, cost, quantity);
                break;
            case 2:
                cout << "Enter Product ID: ";
                cin >> ID;
                display(ID);
                break;
            case 3:
                cout << "Enter ID, New Name, New Price, New Quantity: ";
                cin >> ID;
                getline(cin, naam);
                cin >> price >> quantity;
                update(ID, naam, cost, quantity);
                break;
            case 4:
                cout << "Enter Product ID to remove: ";
                cin >> ID;
                remove(ID);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!";
        }
    }
}

