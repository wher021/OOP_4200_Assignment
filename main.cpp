#include <iostream>
#include "Product.h"
#include "Movie.h"
#include "Cellphones.h"
#include "Computer.h"
#include <list>
#include <fstream>
#include <string>

namespace myEnums
{
    enum MainMenu {Movies = 1, Computers = 2, Cellphones = 3, Search = 4};
    enum ProductCodes {Horror = 1, Action = 2,Desktop = 3, Laptop = 4,Apple = 5, Samsung = 6 };
    enum ActionMenu {Add = 1, Modify = 2, Delete = 3, Print = 4};
}

std::list<Product*> myList;

//Utility functions...Should have been a seperate Database Class
void MainMenuInput(int &usr_input);
void SubMenuInput(int &usr_input);
void Options(int &,int);
void ValidateOptionsMenuInput(int &usr_input);
void DisplayProductGroup(int);
int AutoGenerateProductId(int type);
void DeleteProducts(int &usr_input);
void ModifyProducts(int &usr_input);
void ProductSearch();
void Print(int &);
void checkProductType(int &type, int &minid ,int &maxid);
void AddProduct(Product *newProduct,int id);
static void Database_Initialization();//static only resides in this textfile

int main()
{
    Database_Initialization();

    while(1)
    {
        int usr_input;
        std::cout<<"==================================================================="<<std::endl;
        std::cout<<"Welcome to the Main Menu choose product group or use the search function \nby entering the corresponding code number and hit enter"<<std::endl;
        std::cout<<"Movies(1)  Computers(2)    Cellphones(3)    Search(By Title)(4)"<<std::endl;

        MainMenuInput(usr_input);

        if(usr_input==myEnums::Movies)
        {
            std::cout<<"Horror_Movies(1)    Action_Movies(2)"<<std::endl;
            SubMenuInput(usr_input);
            if(usr_input == 1)
            {
                DisplayProductGroup(myEnums::Horror);
                Options(usr_input,myEnums::Horror);
            }
            else if(usr_input == 2)
            {
                DisplayProductGroup(myEnums::Action);
                Options(usr_input,myEnums::Action);
            }
        }
        else if(usr_input==myEnums::Computers)
        {
            std::cout<<"Desktop(1)    Laptop(2)"<<std::endl;
            SubMenuInput(usr_input);
            if(usr_input == 1)
            {
                DisplayProductGroup(myEnums::Desktop);
                Options(usr_input,myEnums::Desktop);
            }
            else if(usr_input == 2)
            {
                DisplayProductGroup(myEnums::Laptop);
                Options(usr_input,myEnums::Laptop);
            }
        }
        else if(usr_input==myEnums::Cellphones)
        {
            std::cout<<"Apple(1)    Samsung(2)"<<std::endl;
            SubMenuInput(usr_input);
            if(usr_input == 1)
            {
                DisplayProductGroup(myEnums::Apple);
                Options(usr_input,myEnums::Apple);
            }
            else if(usr_input == 2)
            {
                DisplayProductGroup(myEnums::Samsung);
                Options(usr_input,myEnums::Samsung);
            }

        }
        else if(usr_input==myEnums::Search)
        {
            std::cout<<"Enter Product Name to Search(this is not case-sensitive)"<<std::endl;
            ProductSearch();
        }
    }
    return 0;
}

void Options(int &usr_input,int type)
{
    std::cout<<"Add(1)  Modify(2)   Buy(Deletes from Quantity)(3)   Print(4)"<<std::endl;
    ValidateOptionsMenuInput(usr_input);
    int id = 0;
    Product *newProduct;

    if(usr_input == myEnums::Add)
    {
        if(type == myEnums::Horror)
        {
            Horror_Movie *nHM = new Horror_Movie();
            newProduct = nHM;
            id = AutoGenerateProductId(type);
            AddProduct(newProduct,id);
        }
        else if(type == myEnums::Action)
        {
            Action_Movie *nAM = new Action_Movie();
            newProduct = nAM;
            id = AutoGenerateProductId(type);
            AddProduct(newProduct,id);
        }
        else if(type == myEnums::Desktop)
        {
            Desktop *nDesk = new Desktop();
            newProduct = nDesk;
            id = AutoGenerateProductId(type);
            AddProduct(newProduct,id);
        }
        else if(type == myEnums::Laptop)
        {
            Laptop *nLap = new Laptop();
            newProduct = nLap;
            id = AutoGenerateProductId(type);
            AddProduct(newProduct,id);
        }
        else if(type == myEnums::Apple)
        {
            Apple *nApp = new Apple();
            newProduct = nApp;
            id = AutoGenerateProductId(type);
            AddProduct(newProduct,id);
        }
        else if(type == myEnums::Samsung)
        {
            Samsung *nSam = new Samsung();
            newProduct = nSam;
            id = AutoGenerateProductId(type);
            AddProduct(newProduct,id);
        }
        myList.push_front(newProduct);
        DisplayProductGroup(type);//Display based on type of product
    }
    else if(usr_input == myEnums::Modify)
    {
        while(1)
        {
            std::cout<<"enter the pid of the product you wish to modify or enter (q) to return"<<std::endl;
            std::cin>>usr_input;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                break;
            }
            if(type == myEnums::Horror)
            {
                ModifyProducts(usr_input);
                DisplayProductGroup(myEnums::Horror);
            }
            else if(type == myEnums::Action)
            {
                ModifyProducts(usr_input);
                DisplayProductGroup(myEnums::Action);
            }
            else if(type == myEnums::Desktop)
            {
                ModifyProducts(usr_input);
                DisplayProductGroup(myEnums::Desktop);
            }
            else if(type == myEnums::Laptop)
            {
                ModifyProducts(usr_input);
                DisplayProductGroup(myEnums::Laptop);
            }
            else if(type == myEnums::Apple)
            {
                ModifyProducts(usr_input);
                DisplayProductGroup(myEnums::Apple);
            }
            else if(type == myEnums::Samsung)
            {
                ModifyProducts(usr_input);
                DisplayProductGroup(myEnums::Samsung);
            }
        }
    }
    else if(usr_input == myEnums::Delete)
    {
        while(1)
        {
            std::cout<<"enter the pid of the product you wish to buy(delete) or press (q) to return"<<std::endl;
            std::cin>>usr_input;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                break;
            }
            if(type == myEnums::Horror)
            {
                DeleteProducts(usr_input);
                DisplayProductGroup(myEnums::Horror);
            }
            else if(type == myEnums::Action)
            {
                DeleteProducts(usr_input);
                DisplayProductGroup(myEnums::Action);
            }
            else if(type == myEnums::Desktop)
            {
                DeleteProducts(usr_input);
                DisplayProductGroup(myEnums::Desktop);
            }
            else if(type == myEnums::Laptop)
            {
                DeleteProducts(usr_input);
                DisplayProductGroup(myEnums::Laptop);
            }
            else if(type == myEnums::Apple)
            {
                DeleteProducts(usr_input);
                DisplayProductGroup(myEnums::Apple);
            }
            else if(type == myEnums::Samsung)
            {
                DeleteProducts(usr_input);
                DisplayProductGroup(myEnums::Samsung);
            }
        }
    }
    else if(usr_input == myEnums::Print)
    {
        std::cout<<"printing"<<std::endl;
        Print(type);
        std::cout << "File successfully created." << std::endl;
    }
}

void MainMenuInput(int &usr_input)
{
    while (!(std::cin >> usr_input) || (usr_input != myEnums::Movies && usr_input != myEnums::Computers && usr_input != myEnums::Cellphones && usr_input != myEnums::Search))
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid input.  Try again: ";
    }
}

void SubMenuInput(int &usr_input)
{
    if(!(std::cin >> usr_input))
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    while ((usr_input != 1 && usr_input != 2))
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid input.  Try again: ";
        std::cin >> usr_input;
    }
}

void ValidateOptionsMenuInput(int &usr_input)
{
    if(!(std::cin >> usr_input))
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    while ((usr_input != myEnums::Add && usr_input != myEnums::Modify && usr_input != myEnums::Delete && usr_input != myEnums::Print))
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid input.  Try again: ";
        std::cin >> usr_input;
    }
}

void DisplayProductGroup(int type)
{
    int min_id;
    int max_id;

    checkProductType(type,min_id,max_id);
    std::cout<<"==========Displaying Product List============"<<std::endl;
    for(std::list<Product*>::iterator list_iter = myList.begin(); list_iter != myList.end(); list_iter++)
    {
        if((*list_iter)->getProductId() > min_id && (*list_iter)->getProductId() < max_id)
            (*list_iter)->Display();
    }
    std::cout<<std::endl;
}

int AutoGenerateProductId(int type)
{
    int newId = 0;
    int tmp = 0;
    int min_id;
    int max_id;

    checkProductType(type,min_id,max_id);

    for(std::list<Product*>::iterator list_iter = myList.begin(); list_iter != myList.end(); list_iter++)
    {
        if((*list_iter)->getProductId() > min_id && (*list_iter)->getProductId() < max_id)
        {
            tmp = (*list_iter)->getProductId();
            if(tmp > newId)
                newId = tmp;
        }
    }
    return newId + 1;
}

void DeleteProducts(int &usr_input)
{
    for(std::list<Product*>::iterator list_iter = myList.begin(); list_iter != myList.end(); list_iter++)
    {
        if((*list_iter)->getProductId() == usr_input)
        {
            if((*list_iter)->getQuantity() == 0)
            {
                static std::string tmp = (*list_iter)->getProductName();
                (*list_iter)->setProductName(tmp + " "+"(Out of Stock!)");
                break;
            }
            else
            {
                int update_quantity = (*list_iter)->getQuantity() - 1;
                (*list_iter)->setQuantity(update_quantity);
                break;
            }
            //myList.erase(list_iter);
        }
    }
}

void ModifyProducts(int &usr_input)
{
    bool found = false;
    for(std::list<Product*>::iterator list_iter = myList.begin(); list_iter != myList.end(); list_iter++)
    {
        if((*list_iter)->getProductId() == usr_input)
        {
            std::cout<<"***Modifying Product***"<<std::endl;
            found = true;
            (*list_iter)->Display();
            std::cout<<"enter new name:"<<std::endl;
            std::string string_input="";
            std::cin>>string_input;
            (*list_iter)->setProductName(string_input);
            std::cout<<"enter manufacturer/publisher:"<<std::endl;
            std::cin>>string_input;
            (*list_iter)->setManufacturer(string_input);
            std::cout<<"enter quantity:"<<std::endl;
            int quantity;
            std::cin>>quantity;
            (*list_iter)->setQuantity(quantity);
            //(*list_iter)->setQuantity(std::stoi(string_input));
        }
    }
    if(!found)
    {
        std::cout<<"Sorry the productid:"<<usr_input<<" "<<"does not exist"<<std::endl;
    }
}

void ProductSearch()
{
    std::string my_search="";
    std::string my_upper="";
    std::cin>>my_search;
    my_search = my_search.substr(0,2);
    std::locale loc;
    bool match = false;
    for (std::string::size_type i=0; i<my_search.length(); i++)//Why does this not grab blank space?????
    {
        my_upper += std::toupper(my_search[i],loc);
    }

    for(std::list<Product*>::iterator list_iter = myList.begin(); list_iter != myList.end(); list_iter++)
    {
        my_search = "";
        std::string pname = (*list_iter)->getProductName();
        pname = pname.substr(0,2);
        for (std::string::size_type i=0; i< pname.length(); i++)
        {
            my_search  += std::toupper(pname[i],loc);
        }
        if(my_upper == my_search)
        {
            match = true;
            std::cout<<"Found Match"<<std::endl;
            (*list_iter)->Display();
        }
    }
    if(!match)
        std::cout<<"Sorry could not find a match"<<std::endl;
}

void Print(int &type)
{
    int min_id;
    int max_id;
    checkProductType(type,min_id,max_id);

    std::ofstream outfile;
    std::string s = "Printout";
    s += ".txt";
    outfile.open(s.c_str(), std::ios::out);
    if (!outfile);
        //throw "Error creating output file.";
    if(type == myEnums::Horror)
    {
        outfile <<"Horror Movies"<<std::endl;
        outfile <<"============="<<std::endl;
    }
    else if(type == myEnums::Desktop)
    {
        outfile <<"Desktops"<<std::endl;
        outfile <<"============="<<std::endl;
    }
    else if(type == myEnums::Laptop)
    {
        outfile <<"Laptops"<<std::endl;
        outfile <<"============="<<std::endl;
    }
    else if(type == myEnums::Apple)
    {
        outfile <<"Apple"<<std::endl;
        outfile <<"============="<<std::endl;
    }
    else if(type == myEnums::Samsung)
    {
        outfile <<"Samsung"<<std::endl;
        outfile <<"============="<<std::endl;
    }
    for(std::list<Product*>::iterator list_iter = myList.begin(); list_iter != myList.end(); list_iter++)
    {
        if((*list_iter)->getProductId() > min_id && (*list_iter)->getProductId() < max_id)
        {
            outfile <<"PID="<<(*list_iter)->getProductId()<<"   "<<"Pname="<< (*list_iter)->getProductName()<<"   "<<"Quantity="<<
            (*list_iter)->getQuantity()<< std::endl;
        }
    }
    outfile.close();
}
void checkProductType(int &type, int &minid ,int &maxid)
{
    if(type == myEnums::Horror)//needs to be completed
    {
        minid = 1000;
        maxid = 2000;
    }
    else if(type == myEnums::Action)//needs to be completed
    {
        minid = 2000;
        maxid = 3000;
    }
    else if(type == myEnums::Laptop)//needs to be completed
    {
        minid = 3000;
        maxid = 4000;
    }
    else if(type == myEnums::Desktop)//needs to be completed
    {
        minid = 4000;
        maxid = 5000;
    }
    else if(type == myEnums::Apple)//needs to be completed
    {
        minid = 5000;
        maxid = 6000;
    }
    else if(type == myEnums::Samsung)//needs to be completed
    {
        minid = 6000;
        maxid = 7000;
    }
}

void AddProduct(Product *newProduct,int id)
{
    std::cout<<"***Adding New Product***"<<std::endl;
    newProduct->setProductId(id);
    std::cout<<"enter product name:"<<std::endl;
    std::string text;
    std::cin>>text;
    newProduct->setProductName(text);
    std::cout<<"enter manufacturer/distributor:"<<std::endl;
    std::cin>>text;
    newProduct->setManufacturer(text);
    std::cout<<"enter quantity:"<<std::endl;
    int quantity;
    std::cin>>quantity;
    newProduct->setQuantity(quantity);
}

static void Database_Initialization()
{
    //Product *test;

    Apple *myApple1 = new Apple("Iphone 6",5001,"Apple",3,"BLACK",6 ,"4G", "10h", true);
    Apple *myApple2 = new Apple("Iphone 5",5002,"Apple",5,"SILVER",5 ,"4G", "8h", true);
    Apple *myApple3 = new Apple("Iphone 5S",5003,"Apple",3,"GOLD",5 ,"4G", "8h", true);
    Apple *myApple4 = new Apple("Iphone 4S",5004,"Apple",7,"WHITE",5 ,"4G", "7h", true);
    Apple *myApple5 = new Apple("Iphone 3S",5005,"Apple",3,"BLACK",4 ,"3G", "4h", true);

    myList.push_front(myApple1);
    myList.push_front(myApple2);
    myList.push_front(myApple3);
    myList.push_front(myApple4);
    myList.push_front(myApple5);

    //test = myApple5;
    //test->Display();

    Samsung *mySamsung1 = new Samsung("Samsung S5",6001,"Samsung",7,"White",7,"4G", "7h", true);
    Samsung *mySamsung2 = new Samsung("Samsung S4",6002,"Samsung",5,"White",6,"4G", "6h", true);
    Samsung *mySamsung3 = new Samsung("Samsung S3",6003,"Samsung",4,"White",5,"3G", "6h", true);
    Samsung *mySamsung4 = new Samsung("Samsung S2",6004,"Samsung",3,"White",5,"3G", "5h", false);
    Samsung *mySamsung5 = new Samsung("Samsung S1",6005,"Samsung",2,"Black",5,"3G", "4h", false);
    myList.push_front(mySamsung1);
    myList.push_front(mySamsung2);
    myList.push_front(mySamsung3);
    myList.push_front(mySamsung4);
    myList.push_front(mySamsung5);

    Desktop *myDesktop1 = new Desktop("IBM_mini", 4001,"IBM",2,"Desktop", "Black", "Intel I5", 4096, 512, true);
    Desktop *myDesktop2 = new Desktop("HP_mini", 4002,"HP",2,"Desktop", "Black", "Intel I5", 4096, 512, true);
    Desktop *myDesktop3 = new Desktop("Lenovo_std", 4003,"Lenovo",1,"Desktop", "Black", "Intel I3", 2096, 512, false);
    Desktop *myDesktop4 = new Desktop("Asus_mini", 4004,"Asus",4,"Desktop", "Black", "Intel I7", 8096, 1024, true);
    Desktop *myDesktop5 = new Desktop("Compaq_std", 4005,"Compaq",3,"Desktop", "Black", "Intel I7", 8096, 2048, false);
    myList.push_front(myDesktop1);
    myList.push_front(myDesktop2);
    myList.push_front(myDesktop3);
    myList.push_front(myDesktop4);
    myList.push_front(myDesktop5);

    Laptop *myLaptop1 = new Laptop("Ideapad", 3001,"Lenovo",10, "Laptop", "Black", "Intel I7", 8096, 512, 15, true);
    Laptop *myLaptop2 = new Laptop("Surface Pro", 3002,"Microsoft",9, "Laptop", "Silver", "Intel I5", 4096, 512, 14, true);
    Laptop *myLaptop3 = new Laptop("Blizzard", 3003,"Samsung",8, "Laptop", "Black", "Intel I5", 4096, 256, 13, true);
    Laptop *myLaptop4 = new Laptop("Rocket", 3004,"HP",7, "Laptop", "Silver", "Intel I5", 4096, 256, 15, false);
    Laptop *myLaptop5 = new Laptop("Accender", 3005,"Asus",6, "Laptop", "Black", "Intel I3", 4096, 256, 15, false);
    myList.push_front(myLaptop1);
    myList.push_front(myLaptop2);
    myList.push_front(myLaptop3);
    myList.push_front(myLaptop4);
    myList.push_front(myLaptop5);
//Action_Movie(string pname, int pid, string distributor, float price, string genre, int age, int length, int af):Movie(pname,pid,distributor,price,genre,age,length)
    Action_Movie *myAction1 = new Action_Movie("Die Hard",2001,"Tri-Star",2,"action",15,3,8);
    Action_Movie *myAction2 = new Action_Movie("Die Hard 2",2002,"Tri-Star",2,"action",15,2,8);
    Action_Movie *myAction3 = new Action_Movie("Rocky",2003,"Universal",2,"action",15,2,8);
    Action_Movie *myAction4 = new Action_Movie("Rocky 2",2004,"Universal",2,"action",15,1,9);
    Action_Movie *myAction5 = new Action_Movie("Terminator",2005,"Buena Vista",2,"action",15,2,10);
    myList.push_front(myAction1);
    myList.push_front(myAction2);
    myList.push_front(myAction3);
    myList.push_front(myAction4);
    myList.push_front(myAction5);
//Horror_Movie(string pname, int pid, string distributor, int quantity, string genre, int age, int length, int sf):Movie(pname,pid,distributor,price,genre,age,length)
    Horror_Movie *myHorror1 = new Horror_Movie("Scream",1001,"BuenaVista",2,"horror",15,2,7);
    Horror_Movie *myHorror2 = new Horror_Movie("Scream 2",1002,"BuenaVista",2,"horror",15,2,7);
    Horror_Movie *myHorror3 = new Horror_Movie("Halloween h20",1003,"BuenaVista",5,"horror",15,2,7);
    Horror_Movie *myHorror4 = new Horror_Movie("The Grudge",1004,"BuenaVista",8,"horror",15,2,8);
    Horror_Movie *myHorror5 = new Horror_Movie("Exorcist",1005,"BuenaVista",3,"horror",18,2,10);
    myList.push_front(myHorror1);
    myList.push_front(myHorror2);
    myList.push_front(myHorror3);
    myList.push_front(myHorror4);
    myList.push_front(myHorror5);
}



