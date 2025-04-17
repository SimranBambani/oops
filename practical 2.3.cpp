#include<iostream>
using namespace std;
class Account_Details
{
private:
   string acc_name;
   int acc_number,count=0;
   double acc_balance=0;
public:
    void Get_data(string n,int acc_num)
    {
        acc_name=n;
        acc_number=acc_num;
    }
    double Deposit_Amount(double depo)
    {
        acc_balance=acc_balance+depo;
        cout<<"BALANCE AFTER DEPOSITED AMOUNT: "<<acc_balance<<endl;
    }

    int Get_Acc_Num() {
        return acc_number;
    }
    double Withdraw_Amount(double widr)
    {
        if(widr>5000)
        {
        if(acc_balance>widr)
        {
        acc_balance=acc_balance-widr;
        cout<<"BALANCE AFTER WITHDRAW AMOUNT: "<<acc_balance<<endl;
        }
        }
        else
        {
            cout<<"INSIFFICENT BALANCE";
        }
    }
}A[100];

int count=0;
int Find_Account(int acc_num) {
    for (int i=0;i<count;i++) {
        if (A[i].Get_Acc_Num()==acc_num) {
            return i;
        }
    }
    return -1;
}
int main()
{
    int balance,account_num,i,index;
    string name;
    double depo_amount,widr_amount;
    char choice;
    do{
    cout<<"Enter 'D' for depositing the money ,enter 'W' for withdrawing the money and enter 'E' to exit, Enter 'A' to add account: ";
    cin>>choice;
    switch(choice)
    {
    case 'A':
    cout<<"------------------------------------"<<endl;
    cout<<"Enter name of the account holder: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the account number: ";
    cin>>account_num;
     if (Find_Account(account_num)!=-1) {
                cout<< "Account already exists"<<endl;
                break;
            }
            A[count].Get_data(name, account_num);
            cout << "Account created successfully"<<endl;
    count++;
    cout<<"------------------------------------"<<endl;
    break;
    case 'D':
      cout<<"Enter account number: ";
            cin>>account_num;
        index= Find_Account(account_num);
            if(index==-1)
            {
                cout<<"Account not found!"<<endl;
                break;
            }
            cout<<"Enter deposit amount: ";
            cin>>depo_amount;
            A[index].Deposit_Amount(depo_amount);
            break;
    break;
    case 'W':
        cout<<"Enter account number: ";
            cin>>account_num;
        index=Find_Account(account_num);
            if(index==-1)
                {
                cout<<"Account not found!"<<endl;
                break;
            }
            cout<<"Enter withdraw amount: ";
            cin>>widr_amount;
            A[index].Withdraw_Amount(widr_amount);
            break;

    }
    }while(choice!='E');
    return 0;
}
