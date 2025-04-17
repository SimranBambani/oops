#include<iostream>
using namespace std;
class Shape
{
private:
    string shape_name;
    float radius;
public:
    void Get_Data(string name,float radii)
    {
       shape_name=name;
       radius=radii;
    }
    void Display()
    {
        cout<<"The shape of the object: "<<shape_name<<endl;
        cout<<"Radius of th object: "<<radius<<endl;
    }
   inline float Radius_Of_Shape()
    {
        return radius;
    }
};
class Circle: public Shape
{
public:
    float Area_Of_Shape(){
    float Radius=Radius_Of_Shape();
    return 3.14*Radius*Radius;
    }
    void Display_Area()
    {
        cout<<"Area of the circle: "<< Area_Of_Shape()<<endl;
    }

};
int main()
{
    int num;
    cout<<"Enter the number of the circle: "<<endl;
    cin>>num;
    Circle *C1= new Circle[num];
    float radii;
    string name;
    for(int i=0;i<num;i++){
    cout<<"Enter the shape: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the radius: ";
    cin>>radii;
    C1[i].Get_Data(name,radii);
    C1[i].Display();
    C1[i]. Area_Of_Shape();
    C1[i].Display_Area();
    }
    return 0;
}
