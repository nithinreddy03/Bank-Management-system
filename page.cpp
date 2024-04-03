#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNum;
    double balance;

public:
    BankAccount(string n, int ac, double bal)
    {
        name = n;
        accountNum = ac;
        balance = bal;
    }

    string getName()
    {
        return name;
    }

    int getAccountNum()
    {
        return accountNum;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "\t\tDeposit of " << amount << " successfully completed." << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "\t\tWithdrawal of " << amount << " successfully completed." << endl;
        }
        else
        {
            cout << "\t\tInsufficient balance." << endl;
        }
    }
};

class BankManagement
{
private:
    vector<BankAccount> accounts;

public:
    void addAccount(string name, int accountNum, double balance)
    {
        accounts.push_back(BankAccount(name, accountNum, balance));
        cout << "\t\tAccount created successfully." << endl;
    }

    void showAllAccounts()
    {
        if (accounts.empty())
        {
            cout << "\t\tNo accounts available." << endl;
            return;
        }
        cout << "\t\tAll Account Holders" << endl;
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "Name: " << accounts[i].getName() << ", Account Number: " << accounts[i].getAccountNum() << ", Balance: " << accounts[i].getBalance() << endl;
        }
    }

    void searchAccount(int accountNum)
    {
        bool found = false;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNum() == accountNum)
            {
                cout << "\t\tAccount Holder" << endl;
                cout << "Name: " << accounts[i].getName() << ", Account Number: " << accounts[i].getAccountNum() << ", Balance: " << accounts[i].getBalance() << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\t\tAccount not found." << endl;
        }
    }

    BankAccount *findAccount(int accountNum)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNum() == accountNum)
            {
                return &accounts[i];
            }
        }
        return nullptr; // Return nullptr if account not found
    }
};

int main()
{
    BankManagement bank;
    int choice, accountNum;
    char op;
    double amount;
    string name;
    BankAccount *account;

    do
    {
        system("cls");
        cout << "\t\t::Bank Management System" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "\t\t1. Create New Account" << endl;
        cout << "\t\t2. Show All Accounts" << endl;
        cout << "\t\t3. Search Account" << endl;
        cout << "\t\t4. Deposit Money" << endl;
        cout << "\t\t5. Withdraw Money" << endl;
        cout << "\t\t6. Balance Inquiry" << endl;
        cout << "\t\t7. Exit" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\tEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\t\tEnter Name: ";
            cin >> name;
            cout << "\t\tEnter Account Number: ";
            cin >> accountNum;
            cout << "\t\tEnter Initial Balance: ";
            cin >> amount;
            bank.addAccount(name, accountNum, amount);
            break;
        case 2:
            bank.showAllAccounts();
            break;
        case 3:
            cout << "\t\tEnter Account Number: ";
            cin >> accountNum;
            bank.searchAccount(accountNum);
            break;
        case 4:
            cout << "\t\tEnter Account Number to Deposit Money: ";
            cin >> accountNum;
            account = bank.findAccount(accountNum);
            if (account != nullptr)
            {
                cout << "\t\tEnter Amount to Deposit: ";
                cin >> amount;
                account->deposit(amount);
            }
            else
            {
                cout << "\t\tAccount not found." << endl;
            }
            break;
        case 5:
            cout << "\t\tEnter Account Number to Withdraw Money: ";
            cin >> accountNum;
            account = bank.findAccount(accountNum);
            if (account != nullptr)
            {
                cout << "\t\tEnter Amount to Withdraw: ";
                cin >> amount;
                account->withdraw(amount);
            }
            else
            {
                cout << "\t\tAccount not found." << endl;
            }
            break;
        case 6:
            cout << "\t\tEnter Account Number for Balance Inquiry: ";
            cin >> accountNum;
            account = bank.findAccount(accountNum);
            if (account != nullptr)
            {
                cout << "\t\tBalance: " << account->getBalance() << endl;
            }
            else
            {
                cout << "\t\tAccount not found." << endl;
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "\t\tInvalid choice. Please enter a valid option." << endl;
        }

        cout << "\t\tDo You Want to Continue or Exit [Yes/No]? ";
        cin >> op;

    } while (op == 'y' || op == 'Y');

    return 0;
}
