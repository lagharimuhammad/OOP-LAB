#include <iostream>
#include <string>
using namespace std;

class Exception
{
    string message;
public:
    Exception(const string &msg) : message(msg) {}
    string what() const 
    { 
        return message; 
    }
};

class BankAccount
{
    int balance;
public:
    BankAccount(int bal) : balance(bal) {}
    int getBalance() const
    {
        return balance;
    }
    void withdraw(int amount)
    {
        if (amount > balance)
        {
            throw Exception("not enough cash!");
        }
        balance -= amount;
        cout << "mission successful! new balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account(50000);
    cout << "Current Balance: Rs " << account.getBalance() << endl;
    cout << "Enter withdrawal amount: ";
    int amount;
    cin >> amount;
    try
    {
        account.withdraw(amount);
    }
    catch (const Exception &e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}