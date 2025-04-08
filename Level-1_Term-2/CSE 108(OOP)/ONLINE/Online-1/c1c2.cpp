#include <iostream>
#include <cstring>

using namespace std;

class BankAccount
{
    double balance;
    char *acno;
    char *name;

public:
    BankAccount()
    {
        balance = 0;
        acno = NULL;
        name = NULL;
    }
    ~BankAccount()
    {
        delete[] acno;
        delete[] name;
    }
    void set(char *a, char *n)
    {
        acno = new char[strlen(a) + 1];
        name = new char[strlen(n) + 1];
        strcpy(acno,a);
        strcpy(name,n);
    }
    double getbalance()
    {
        return balance;
    }
    char *getacno()
    {
        return acno;
    }
    char *getname()
    {
        return name;
    }
    void deposit(double t)
    {
        balance += t;
    }
    void withdraw(double t)
    {
        balance -= t;
    }
    void display()
    {
        cout << "Account number: " << getacno() << endl;
        cout << "Name: " << getname() << endl;
        cout << "Balance: " << getbalance() << endl;
    }
};
class Bank
{
public:
    BankAccount array[100];
    int accs = 0;

    void addAccount(char *p, char *q)
    {
        array[accs].set(p, q);
        accs++;
    }
    void deposit(char *p, double t)
    {
        for (int i = 0; i < accs; i++)
        {
            if (strcmp(array[i].getacno(), p) == 0)
            {
                array[i].deposit(t);
                break;
            }
        }
    }
    void withdraw(char *p, double t)
    {
        for (int i = 0; i < accs; i++)
        {
            if (strcmp(array[i].getacno(), p) == 0)
            {
                array[i].withdraw(t);
                break;
            }
        }
    }
    void displayAllAccounts()
    {
        for (int i = 0; i < accs; i++)
        {
            cout<<i+1<<". "<<endl;
            array[i].display();
        }
    }
    void removeAccount(char *p)
    {
        int i = 0;
        while (1)
        {
            if (strcmp(array[i].getacno(), p) == 0)
            {
                break;
            }
            i++;
        }
        for(int j = i;j<accs; j++)
        {
            array[i] = array[i+1];
        }
        accs--;
    }
};

int main()
{
    Bank bank;
    // Add new bank accounts
    bank.addAccount("12345", "John Doe");
    bank.addAccount("67890", "Jane Smith");
    // Perform transactions
    bank.deposit("12345", 1000.0);
    bank.deposit("67890", 500.0);
    // Display account details
    bank.displayAllAccounts();
    // Perform transactions
    bank.withdraw("12345", 200.0);
    bank.withdraw("67890", 500.0);
    // Display account details after transaction
    bank.displayAllAccounts();
    // Remove an account
    bank.removeAccount("67890");
    // Display account details after removal
    bank.displayAllAccounts();
    // Add more accounts
    bank.addAccount("24680", "Sarah Adams");
    bank.addAccount("13579", "Michael Lee");
    // Perform transactions on the newly added accounts
    bank.deposit("24680", 1500.0);
    bank.deposit("13579", 200.0);
    bank.withdraw("13579", 100.0);
    bank.withdraw("24680", 300.0);
    // Display all accounts
    bank.displayAllAccounts();
    return 0;
}