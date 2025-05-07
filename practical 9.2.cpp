#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_LOG = 100;
class Bank_Account {
private:
    string account_holder;
    int account_number;
    float balance;
    string transaction_log[MAX_LOG];
    int log_count;

    void Log_Transaction(const string& message) {
        if (log_count < MAX_LOG) {
            transaction_log[log_count++] = message;
        }
    }
public:
    Bank_Account(string name, int accNo, float initialBalance = 0.0f) {
        account_holder = name;
        account_number = accNo;
        balance = initialBalance;
        log_count = 0;
        Log_Transaction("Account created for " + name + " with balance: " + to_string(balance));
    }

    void Deposit_Amount(float amount) {
        if (amount <= 0) {
            Log_Transaction("Error: Attempted Deposit Amount of non-positive amount: " + to_string(amount));
            cout << "Invalid Deposit Amount amount.\n";
            return;
        }
        balance += amount;
        Log_Transaction("Deposit Amounted: " + to_string(amount) + ", New Balance: " + to_string(balance));
        cout << "Deposit Amount successful.\n";
    }

    void Withdraw_Amount(float amount) {
        if (amount <= 0) {
            Log_Transaction("Error: Attempted WithdrawAmount of non-positive amount: " + to_string(amount));
            cout << "Invalid withdrawal amount.\n";
            return;
        }
        if (amount > balance) {
            Log_Transaction("Error: Withdrawal of " + to_string(amount) + " failed due to insufficient funds.");
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
        Log_Transaction("Withdrawn: " + to_string(amount) + ", Remaining Balance: " + to_string(balance));
        cout << "Withdrawal successful.\n";
    }

    void Display_Account() const {
        cout << "\nAccount Summary:\n";
        cout << "Holder Name  : " << account_holder << endl;
        cout << "Account No.  : " << account_number << endl;
        cout << "Balance      : " << balance << endl;
    }

    void Display_Log() const {
        cout << "\nTransaction Log:\n";
        for (int i = 0; i < log_count; ++i) {
            cout << i + 1 << ". " << transaction_log[i] << endl;
        }
    }
};

int main() {
    Bank_Account user("Simran", 123456, 1000.0f);
    int choice;
    float amount;
    do {
        cout << "1. Deposit Amount\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Account Info\n";
        cout << "4. Show Transaction Log\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to Deposit Amount: ";
                cin >> amount;
                user.Deposit_Amount(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                user.Withdraw_Amount(amount);
                break;
            case 3:
                user.Display_Account();
                break;
            case 4:
                user.Display_Log();
                break;
            case 5:
                cout << "Thank you for using the banking system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
