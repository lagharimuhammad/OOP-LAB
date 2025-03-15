#include <iostream>
#include <string>

using namespace std;

class Item 
{
public:
    string item_name;
    double item_price;
    Item(string n, double p) : item_name(n), item_price(p) {}
};

class Menu 
{
private:
    Item* items[100];
    int counter;
public:
    Menu() : counter(0) {}
    void add_item(string item_name, double item_price) 
    {
        if (counter < 100) 
        {
            items[counter++] = new Item(item_name, item_price);
        }
    }
    void remove_item(string item_name) 
    {
        for (int i = 0; i < counter; i++) 
        {
            if (items[i]->item_name == item_name)

            {
                delete items[i];
                for (int j = i; j < counter -1; j++) 
                {
                    items[j] = items[j + 1];
                }
                counter--;
                break;
            }
        }
    }
    void display() 
    {
    	cout << "---MENU---" << endl;
        for (int i = 0; i < counter; i++) 
        {
            cout << items[i]->item_name << " - rs" << items[i]->item_price << endl;

        }
    }
};

class Payment 
{
public:
    double amt;
    Payment(double amt) : amt(amt) {}
    
    void display_payment() 
    { 
        cout << endl << "total: " << amt << endl;
    }
};

class Order {
private:
    Item* order_dish[10];
    int counter;
    Payment* pay;
public:
    Order() : counter(0), pay(NULL) {}

    void add_Item(Item* item) 
    {
        if (counter < 10) 
        {
            order_dish[counter++] = item;
        }
    }
    void place_order() 
    {
        double total = 0;
        for (int i = 0; i < counter; i++) 
        {
            total += order_dish[i]->item_price;
        }
        pay = new Payment(total);
    }
    void display_order() 
    {
    	cout << "order: " << endl;
        for (int i = 0; i < counter; i++) 
        {
            cout << i+1 << "." << order_dish[i]->item_name << " - rs" << order_dish[i]->item_price << endl;
        }
        if (pay) 
        {
            pay->display_payment();
        }
    }
};

int main() 
{
    Menu menu;
    menu.add_item("Burger", 200);
    menu.add_item("Wrap", 150);
    menu.display();
    
    Order order;
    order.add_Item(new Item("burger", 200));
    order.add_Item(new Item("burger", 200));
    order.place_order();
    order.display_order();
    return 0;
}
