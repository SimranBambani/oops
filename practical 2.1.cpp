#include<iostream>
using namespace std;
class Rectangle
{
private:
int length,x;
int width,area,perimeter;
char ch;
public:
int setDimensions()
{

cout<<"Enter the length of rectangle: ";
cin>>length;
cout<<"Enter the width of rectangle: ";
cin>>width;
}
int Area()
{
area=length*width;
cout<<"Area of rectangle is: "<<area<<endl;
}
int Perimeter()
{
perimeter=2*(length+width);
cout<<"Perimeter of rectangle is: "<<perimeter<<endl;
cout<<"----------------------------"<<endl;
}
int update(int l,int w)
{
length=l;
width=w;

}
 void display()
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
int i,n,x,l,w;
char ch;
cout<<"Enter the number of rectangle : ";
cin>>n;
cout<<"----------------------------"<<endl;
for(i=1;i<=n;i++)
{
cout<<"Rectangle "<<i<<endl;
R[i].setDimensions();
R[i].Area();
R[i].Perimeter();
}
cout<<"WHAT TO UPDATE ANY RECTANGLE DIMENSIONS? IF YES! THEN ENTER 'Y' AND NO THEN ENTER 'N'. ";
cin>>ch;
if(ch=='Y')
{
cout<<"Enter rectangle number: ";
cin>>x;
cout<<"------------------------------------"<<endl;
for(i=1;i<=n;i++)
{
    if(i==x)
{
cout<<"Enter the length of rectangle: ";
cin>>l;
cout<<"Enter the width of rectangle: ";
cin>>w;
R[i].update(l,w);
R[i].Area();
R[i].Perimeter();
}
}
}
else
{
cout<<"DONE";
}
cout<<"UPDATED QUANTITIES ARE: "<<endl;
for(i=1;i<=n;i++)
{
    cout<<"Rectangle: "<<i<<endl;
    fflush(stdin);
    R[i].display();
}
cout<<"---------------------------------"<<endl<<"NAME: SIMRAN BAMBANI"<<endl<<"ID: 24CE005"<<endl;
return 0;
}

