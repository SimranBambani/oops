#include<iostream>
using namespace std;
class shape
{
private:
    string shape_name;
    float radius;
public:
    void get_data(string name,float radii)
    {
       shape_name=name;
       radius=radii;
    }
    void display()
    {
        cout<<"The shape of the object: "<<shape_name<<endl;
        cout<<"Radius of th object: "<<radius<<endl;
    }
   inline float radius_()
    {
        return radius;
    }
};
class circle: public shape
{
public:
    float area(){
    float Radius=radius_();
    return 3.14*Radius*Radius;
    }
    void display_radius()
    {
        cout<<"Area of the circle: "<<area()<<endl;
    }

};
int main()
{
    int num;
    cout<<"Enter the number of the circle: "<<endl;
    cin>>num;
    circle *C1= new circle[num];
    float radii;
    string name;
    for(int i=0;i<num;i++){
    cout<<"Enter the shape: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the radius: ";
    cin>>radii;
    C1[i].get_data(name,radii);
    C1[i].display();
    C1[i].area();
    C1[i].display_radius();
    }
    return 0;
}
