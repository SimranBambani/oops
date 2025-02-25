#include<iostream>
#include<string>
using namespace std;
class item_data
{
private:
    int item_id;
    string item_name;
    float item_prize;
    int item_quantity;
    public:
        void get_data(int id,string name,int quantity,float prize)
        {
          item_id=id;
          item_name=name;
          item_prize=prize;
          item_quantity=quantity;
        }
        int buy(int ID,int QUANTITY)
        {
           if(item_id==ID)
           {
               if(item_quantity>=QUANTITY)
               {
               item_quantity=item_quantity-QUANTITY;
               }
               else{
                   cout<<"SORRY FOR THE INCONVINENCE BUT WE ONLY HAVE "<<item_quantity<<"QUANTITY AVAILABLE."<<endl;
               }
           }
               else{
                cout<<"NO SUCH PRODUCT FOUND"<<endl;
               }

        }
          void display()
          {
              cout<<"The product id is : "<<item_id<<endl;
              cout<<"The quantity of the product is: "<<item_quantity<<endl;
          }


};
int main()
{
    int id,quantity,i;
    float prize;
    string name;
    char input;
    item_data I[100];
    cout<<"WELCOME TO THE STORE"<<endl;
    do{
    cout<<"Enter A to add data in stock,Enter B to buy something,Enter D to display current data and Enter E to exit: ";
    cin>>input;
    switch(input)
    {
    case 'A':
        cout<<"Enter the ID number of the product: ";
        cin>>id;
        cout<<"Enter the Name of the product: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the quantity of the product: ";
        cin>>quantity;
        cout<<"Enter the prize of the quantity: ";
        cin>>prize;
        for(i=0;i<100;i++)
        {
        I[i].get_data(id,name,quantity,prize);
        }
        break;
    case 'B':
        cout<<"Enter the ID number of the product to buy: ";
        cin>>id;
        cout<<"Enter the quantity of the product to buy: ";
        cin>>quantity;
        for(i=0;i<100;i++)
        {
        I[i].buy(id,quantity);
        }
        break;
    case 'D':
          cout<<"HERE IS YOUR DATA: "<<endl;
          for(i=0;i<100;i++)
          {
        I[i].display();
          }
        break;

}
    }while(input!='E');
    cout<<"NAME: SIMRAN BAMBANI"<<endl<<"ID: 24CE005";
}

