#include<iostream>
using namespace std;
const double DEFAULT_BONUS = 5000.0;
class employee_salary
{
    float basic_salary;
    float employee_bonus,total_salary;
    string employee_name;
public:
    employee_salary()
    {
        char choice;
        fflush(stdin);
       cout<<"Enter the name of employee: ";
       cin>>ws;
        getline(cin,employee_name);
        fflush(stdin);
        cout<<"Enter the salary of the employee: ";
        cin>>basic_salary;
        cout<<"Enter your choice : Enter y to add bonus."<<endl;
        cin>>choice;
        if(choice=='y')
        {
        cout<<"Enter the bonus: ";
        cin>>employee_bonus;
        }
        else
        {
           employee_bonus=DEFAULT_BONUS;
        }
    }
    inline void salary()
    {
        total_salary=basic_salary+employee_bonus;
    }
    void display()
    {
        cout<<"Name of the employee: "<< employee_name<<endl;
        cout<<"Salary of the employee: "<<basic_salary<<endl;
        cout<<"Bonus amount of the employee: "<<employee_bonus<<endl;
          cout<<"Total salary of the employee: "<<total_salary<<endl;
    }
};
int main()
{
    int num,i;
    cout<<"Enter the number of employee: ";
    cin>>num;
    fflush(stdin);
    float salary,bonus;
    string name;
    employee_salary *ptr=new employee_salary[num];
    for(i=0;i<num;i++)
    {

        ptr[i].salary();
        ptr[i].display();

    }
    return 0;
}
