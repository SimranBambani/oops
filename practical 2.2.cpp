#include<iostream>
using namespace std;
class Student
{
private:
     int id,marks[3];
     string name;
     float average=0;
public:
   void Get_Data()
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
   float Calculte_Average()
   {
     for(int i=0;i<3;i++)
     {
       fflush(stdin);
       average=average+marks[i]/3;
     }
    cout<<"Average: "<<average<<endl;
   }
    void Display()
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
  Student S[100];
  int student_num;
  cout<<"Enter number of student: ";
  cin>>student_num;
  for(int i=1;i<=student_num;i++)
  {
    S[i].Get_Data();
    S[i].Calculte_Average();
  }
  for(int i=1;i<=student_num;i++)
  {
    S[i].Display();
  }
  cout<<"---------------------------------"<<endl<<"NAME: SIMRAN BAMBANI"<<endl<<"ID: 24CE005"<<endl;
  return 0;
}
