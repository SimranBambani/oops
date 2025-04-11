#include<iostream>
using namespace std;
class acc_details
{
private:
   string acc_name;
   int acc_number,count=0;
   double acc_balance=0;
public:
    void get(string n,int acc_num)
    {
        acc_name=n;
        acc_number=acc_num;
    }
    double deposit(double depo)
    {
        acc_balance=acc_balance+depo;
        cout<<"BALANCE AFTER DEPOSITED AMOUNT: "<<acc_balance<<endl;
    }

    int Get_Acc_Num() {
        return acc_number;
    }
    double withdraw(double widr)
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
    char ch;
    do{
    cout<<"Enter 'D' for depositing the money ,enter 'W' for withdrawing the money and enter 'E' to exit, Enter 'A' to add account: ";
    cin>>ch;
    switch(ch)
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
            A[count].get(name, account_num);
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
            A[index].deposit(depo_amount);
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
            cout<<"Enter deposit amount: ";
            cin>>widr_amount;
            A[index].withdraw(widr_amount);
            break;
    default:
        cout<<"Enter a valid function to perform";
        break;
    }

    }while(ch!='E');
    return 0;
}
