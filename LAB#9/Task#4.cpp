#include <iostream>
using namespace std;
class PaymentMethod
{
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod
{
private:
    string cardNo;

public:
    CreditCard(string n) : cardNo(n) {}
    void processPayment(double amount) override
    {
        if (cardNo == "00000-00000-00000")
            cout << "Amount processed:" << amount << endl;
        else
            cout << "Failure!, Enter correct card number" << endl;
    }
};

class DigitalWallet : public PaymentMethod
{
private:
    double balance;

public:
    DigitalWallet(double b) : balance(b) {}
    void processPayment(double amount) override
    {
        if (amount < balance){
            balance -= amount;
            cout << amount << " Deducted from account" << endl
                 << "Remaining balance: " << balance << endl;
        }
        else
            cout << "Insufficient Balance" << endl;
    }
};

int main()
{
    CreditCard cc("00000-00000-00000");
    cc.processPayment(2500);
    DigitalWallet dw(5000);
    dw.processPayment(2500);

    return 0;
}