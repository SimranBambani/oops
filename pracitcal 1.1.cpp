#include<iostream>
using namespace std;
class BackAccount
{
private:
    string acc_holder_name;
    float depo_amount;
    float widr_amount;
    double acc_number;
    float balance;
   public:
    void display(){
        cout<<"Enter the account holder's name: ";
        getline(cin,acc_holder_name);
        cout<<"Enter the account number: ";
        cin>>acc_number;
    }
    float deposit()
    {
        cout<<"Enter amount deposited: ";
        cin>>depo_amount;
        cout<<"AMOUNT DEPOSITED: "<<depo_amount<<endl;
        return 0;
    }
    float withdraw()
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
    float balance_amount()
    {
        balance=depo_amount-widr_amount;
        if(balance>0){
        cout<<"Balance: "<<balance<<endl;
        }
        return 0;
    }

}s1;
int main()
{
    s1.display();
    s1.deposit();
    s1.withdraw();
    s1.balance_amount();
    cout<<"--------------------------------"<<endl;
    cout<<"NAME: SIMRAN BAMBANI"<<endl;
    cout<<"ID NO: 24CE005";
}
