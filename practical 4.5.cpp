#include<iostream>
using namespace std;
const int max_student = 100;
class Student_Grade
{
private:
    string name;
    int rollNo;
    double marks;
public:
    void Get_Data() {
        cout<<"Enter student name: ";
        cin>>name;
        cout<<"Enter roll number: ";
        cin>>rollNo;
        cout<<"Enter marks: ";
        cin>>marks;
    }
    virtual void Calculate_Grade()
    {
    }
    void Display_Data() {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollNo<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
  
class Undergraduate : public Student_Grade {
public:
    void Calculate_Grade() {
        Display_Data();
        cout<<"Undergraduate Grade: ";
        if(marks>= 85)
            cout<<"A"<<endl;
        else if(marks>=70)
            cout<<"B"<<endl;
        else if (marks >= 50)
            cout<<"C"<<endl;
        else
            cout<<"F"<<endl;
    }
};
class Postgraduate : public Student_Grade {
public:
    void Calculate_Grade()  {
        Display_Data();
        cout<<"Postgraduate Grade: ";
        if(marks >= 90)
            cout<<"A"<<endl;
        else if(marks>= 75)
            cout<<"B"<<endl;
        else if(marks>=60)
            cout<<"C"<<endl;
        else
            cout<<"F"<<endl;
    }
};
int main() {
    Student_Grade* students[max_student];
    int number,choice;
    int count = 0;
    cout << "Enter number of students: ";
    cin >> number;
    for (int i = 0;i<number;i++) {
        cout << "Enter 1 for Undergraduate, 2 for Postgraduate: ";
        cin >> choice;
        if (choice == 1) {
            students[count]= new Undergraduate();
        }
        else if (choice==2) {
            students[count]=new Postgraduate();
        }
         else
         {
            cout<< "Invalid choice. Please try again." << endl;
            i--;
        }
        students[count]->Get_Data();
        count++;
    }
    for(int i=0;i<number;i++) {
        students[i]->Calculate_Grade();
    }

    for(int i=0;i<count;i++) {
        delete students[i];
    }
    return 0;
}
