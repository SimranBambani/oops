#include<iostream>
using namespace std;
class Bank_Account
{
private:
    string acc_holder_name;
    float depo_amount;
    float widr_amount;
    double acc_number;
    float balance;
public:
    void Get_Data(){
        cout<<"Enter the account holder's name: ";
        getline(cin,acc_holder_name);
        cout<<"Enter the account number: ";
        cin>>acc_number;
    }
    float Deposit_Amount()
    {
        cout<<"Enter amount deposited: ";
        cin>>depo_amount;
        cout<<"AMOUNT DEPOSITED: "<<depo_amount<<endl;
        return 0;
    }
    float Withdraw_Amount()
    {
        cout<<"Enter amount to be withdraw: ";
        cin>>widr_amount;
        if(depo_amount>widr_amount)
        cout<<"AMOUNT WITHDRAW: "<<widr_amount<<endl;
        else{
            cout<<"Insufficent Balance."<<endl;
        }
        return 0;
    }
    float Balance_Amount()
    {
        balance=depo_amount-widr_amount;
        if(balance>0){
        cout<<"Balance: "<<balance<<endl;
        }
        return 0;
    }
    void Display()
    {
        cout<<"Account Holder Name: "<<acc_holder_name<<endl;
        cout<<"Account Number: "<<acc_number<<endl;
        cout<<"Deposited Amount: "<<depo_amount<<endl;
        cout<<"Withdraw Amount: "<<widr_amount<<endl;
        cout<<"Balance Amount: "<<balance<<endl;
    }

};
int main()
{
    Bank_Account s1;
    s1.Get_Data();
    s1.Deposit_Amount();
    s1.Withdraw_Amount();
    s1.Balance_Amount();
    s1.Display();
    cout<<"--------------------------------"<<endl;
    cout<<"NAME: SIMRAN BAMBANI"<<endl;
    cout<<"ID NO: 24CE005";
}
