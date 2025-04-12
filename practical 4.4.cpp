#include<iostream>
using namespace std;
const int max_transaction=6;
class Current_Account;
class Saving_Account;
class Account_details
{
    int account_number;

    int transaction_type[max_transaction];
    double transaction_amount[max_transaction];
    int count=0;
    protected:
    double balance;
public:
     Account_details(int account_number,double balance)
     {
         this->account_number=account_number;
         this->balance=balance;
     }
      virtual ~Account_details()
     {
     }
     void transaction(int type ,double amount)
     {
         if(count<max_transaction)
         {
              transaction_type[count]=type;
           transaction_amount[count]=amount;
            count++;
         }
         else{
            cout<<"No more transaction possible."<<endl;
         }
     }
     virtual void deposit(double amount)
     {
         balance=balance+amount;
         transaction(0,amount);
         cout<<"Deposited amount: "<<amount<<endl;
     }
     virtual void withdraw(double amount)
     {
         if(balance>=amount)
         {
             balance=balance-amount;
             transaction(1,amount);
             cout<<"Withdraw amount is: "<<endl;
         }
         else{
            cout<<"Insufficent balance."<<endl;
         }
     }
     void Last_transaction()
     {
         if(count==0)
         {
             cout<<"No last transaction."<<endl;
         }
         else
         {
             count--;
             int last=transaction_type[count];
             double  last_amount=transaction_amount[count];
             if(last==0)
             {
                 balance=balance-last;
                 cout<<"Undo deposit"<<last_amount<<" and latest amount: "<<balance<<endl;
             }
             else if(last==1)
             {
                 balance=balance+last;
                 cout<<"Undo withdraw"<<last_amount<<" and latest amount: "<<balance<<endl;
             }
         }
     }
     float get_balance()
     {
         return balance;
     }
};
class Saving_Account: public Account_details
{
    double rate;
public:

    Saving_Account(int account_number,double balance,double rate):Account_details( account_number,balance)
    {
        this->rate=rate;
    }
    ~Saving_Account()
    {
    }
    void interest()
    {
        double interest=balance*(rate/100.0);
        deposit(interest);
        cout<<"Interest applied: "<< interest<<endl;
    }
};
class Current_Account: public Account_details
{
     double Over_Draft_Limit;

public:
    Current_Account(int account_number,double balance,double Over_Draft_Limit):Account_details(account_number,balance)
    {
       this->Over_Draft_Limit=Over_Draft_Limit;
        cout << "CurrentAccount created with overdraft limit: " << Over_Draft_Limit << endl;
    }

    ~Current_Account()
    {
        cout << "CurrentAccount destroyed." << endl;
    }
    void withdraw(double amount)override
     {
        if (balance+Over_Draft_Limit>=amount)
            {
            balance -= amount;
            transaction(1,amount);
            cout << "Withdraw: "<<amount<< " and balance is: " <<balance<<endl;
        } else
        {
            cout <<"Withdrawal failed: Overdraft limit exceeded."<<endl;
        }
    }

};
int main()
{
     int number;
    double balance,amount,rate_or_limit;
     int choice,Acc_type;
    Account_details* account = nullptr;
    cout<<"Enter you choice:Enter 1 for Savings Account. Enter 2 for Current Account: ";
    cin>>Acc_type;
    cout<<"Enter Account Number: ";
    cin>>number;
    cout<<"Enter Initial Balance: ";
    cin>>balance;

    if (Acc_type==1)
        {
        cout<<"Enter the Interest Rate: "<<endl;
        cin>>rate_or_limit;
        account=new Saving_Account(number,balance,rate_or_limit);
    }
    else if(Acc_type==2)
    {
        cout<<"Enter Limit for overdraft: ";
        cin>>rate_or_limit;
        account=new Current_Account(number,balance,rate_or_limit);
    }
    else
        {
        cout<<"Invalid account type"<<endl;
    }

    do {
        cout<< "Enter 1 to Deposit. Enter 2 to  Withdraw. Enter 3 to Show Balance. Enter 4 to Undo Last Transaction. Enter 5 to Apply Interest . Enter 0 to exit: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter deposit amount: ";
                cin>>amount;
                account->deposit(amount);
                break;
            case 2:
                cout<<"Enter withdrawal amount: ";
                cin>>amount;
                account->withdraw(amount);
                break;
            case 3:
                cout<<"Current balance: "<<account->get_balance()<< endl;
                break;
            case 4:
                account->Last_transaction();
                break;
            case 5:
                if(Acc_type == 1)
                    {
                    ((Saving_Account*)account)->interest();
                }
                else
                    {
                    cout<<"Interest not applicable for Current Account."<<endl;
                }
                break;
            default:
                cout<<"Invalid choice."<<endl;
        }
    } while(choice!= 0);

    delete account;
    return 0;
}


