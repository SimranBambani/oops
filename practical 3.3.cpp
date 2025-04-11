#include <iostream>
using namespace std;

class Account_details {
    string holder_name;
    int acc_num;
    float acc_balance;
    float total_amount;

public:
    void add_account(string n, int num, float bal) {
        holder_name = n;
        acc_num = num;
        acc_balance = bal;
        total_amount = bal;
    }

    int get_account_number() {
        return acc_num;
    }

    int search_account(int s) {
        return s == acc_num ? 1 : 0;
    }

    float total_amount_return() {
        return total_amount;
    }

    void deposit_amount(float d) {
        total_amount += d;
    }

    int withdraw_amount(float d) {
        if (total_amount >= d) {
            total_amount -= d;
            return 1;
        }
        return 0;
    }

    void display_balance() {
        cout << "Account Number: " << acc_num << " has balance: " << total_amount << endl;
    }
};

int main() {
    Account_details* accounts = new Account_details[1];
    int acc_counter = 0;
    int choice;

    do {
        cout << "\n1 = Create Account\n2 = Transfer Money\n3 = Show Total Number of Accounts\n4 = Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int a_num;
                float a_bal;

                cout << "Enter holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter account number: ";
                cin >> a_num;
                cout << "Enter initial balance: ";
                cin >> a_bal;

                Account_details* temp = new Account_details[acc_counter + 1];

                for (int i = 0; i < acc_counter; i++) {
                    temp[i] = accounts[i];
                }

                accounts = temp;

                accounts[acc_counter].add_account(name, a_num, a_bal);
                acc_counter++;

                cout << "Account created successfully!\n";
                break;
            }

            case 2: {
                int from_acc, to_acc;
                float amount;
                int from_found = 0, to_found = 0;
                Account_details* from_account;
                Account_details* to_account;

                cout << "Enter account number FROM which money is to be transferred: ";
                cin >> from_acc;
                cout << "Enter account number TO which money is to be transferred: ";
                cin >> to_acc;
                cout << "Enter amount to transfer: ";
                cin >> amount;

                for (int i = 0; i < acc_counter; i++) {
                    if (accounts[i].search_account(from_acc)) {
                        from_found = 1;
                        from_account = &accounts[i];
                    }
                    if (accounts[i].search_account(to_acc)) {
                        to_found = 1;
                        to_account = &accounts[i];
                    }
                }

                if (!from_found || !to_found) {
                    cout << "One or both account numbers not found!\n";
                } else if (from_account->withdraw_amount(amount)) {
                    to_account->deposit_amount(amount);
                    cout << "Transaction successful!\n";
                    from_account->display_balance();
                    to_account->display_balance();
                } else {
                    cout << "Insufficient balance in source account!\n";
                }
                break;
            }

            case 3:
                cout << "Total number of accounts: " << acc_counter << endl;
                break;

            case 4:
                cout << "Thanks";
                break;

            default:
                cout << "Invalid choice! Please enter a valid option."<<endl;
                break;
        }

    } while (choice != 4);
    return 0;
}

