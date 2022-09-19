#include<bits/stdc++.h>
using namespace std;

class shopping{

private:
    int pcode;   //product code
    float price; //product price
    float dis;   // discount on product
    string pname;//product name

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\n\t\t\t\t\t____________________________________________________\n";
    cout<<"\t\t\t\t\t                                                      \n";
    cout<<"\t\t\t\t\t                  Billing System                      \n";
    cout<<"\t\t\t\t\t______________________________________________________\n";
    cout<<"\t\t\t\t\t|                                                    |\n";
    cout<<"\t\t\t\t\t|                                                    |\n";
    cout<<"\t\t\t\t\t|  1) Administrator(Press 1 for administrator)       |\n";
    cout<<"\t\t\t\t\t|                                                    |\n";
    cout<<"\t\t\t\t\t|  2) Buyer(Press 2 for buyer)                       |\n";
    cout<<"\t\t\t\t\t|                                                    |\n";
    cout<<"\t\t\t\t\t|  3) Exit(Press 3 to exit)                          |\n";
    cout<<"\n\t\t\t\t\t\t\tPlease Enter your Choice :  ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\n\n\t\t\t\t\t Please Enter Login Credentials: \n";
        cout<<"\t\t\t Enter Email:";
        cin>>email;
        cout<<"\t\t\t Enter Password:";
        cin>>password;

        if(email == "mridul@gmail.com"  && password == "password")
        {
            administrator();
        }
        else
        {
            cout<<"\n\n\t\t\t\tInvalid Email/Password....!!!!";

        }
        break;
    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }
    default:
        {
            cout<<"\n\n\t\t\t\tPlease Select From the Given Options: ";
        }
    }
goto m;
}

void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t\t\t\t\tAdministrator menu  ";
    cout<<"\n\t\t\t\t\t\t|______1) Add the Product__________|";
    cout<<"\n\t\t\t\t\t\t|                                  |";
    cout<<"\n\t\t\t\t\t\t|______2) Modify the Product_______|";
    cout<<"\n\t\t\t\t\t\t|                                  |";
    cout<<"\n\t\t\t\t\t\t|______3) Delete the Product_______|";
    cout<<"\n\t\t\t\t\t\t|                                  |";
    cout<<"\n\t\t\t\t\t\t|______4) Back to the Main Menu____|";

    cout<<"\n\n\t\t\t\t\t  Please Enter your choice ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid Choice...!!!";
    }

    goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<"\n\n\t\t\t\t\t\t\t   BUYER             \n";
    cout<<"\t\t\t\t\t\t___________________________\n";
    cout<<"                                     ";
    cout<<"\n\t\t\t\t\t\t   1) Buy Product        \n";
    cout<<"                                     ";
    cout<<"\n\t\t\t\t\t\t   2) Go Back            \n";
    cout<<"\n\t\t\t\t\t\t   Enter Your Choice :     ";

    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();

    default:
        cout<<"\n\n\t\t\t\t\tInvalid Choice ..!!";
    }

    goto m;
}

//ios::in will open the file in reading mode
//ios::out will open the file in writing mode

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t  Add New Product :";
    cout<<"\n\n\t\t\t 1)Product Code of the product :";
    cin>>pcode;
    cout<<"\n\n\t\t\t 2)Name of the product :";
    cin>>pname;
    cout<<"\n\n\t\t\t 3)Price of the product :";
    cin>>price;
    cout<<"\n\n\t\t\t 4)Discount on product :";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token == 1)
        {
            cout<<"\n\n\t\t\t\tProduct is same..!!Please Enter again\n";

            goto m;

        }
        else
        {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
        }

    }
    cout<<"\n\n\n\t\t\t\tRecord Inserted...!!";
}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t Modify The Record : ";
    cout<<"\n\n\t\t\t\t Product Code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't exist !";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t\t\t\t Product new code :";
                cin>>c;
                cout<<"\n\n\t\t\t\tName of the product :";
                cin>>n;
                cout<<"\n\n\t\t\t\t Price :";
                cin>>p;
                cout<<"\n\n\t\t\t\t\tDiscount:";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t\t\t Record Edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t\t\tRecord not found sorry!";
        }

    }
}
void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;

    cout<<"\n\n\t\t\t\t Remove The Record : ";
    cout<<"\n\n\t\t\t\t Product Code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't exist !";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t\t\t\t Product Deleted Successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t\t\tRecord not found sorry!";
        }

    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\t\t\t\t\t___________________________________________\n";
    cout<<"\n\t\t\t\t\tProNo\t\tName\t\tPrice\n";
    cout<<"\n\t\t\t\t\t___________________________________________\n";
    data>>pcode>>pname>>price>>dis;

    while(!data.eof())
    {
        cout<<"\t\t\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}


void shopping::receipt()
{
    fstream data;

    int arrc[1000];  //array of product code
    int arrq[1000];  //array of product quantity
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n\t\t\t\t\t\t\t  Product List    ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n\t\t\t\t\t Empty Database";
    }
    else
    {
        data.close();

        list();
        cout<<"\n\n\n\t\t\t\t\t__________________________________________\n";
        cout<<"\t\t\t\t\t                                          \n";
        cout<<"\n\t\t\t\t\t       Please place the order             \n";
        cout<<"\n\t\t\t\t\t__________________________________________\n";

        do
        {
            m:
            cout<<"\n\t\t\t\t\tEnter Product Code : ";
            cin>>arrc[c];
            cout<<"\n\t\t\t\t\tEnter the product quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n\t\t\t\tDuplicate product code.Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n\t\t\t\tDo you want to but another product?If yes press 'y' else press 'n' : ";
            cin>>choice;
        }
        while(choice == 'y');

      cout<<"\n\n\t\t\t\t                        RECEIPT                              \n\n";
      cout<<"\n\t\t_______________________________________________________________________________________________\n\n";
      cout<<"\t\tProduct No\t Product Name \t Product Quantity \t Price \t Amount\t  Amount with discount \n";

      for(int i=0;i<c;i++)
      {

          data.open("database.txt",ios::in);

          data>>pcode>>pname>>price>>dis;

          while(!data.eof())
          {
              if(pcode == arrc[i])
              {
                  amount = price*arrq[i];
                  dis = amount - (amount*dis/100);
                  total = total + dis;
                  cout<<"\t\t "<<pcode<<"\t\t"<<"   "<<pname<<"\t\t"<<arrq[i]<<"\t\t  "<<price<<" \t  "<<amount<<"\t   "<<dis<<"\n";


              }
              data>>pcode>>pname>>price>>dis;
          }
          data.close();
      }

      data.close();
    }
   cout<<"\n\t\t______________________________________________________________________________________________\n\n";
   cout<<"\n\t\t\t\tTotal Amount : " <<total;

}

int main()
{
    shopping s;
    s.menu();
}
