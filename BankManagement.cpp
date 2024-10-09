#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNum;
    double balance;

public:
    BankAccount(string n, int ac, double bal) : name(n), accountNum(ac), balance(bal) {}

    string getName() const {
        return name;
    }

    int getAccountNum() const {
        return accountNum;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "\t\tWithdraw Successful!" << endl;
        } else {
            cout << "\t\tInsufficient Balance." << endl;
        }
    }
};

class BankManagement {
private:
    vector<BankAccount> accounts;

public:
    void addAccount(const string& name, int accountNum, double balance) {
        accounts.push_back(BankAccount(name, accountNum, balance));
    }

    void showAllAccounts() const {
        cout << "\t\tAll Account Holders:" << endl;
        for (const auto& account : accounts) {
            cout << "Name: " << account.getName() << ", Account Number: " << account.getAccountNum() << ", Balance: " << account.getBalance() << endl;
        }
    }

    BankAccount* findAccount(int accountNum) {
        for (auto& account : accounts) {
            if (account.getAccountNum() == accountNum) {
                return &account;
            }
        }
        return nullptr;
    }
};

int main() {
    BankManagement bank;
    int choice;
    char op;

    do {
        cout << "\t\t::Bank Management System" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "\t\t1. Create New Account" << endl;
        cout << "\t\t2. Show All Accounts" << endl;
        cout << "\t\t3. Deposit Money" << endl;
        cout << "\t\t4. Withdraw Money" << endl;
        cout << "\t\t5. Exit" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\tEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int accountNum;
            double balance;
            cout << "\t\tEnter Name: ";
            cin >> name;
            cout << "\t\tEnter Account Number: ";
            cin >> accountNum;
            cout << "\t\tEnter Initial Balance: ";
            cin >> balance;
            bank.addAccount(name, accountNum, balance);
            cout << "\t\tAccount Created Successfully." << endl;
            break;
        }
        case 2: {
            bank.showAllAccounts();
            break;
        }
        case 3: {
            int accountNum;
            double amount;
            cout << "\t\tEnter Account Number to Deposit Money: ";
            cin >> accountNum;
            BankAccount* account = bank.findAccount(accountNum);
            if (account) {
                cout << "\t\tEnter Amount to Deposit: ";
                cin >> amount;
                account->deposit(amount);
                cout << "\t\t" << amount << " Deposited Successfully." << endl;
            } else {
                cout << "\t\tAccount Not Found." << endl;
            }
            break;
        }
        case 4: {
            int accountNum;
            double amount;
            cout << "\t\tEnter Account Number to Withdraw Money: ";
            cin >> accountNum;
            BankAccount* account = bank.findAccount(accountNum);
            if (account) {
                cout << "\t\tEnter Amount to Withdraw: ";
                cin >> amount;
                account->withdraw(amount);
            } else {
                cout << "\t\tAccount Not Found." << endl;
            }
            break;
        }
        case 5: {
            exit(0);
        }
        default:
            cout << "\t\tInvalid Choice." << endl;
        }

        cout << "\t\tDo You Want to Continue? (Y/N): ";
        cin >> op;

    } while (op == 'Y' || op == 'y');

    return 0;
}
