#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class SuperMarket
{   
    private:
        int product_code;
        string product_name;
        float product_price;
        float discount;

    public:
        void main_menu();
        void administrator();
        void customer();
        void add_product();
        void remove_product();
        void modify_product();
        void list();
        void receipt();

};

void SuperMarket :: main_menu()    
{                                                 
MainMenu:

    int option;
    string email;
    string password;
    cout<<"\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t      Supermarket Main Menu        \n";
    cout<<"\t\t\t\t                                   \n";
    cout<<"\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t|| (1) Administrator  ||\n";
    cout<<"\t\t\t\t||                    ||\n";
    cout<<"\t\t\t\t|| (2) Customer       ||\n";
    cout<<"\t\t\t\t||                    ||\n";
    cout<<"\t\t\t\t|| (3) Exit           ||\n";
    cout<<"\t\t\t\t||                    ||\n";
    cout<<"--Please Select from the given Options: ";
    cin>>option;

    switch(option)
    {
    case 1:
    
        cout<<"\t\t Please Sign In! \n";
        cout<<"\t\t Enter Email:    \n";
        cin>>email;
        cout<<"\t\t Enter Password:  \n";
        cin>>password;

        if(email == "pragatikapoor@gmail.com" && password == "pragati#123")
        {
            administrator();
        }
        else
        {
            cout<<"**Invalid Email/Password**";
            cout<<endl;
        }
        break;
    
    case 2:
        customer();
        break; 

    case 3:
        exit(0);

    default:
        cout<<"Invalid Option!";
        cout<<endl;
    }
goto MainMenu;
}                                              

void SuperMarket :: administrator()         
{                                                  
AdminMenu: 
    int option;
    cout<<"\t\t\t--------Administrator Menu--------\n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t||  (1) Add The Product         ||\n";
    cout<<"\t\t\t||                              ||\n";
    cout<<"\t\t\t||  (2) Remove The Product      ||\n";
    cout<<"\t\t\t||                              ||\n";
    cout<<"\t\t\t||  (3) Modify The Product      ||\n";
    cout<<"\t\t\t||                              ||\n";
    cout<<"\t\t\t||  (4) Back To The Main Menu   ||\n";

    cout<<"Please Select from the given options: ";
    cin>>option;

    switch(option)
    {
        case 1: 
            add_product();
            break;
        case 2:
            remove_product();
            break;
        case 3:
            modify_product();
            break;
        case 4:
            main_menu();
            break;
        default:
            cout<<"Invalid Option!";
            cout<<endl;

    }
goto AdminMenu;
}                                          

void SuperMarket :: customer()
{                                          
CustomerMenu:
    int option;
    cout<<"\t\t\t-----------Customer Menu-----------\n";
    cout<<"\t\t\t                                   \n";
    cout<<"\t\t\t||    (1) Buy Product             ||\n";
    cout<<"\t\t\t||                                ||\n";
    cout<<"\t\t\t||    (2) Go Back                 ||\n";
    cout<<"\t\t\t||                                ||\n";

    cout<<"Please Select from the given options: ";
    cin>>option;

    switch(option)
    {
        case 1:
            receipt();
            break;
        case 2:
            main_menu();
            
        default:
            cout<<"Invalid Option!";
            cout<<endl;
    }
goto CustomerMenu;
}                                          

void SuperMarket :: add_product()
{                                          
addingProduct:
    fstream data;
    int p_code;
    string p_name;
    float p_price;
    float p_discount;
    int token =0;

    cout<<"\n\t\t\t---Add New Product---\t\t\t\n";
    cout<<"Enter Product Code of the product:\n";
    cin>>product_code;
    cout<<"Enter Name of the product: \n";
    cin>>product_name;                         
    cout<<"Enter Price of the product: \n";
    cin>>product_price;
    cout<<"Enter Discount on the product: \n";
    cin>>discount;

    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";
        data.close();
    }
    else{
        data>>p_code>>p_name>>p_price>>p_discount;

        while(!data.eof())
        {
            if(p_code==product_code)
            {
                token++;
            }
            data>>p_code>>p_name>>p_price>>p_discount;
        }
        data.close();

        if(token==1){
            cout<<"Product already exist!\n";
            cout<<"Add different Product Code\n";
        goto addingProduct;
        }
        else
        {
        data.open("database.txt", ios::app | ios::out);
        data<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";
        data.close();
        }
    }
    cout<<"\n\t\t Product Added! \t\t\n\n";
    cout<<endl;
}                                          

void SuperMarket :: modify_product()
{
fstream data, data1;
    int product_key;
    int p_code;
    string p_name;
    float p_price;
    float p_discount;
    int token = 0;

    cout<<"\n\t\t\t---Modify The Product---\t\t\t";
    cout<<"\n Enter Product Code of the product you want to modify: \n";
    cin>>product_key;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n File does not exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data>>product_code>>product_name>>product_price>>discount;

        while(!data.eof())
        {
            if(product_key == product_code)
            {
                cout<<"Enter the details of the Product you want to modify!\n";
                cout<<"Enter Product Code of the product:\n";
                cin>>p_code;
                cout<<"Enter Name of the product: \n";
                cin>>p_name;
                cout<<"Enter Price of the product: \n";
                cin>>p_price;
                cout<<"Enter Discount on the product: \n";
                cin>>p_discount;
                data1<<" "<<p_code<<" "<<p_name<<" "<<p_price<<" "<<p_discount<<"\n";
                cout<<"\n\t\t Product Modified!\n\n";
                token ++;
            }

            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";         
            }
            data>>product_code>>product_name>>product_price>>discount;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\t\t Product Not Found! \t\t";
            cout<<endl;
        }
    }
}


void SuperMarket :: remove_product()
{
    fstream data, data1;
    int product_key;
    int token=0;
    cout<<"\n\t\t\t---Remove Product---\t\t\t\n";
    cout<<"Enter Product Code of the product you want to remove: \n";
    cin>>product_key;
    
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File does not exist";

    }
    else
    {
        data1.open("database1.txt", ios::app | ios:: out);
        data>>product_code>>product_name>>product_price>>discount;
        while(!data.eof())
        {
            if(product_code==product_key)
            {
                cout<<"\n\t\t Product Removed Successfully! \t\t\n\n";
                token ++;
            }
            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<product_price<<" "<<discount<<"\n";
            }
            data>>product_code>>product_name>>product_price>>discount;
        }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\t Product Not Found!\n";
            cout<<endl;
            cout<<endl;
        }

    }
}


void SuperMarket :: list()
{
    fstream data;
    data.open("database.txt", ios:: in);
    cout<<"\n\n_____________________________________________\n";
    cout<<"Product No:\tName\t\tPrice";
    cout<<"\n\n_____________________________________________\n";
    data>>product_code>>product_name>>product_price>>discount;
    while(!data.eof())
    {
        cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<product_price<<"\n";
        data>>product_code>>product_name>>product_price>>discount;
    }
    data.close();
}

void SuperMarket :: receipt()
{

    fstream data;
    int product_codes[100];
    int quantity[100];
    int count = 0;
    float amount = 0;
    float discount = 0;
    float sum = 0;
    char choice;


    cout<<"\n\t\t----------LIST OF THE PRODUCTS----------\t";
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"The database is empty!\n\n";
    }

    else
    {
        data.close();
        
        list();
        cout<<"\n----------------------------------------\n";
        cout<<"\n                                        \n";
        cout<<"\n         Please Place The Order!        \n";
        cout<<"\n                                        \n";
        cout<<"\n----------------------------------------\n";


       do
       {
        PlaceOrder: 
        cout<<"\n Enter Product Code: ";
        cin>>product_codes[count];
        cout<<"\n Enter the Product Quantity: ";
        cin>>quantity[count];
        for(int i=0; i<count; i++)
        {
            if(product_codes[count] == product_codes[i])
            {
                cout<<"\n You have already entered this product code!\n";
                cout<<"Please try again";
                goto PlaceOrder;
            }
        }
        count ++;
        y_n:

        cout<<"\n\t Do you want to buy another product?";
        cout<<"\n\t If YES then press y, If NO then press n\n";
        cin>>choice;
        if(choice == 'n')
        {
            goto receipt;
        }

        else if(choice != 'y' && choice != 'n')
        {
            cout<<"INVALID CHOICE!";
            goto y_n;
        }
       } while (choice == 'y');

     receipt: 

       cout<<"\n\t\t---------------RECEIPT---------------\n";
       cout<<"\nProduct No.\tProduct Name\tQuantity\tPrice\t\tAmount\t\tAmount after Discount\n";

       for(int i=0; i<count; i++)
       {
        data.open("database.txt", ios::in);
        data>>product_code>>product_name>>product_price>>discount;
        while(!data.eof()) 
        {
            if(product_code == product_codes[i])
            {
                amount = product_price*quantity[i];
                discount = amount - (amount * discount/100);
                sum = sum + discount;
                cout<<"\n"<<product_code<<"\t\t"<<product_name<<"\t\t"<<quantity[i]<<"\t\t"<<product_price<<"\t\t"<<amount<<"\t\t"<<discount;
            }
             data>>product_code>>product_name>>product_price>>discount;
        }
        data.close();

       }
    cout<<"\n\n---------------------------------------";
    cout<<fixed<<setprecision(1);
    cout<<"\n Total Amount: "<<sum;
    cout<<endl;
    cout<<endl;
    }

}

int main()
{
    SuperMarket user;
    user.main_menu();

    return 0;
}
