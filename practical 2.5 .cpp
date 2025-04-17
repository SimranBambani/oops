#include<iostream>
#include<cmath>
using namespace std;
class Loan_Master
{
    string applicants_name;
    float loan_amount;
    double EMI;
    int loan_tenure;
    static float interest_rate;
public:
    void Get_Data(string name,float amount,int tenure)
    {
       applicants_name=name;
       loan_amount=amount;
       loan_tenure=tenure;
       cout<<"EMI= "<<EMI_Calculator(loan_amount,loan_tenure)<<endl;

    }
     double EMI_Calculator(float amount,int tenure)
    {
        EMI=(loan_amount*interest_rate*pow(1+interest_rate,loan_tenure))/(pow(1+interest_rate,loan_tenure)-1);
        return EMI;
    }
    void Display()
    {
        cout<<"---------------------------------------"<<endl;
        cout<<"Name of the applicant is : "<<applicants_name<<endl;
        cout<<"Total amount of the loan is: "<<loan_amount<<endl;
        cout<<"Interest rate is: "<<interest_rate<<endl;
        cout<<"Loan tenure is: "<<loan_tenure<<endl;
        cout<<"EMI= "<<EMI_Calculator(loan_amount,loan_tenure)<<endl;

    }
}loan[100];
float Loan_Master::interest_rate=7;
int main()
{
    string name;
   float amount;
   int tenure,count=0,i;
   char input;
   do
   {
       cout<<"Enter'C' if you want to create a account or Enter 'D' to display a account or Enter 'E' to exit: ";
       cin>>input;
       switch(input)
       {
       case'C':
            cout<<"Enter the name of the applicant: ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter the loan amount: ";
            cin>>amount;
            cout<<"Enter the loan tenure: ";
            cin>>tenure;
            loan[count].Get_Data(name,amount,tenure);
            count++;
            break;
    case 'D':
           for(i=0;i<count;i++)
           {
              loan[i].Display();
           }
           break;
       }
   }while(input!='E');
    return 0;
}
