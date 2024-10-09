#include <iostream>
#include <vector>
#include <cstdlib>  // For srand and rand (not used anymore)
#include <ctime>    // For time (not used anymore)
using namespace std;

// Class to manage account details and transactions
class Account {
    // Basic Variables declared
    int dogecoin, balance;
    int bitcoin;
    int deposit, withdraw;
    int total_equity = 100;  // Equity available for transactions
    int crypto_invest;       // Total investment in crypto
    int crypto_return;       // Total return from crypto
    int dogecoin_value;      // Value of one Dogecoin
    int bitcoin_value;       // Value of one Bitcoin

    // Vector to store transaction history
    vector<pair<string, int>> transactions;

public:
    // Constructor to initialize account details
    Account() {
        crypto_invest = 0;
        crypto_return = 0;
        total_equity = 100;
        balance = 50000;
        dogecoin = 0;
        bitcoin = 0;
        withdraw = 0;
        deposit = 0;
        dogecoin_value = 100;  // Set value for Dogecoin
        bitcoin_value = 500;   // Set value for Bitcoin
    }

    // Function to deposit cash into the account
    bool Deposit(int money) {
        deposit += money;  // Update deposit amount
        balance += money;  // Update account balance
        transactions.push_back({"Deposit:", money});  // Record the transaction
        return true;  // Indicate successful deposit
    }

    // Function to get account details
    void Get_account_information() {
        cout << "Money Details:\n";
        cout << "Bank Balance: " << balance << endl;
        cout << "Dogecoin: " << dogecoin << endl;
        cout << "Bitcoin: " << bitcoin << endl;
    }

    // Function to withdraw cash from the account
    bool Withdraw(int money) {
        if (money > balance) {  // Check if withdrawal amount is greater than balance
            return false;  // Withdrawal fails
        }

        withdraw += money;  // Update withdrawal amount
        balance -= money;  // Update account balance
        transactions.push_back({"Withdraw:", money});  // Record the transaction
        return true;  // Indicate successful withdrawal
    }

    // Function to buy cryptocurrency
    bool buy_crypto() {
        int option;  // Variable to select crypto type
        cout << "Want to purchase Dogecoin press 1, else for Bitcoin press 2\n";
        cin >> option;  // User selects cryptocurrency type

        if (total_equity > 0) {  // Check if there is equity available
            if (option == 1) {  // User chose Dogecoin
                if (balance >= dogecoin_value) {  // Check if balance is sufficient
                    dogecoin += 1;  // Increase Dogecoin count
                    balance -= dogecoin_value;  // Deduct Dogecoin value from balance
                    crypto_invest += dogecoin_value;  // Update investment
                } else {
                    return false;  // Not enough balance to buy Dogecoin
                }
            } else if (option == 2) {  // User chose Bitcoin
                if (balance >= bitcoin_value) {  // Check if balance is sufficient
                    bitcoin += 1;  // Increase Bitcoin count
                    balance -= bitcoin_value;  // Deduct Bitcoin value from balance
                    crypto_invest += bitcoin_value;  // Update investment
                } else {
                    return false;  // Not enough balance to buy Bitcoin
                }
            } else {
                return false;  // Invalid option selected
            }
        } else {
            return false;  // No equity available, purchase fails
        }
        return true;  // Purchase successful
    }

    // Function to sell cryptocurrency
    bool sell_crypto() {
        int option;  // Variable to select crypto type
        cout << "Want to sell Dogecoin press 1, else for Bitcoin press 2\n";
        cin >> option;  // User selects cryptocurrency type

        if (option == 2) {  // User chose Bitcoin
            if (bitcoin == 0)  // Check if there are any Bitcoins to sell
                return false;  // No Bitcoins to sell

            crypto_return += bitcoin_value;  // Update return from crypto
            balance += bitcoin_value;  // Add Bitcoin value to balance
            transactions.push_back({"Bitcoin Sold:", bitcoin_value});  // Record the transaction
            bitcoin -= 1;  // Decrease Bitcoin count
        } else if (option == 1) {  // User chose Dogecoin
            if (dogecoin == 0)  // Check if there are any Dogecoins to sell
                return false;  // No Dogecoins to sell

            crypto_return += dogecoin_value;  // Update return from crypto
            balance += dogecoin_value;  // Add Dogecoin value to balance
            transactions.push_back({"Dogecoin Sold:", dogecoin_value});  // Record the transaction
            dogecoin -= 1;  // Decrease Dogecoin count
        } else {
            return false;  // Invalid option selected
        }

        return true;  // Sale successful
    }

    // Function to display transaction history
    void History() {
        cout << "Displaying All transactions\n";
        for (auto it : transactions) {  // Iterate through all transactions
            cout << it.first << " " << it.second << endl;  // Print transaction type and amount
        }

        char temp;
        cout << "Do you want to clear all transactions (Y/N)? ";
        cin >> temp;  // User decides whether to clear transactions

        int no = transactions.size();  // Get the number of transactions

        if (temp == 'Y' || temp == 'y') {  // If user chooses to clear transactions
            transactions.clear();  // Clear all transactions
            cout << "Total transactions cleared: " << no << endl;
        } else {
            cout << "Total transactions: " << no << endl;  // Print total number of transactions
        }
    }
};

// Main function
int main() {
    Account person;  // Create an Account object
    int amount, choice;
    bool ans;

    while (true) {  // Infinite loop to display menu and handle user choices
        cout << "******************************************" << endl;
        cout << "Press 1 if you want to see your Account Info" << endl;
        cout << "Press 2 if you want to Deposit money" << endl;
        cout << "Press 3 if you want to Withdraw money" << endl;
        cout << "Press 4 if you want to view your transaction History" << endl;
        cout << "Press 5 if you want to Buy Cryptocurrency" << endl;
        cout << "Press 6 if you want to Sell Cryptocurrency" << endl;
        cout << "Press any other key to Exit" << endl;
        cout << "******************************************" << endl;

        cin >> choice;  // User selects an option

        switch (choice) {
            case 1:
                person.Get_account_information();  // Display account details
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;  // Input deposit amount
                ans = person.Deposit(amount);  // Deposit money
                if (ans)
                    cout << "Successfully deposited money" << endl;
                else
                    cout << "Deposit failed" << endl;
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;  // Input withdrawal amount
                ans = person.Withdraw(amount);  // Withdraw money
                if (ans)
                    cout << "Successfully withdrawn amount" << endl;
                else
                    cout << "Not enough balance" << endl;
                break;

            case 4:
                person.History();  // Display transaction history
                break;

            case 5:
                ans = person.buy_crypto();  // Attempt to buy cryptocurrency
                if (ans)
                    cout << "Purchase successful" << endl;
                else
                    cout << "Purchase failed" << endl;
                break;

            case 6:
                ans = person.sell_crypto();  // Attempt to sell cryptocurrency
                if (ans)
                    cout << "Sale successful" << endl;
                else
                    cout << "Sale failed" << endl;
                break;

            default:
                exit(0);  // Exit the program
        }
    }

    return 0;  // Program termination
}

