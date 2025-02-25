#include<iostream>
using namespace std;
class student
{
private:
int id,marks[3];
string name;
float average=0;
public:
void getdata()
{
cout<<"Enter student id: ";
cin>>id;
cin.ignore();
cout<<"Enter student name: ";
getline(cin,name);
for(int i=0;i<3;i++)
{
    fflush(stdin);
cout<<"Enter student marks: ";
fflush(stdin);
cin>>marks[i];
}
cout<<endl;
}
float Average()
{
for(int i=0;i<3;i++)
{
    fflush(stdin);
average=average+marks[i]/3;

}
cout<<"Average: "<<average<<endl;
}
void display()
{
cout<<"--------------------------------"<<endl;
cout<<"Id of student is: "<<id<<endl;
cout<<"Name of student is: "<<name<<endl;
for(int i=0;i<3;i++)
{
    fflush(stdin);
    cout<<"Marks of students are: ";
cout<<marks[i];
cout<<endl;
}
cout<<"Average of student is : "<<average<<endl;
}

};
int main()
{
student S[100];
int n;
cout<<"Enter number of student: ";
cin>>n;
for(int i=1;i<=n;i++)
{
S[i].getdata();
S[i].Average();
}
for(int i=1;i<=n;i++)
{
    S[i].display();
}
cout<<"---------------------------------"<<endl<<"NAME: SIMRAN BAMBANI"<<endl<<"ID: 24CE005"<<endl;
return 0;
}
