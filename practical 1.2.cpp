#include<iostream>
using namespace std;
const int Max_Products=100;
class Inventory;
class Product
{
    int id;
    string name;
    int quantity;
    float price;
public:
    void Set_Data(int pid,string pname,int qty,float p)
    {
        id=pid;
        name=pname;
        quantity=qty;
        price=p;
    }
    int Get_Id()
     {
    return id;
    }
    void Update_Quantity(int Qty_Change)
    {
        quantity=quantity+Qty_Change;
    }
    float Get_Value()
    {
        return quantity*price;
    }
    void display()
     {
        cout<<"ID: "<<id<<endl;
         cout<<"Name: " <<name<<endl;
          cout<<"Quantity: "<<quantity<<endl;
        cout<< "Price: "<<price<<endl;
    }
};
class Inventory
{
    Product products[Max_Products];
    int count;
public:
    Inventory()
    {
        count=0;
    }
    void Add_Product(int id,string name,int quantity,float price)
     {
        if (count<Max_Products)
            {
            products[count].Set_Data(id,name,quantity,price);
            count++;
        }
         else
        {
            cout<<"Inventory full"<<endl;
        }
    }
    void Update(int id,int Qty_Change)
    {
        for (int i=0;i<count;i++)
            {
            if (products[i].Get_Id()==id)
                {
                products[i].Update_Quantity(Qty_Change);
                return;
            }
        }
        cout<<"Product not found"<<endl;
    }

    float Calculate_Total_Value()
     {
        float total=0;
        for (int i=0;i<count;i++)
            {
            total=total+products[i].Get_Value();
        }
        return total;
    }

    void Display_Inventory()
     {
        for (int i=0;i<count;i++)
            {
            products[i].display();
        }
    }
};
int main()
{
    int n,i;
    cout<<"Enter the number of items: "<<endl;
    cin>>n;
    Inventory inv[n];
    int id,quantity,up_quantity,up_id;
    string name;
    float price;
     cout<<"Enter the name of the product: "<<endl;
     cin.ignore();
     getline(cin,name);
    cout<<"Enter the id of the product: "<<endl;
    cin>>id;
    cout<<"Enter the Quantity of the product: "<<endl;
    cin>>quantity;
   cout<<"Enter the price of the product: "<<endl;
   cin>>price;
   for(i=0;i<n;i++)
   {
    inv[i].Add_Product(id,name,quantity,price);
    cout<<"Enter the updated quantity: "<<endl;
    cin>>up_quantity;
    cout<<"Enter the id  of the product: "<<endl;
    cin>>up_id;
    inv[i].Update(up_id,up_quantity);
    inv[i].Display_Inventory();
    cout<<"Total Inventory Value: "<<inv[i].Calculate_Total_Value()<<endl;
   }
    return 0;
}

