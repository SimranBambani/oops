#include<iostream>
using namespace std;
class Rectangle
{
private:
     int length,x;
     int width,area,perimeter;
     char ch;
public:
    int Get_Dimensions()
    {
    cout<<"Enter the length of rectangle: ";
    cin>>length;
    cout<<"Enter the width of rectangle: ";
    cin>>width;
    }
    int Calculate_Area()
    {
    area=length*width;
    cout<<"Area of rectangle is: "<<area<<endl;
    }
    int Calculate_Perimeter()
    {
    perimeter=2*(length+width);
    cout<<"Perimeter of rectangle is: "<<perimeter<<endl;
    cout<<"----------------------------"<<endl;
    }
    int Update_Dimensions(int l,int w)
    {
    length=l;
    width=w;
    }
    void Display()
    {
     cout<<"Length of rectangle: "<<length<<endl;
     cout<<"Width of rectangle: "<<width<<endl;
     cout<<"Area of rectangle is: "<<area<<endl;
     cout<<"Perimeter of rectangle is: "<<perimeter<<endl;
     cout<<endl;
    }
};
int main()
{
   Rectangle R[100];
   int i,number,updated_number,length,width;
   char ch;
   cout<<"Enter the number of rectangle : ";
   cin>>number;
   cout<<"----------------------------"<<endl;
   for(i=1;i<=number;i++)
   {
    cout<<"Rectangle "<<i<<endl;
    R[i].Get_Dimensions();
    R[i].Calculate_Area();
    R[i].Calculate_Perimeter();
   }
   cout<<"WHAT TO UPDATE ANY RECTANGLE DIMENSIONS? IF YES! THEN ENTER 'Y' AND NO THEN ENTER 'N'. ";
   cin>>ch;
   if(ch=='Y')
   {
     cout<<"Enter rectangle number: ";
     cin>>updated_number;
     cout<<"------------------------------------"<<endl;
    for(i=1;i<=number;i++)
    {
     if(i==updated_number)
      {
       cout<<"Enter the length of rectangle: ";
       cin>>length;
       cout<<"Enter the width of rectangle: ";
       cin>>width;
       R[i].Update_Dimensions(length,width);
       R[i].Calculate_Area();
       R[i].Calculate_Perimeter();
      }
    }
   }
      else
       {
         cout<<"DONE";
       }
     cout<<"UPDATED QUANTITIES ARE: "<<endl;
    for(i=1;i<=number;i++)
    {
     cout<<"Rectangle: "<<i<<endl;
     fflush(stdin);
     R[i].Display();
    }
cout<<"---------------------------------"<<endl<<"NAME: SIMRAN BAMBANI"<<endl<<"ID: 24CE005"<<endl;
return 0;
}

