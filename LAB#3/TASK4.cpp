#include <iostream>
#include <string>
using namespace std;

class StationeryShop 
{
private:
    string things[100];  
    double costs[100]; 
    int count;

public:
    StationeryShop(): count(0) {}
    void add() 
    {
        if (count < 100) 
            { 
                cout << "input item name: ";
                cin >> things[count];
                cout << "input item price: ";
                cin >> costs[count];
                count++;
            } 
        else 
            {
                cout << "no free space";
            }
    }
    void display() 
    {
        if (count == 0) 
        {
            cout << "nothing here.";
            return;
        }
        for (int i = 0; i < count; i++) 
            {
                cout << things[i] << "- rs" << costs[i] << endl;
            }
    }

    void edit_cost() 
    {
        int i;
        cout << "input object number to edit cost: ";
        cin >> i;
        if (i > 0 && i <= count) 
            {
                cout << "input new price: ";
                cin >> costs[i - 1];
            } 
        else 
            {
                cout << "error 404!";
            }
    }

    void receipt() 
    {
        if (count == 0)
        {
            cout << "amount: rs 00";
            return;
        }

        double total= 0;
        int quantity;

        for (int i = 0; i < count; i++) 
        {
            cout << things[i] << " quantity: ";
            cin >> quantity;
            if (quantity > 0) 
            {
                double total_cost = costs[i] * quantity;
                total += total_cost;
                cout << "total for " << things[i] << ": " << total_cost <<endl;
            }
        }
        cout << "amount: rs " << total <<endl;
    }
};

int main() 
{
    StationeryShop shop;
    int option;

    do 
    {
        cout << "1 add\n2 display\n3 edit\n4 receipt\n5 exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) 
        {
            case 1: 
            shop.add(); 
            break;

            case 2: 
            shop.display(); 
            break;

            case 3: 
            shop.edit_cost(); 
            break;

            case 4: 
            shop.receipt(); 
            break;

            case 5: 
            break;

            default: 
            cout << "invalid option";
        }
    } 
    while (option != 5);

    return 0;
}

