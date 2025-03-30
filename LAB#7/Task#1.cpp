#include <iostream>
using namespace std;

class Account {
public:
    int acc_num;
    double balance;
    string acc_holder;
    string acc_type;

    Account(int an, double b, string ah, string at) : acc_num(an), balance(b), acc_holder(ah), acc_type(at) {}
    
    virtual void deposit(double amt) 
    {
        balance += amt;
    }
    
    virtual bool withdraw(double amt) 
    {
        if (amt > balance) 
        {
            cout << "not enough balance" << endl;
            return false;
        }
        balance -= amt;
        return true;
    }
    
    virtual void calc_int() = 0;
    virtual void print_statement() = 0;
    
    void display_info() 
    {
        cout << "account number: " << acc_num << endl << "account holder: " << acc_holder << endl << "balance: " << balance << endl << "account type: " << acc_type << endl;
    }
};

class SavingsAccount : public Account {
public:
    double i_rate;
    double min_bal;
    SavingsAccount(int an, double b, string ah, double r, double m) : Account(an, b, ah, "Savings"), i_rate(r), min_bal(m) {}
    void calc_int() override 
    {
        balance += balance * (i_rate / 100);
    }
    bool withdraw(double amt) override 
    {
        if (balance - amt < min_bal) {
            cout << "can't withdraw" << endl;
            return false;
        }
        return Account::withdraw(amt);
    }
    void print_statement() override 
    {
        cout << "savings account: " << acc_holder << endl;
        cout << "balance: " << balance << endl;
    }
};

class CheckingAccount : public Account 
{
public:
    CheckingAccount(int accNum, double bal, string holder) : Account(accNum, bal, holder, "Checking") {}
    
    void calc_int() override {}
    
    void print_statement() override 
    {
        cout << "checking account: " << acc_holder << endl;
        cout << "balance: " << balance << endl;
    }
};

class FixedDepositAccount : public Account 
{
public:
    double fixed_ir;
    int maturity;

    FixedDepositAccount(int accNum, double bal, string holder, double rate, int period) : Account(accNum, bal, holder, "Fixed Deposit"), fixed_ir(rate), maturity(period) {}
    
    void calc_int() override 
    {
        balance += balance * (fixed_ir / 100) * maturity;
    }
    
    bool withdraw(double amt) override 
    {
        cout << "cannot withdraw" << endl;
        return false;
    }
    
    void print_statement() override 
    {
        cout << "fixed deposit account: " << acc_holder << endl;
        cout << "balance: " << balance << endl;
    }
};

int main() 
{
    SavingsAccount savings(240006, 50000, "Baqar", 2.5, 500);
    savings.deposit(20000);
    savings.withdraw(8000);
    savings.calc_int();
    savings.print_statement();
    return 0;
}