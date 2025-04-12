#include<iostream>
using namespace std;
const int max_student=100;
class Undergraduate;
class Postgraduate;
class Student {
protected:
    string name;
    int rollNo;
    double marks;
public:
    void inputData() {
        cout<<"Enter student name: ";
         cin>>name;
        cout<<"Enter roll number: ";
          cin>>rollNo;
        cout<<"Enter marks : ";
        cin>>marks;
    }
    virtual void compute_Grade() = 0;

    virtual void display()
    {
        cout<<"Name: " <<name<<endl;
        cout<<"Roll No: "<<rollNo<<endl;
        cout<<" Marks: "<< marks<< endl;
    }
    virtual ~Student()
    {}
};
class Undergraduate:public Student
 {
public:
    void compute_Grade()override
    {
        display();
        cout<<"Undergraduate Grade: ";
        if(marks>=85)
            {
            cout<<"A"<<endl;
            }
        else if(marks>=70)
        {
            cout<<"B"<<endl;
        }
        else if (marks>=50)
        {
            cout<<"C"<<endl;
        }
        else
        {
            cout<<"F"<<endl;
        }
    }
};
class Postgraduate:public Student
{
public:
    void compute_Grade()override
    {
        display();
        cout << "Postgraduate Grade: ";
       if(marks>=90)
            {
            cout<<"A"<<endl;
            }
        else if(marks>=75)
        {
            cout<<"B"<<endl;
        }
        else if (marks>=60)
        {
            cout<<"C"<<endl;
        }
        else
        {
            cout<<"F"<<endl;
        }
    }
};
int main() {
    Student* students[max_student];
    int n,choice,i;
    cout<<"Enter number of students: ";
    cin>> n;
for(i = 0;i<n;++i)
    {
        cout<<"Enter 1 for Undergraduate, Enter 2 for Postgraduate: ";
        cin>>choice;
        if(choice == 1)
         {
            students[i]=new Undergraduate();
        }
        else if (choice == 2)
         {
            students[i]=new Postgraduate();
        }
         else
        {
            cout << "Invalid choice. Skipping this student.\n";
            students[i] = nullptr;
            continue;
        }
        students[i]->inputData();
    }
    for(i=0;i<n;++i) {
        if(students[i] != nullptr)
            {
            students[i]->compute_Grade();
        }
    }
    for(i = 0; i < n; ++i) {
        delete students[i];
    }
    return 0;
}

