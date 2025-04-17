#include<iostream>
using namespace std;
class Person
{
    protected:
    int person_age;
    string person_name;
public:
    Person(string name,int age)
    {
        person_age=age;
        person_name=name;
    }
    void Display_Data()
    {
        cout<<"Name: "<<person_name<<endl;
        cout<<"Age: "<<person_age<<endl;
    }
};
class Manager: public Person
{
protected:
    int  manager_id;
    string department;
public:
    Manager(string name, int age, int id, string dept) : Person(name, age)
    {
        manager_id=id;
        department=dept;
    }
    void Display()
    {
        cout<<"Manager id: "<<manager_id<<endl;
        cout<<"Department: "<<department<<endl;
    }
};
class Employee: public Manager
{

    public:
         Employee(string name,int age,int id,string dept)
        : Manager(name,age,id,dept) {}

    void Show_Details() {
        Display_Data();
        Display();
    }
};
int main()
{
    int age,id,num,i;
    string name,dept;
    cout<<"Enter the number of employee: "<<endl;
    cin>>num;
    Employee **E=new Employee*[num];
    for(i=0;i<num;i++)
    {
    cout<<"Enter the name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the age: ";
    cin>>age;
    cout<<"Enter the id: ";
    cin>>id;
    cout<<"Enter the department: ";
    cin.ignore();
    getline(cin,dept);
    E[i]=new Employee(name,age,id,dept);
    }
    for(i=0;i<num;i++)
    {
        cout<<"--------------------------"<<endl;
        E[i]->Show_Details();
    }
    return 0;
}

