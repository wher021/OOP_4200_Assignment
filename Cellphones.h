class CellPhones:public Product
{
    public:
        CellPhones(std::string, int, std::string, int, std::string, int, std::string, std::string);//forsta fyra kommer fran product
        CellPhones();
    protected:
        std::string color;
        int screen_size;
        std::string network_type;
        std::string battery_life;
};
CellPhones::CellPhones()
{
    color = "";
    screen_size = 0;
    network_type = "";
    battery_life = "";
}

CellPhones::CellPhones(std::string pname, int pnum, std::string manu, int quantity, std::string c, int s, std::string n, std::string b):Product(pname,pnum,manu,quantity)
{
    color = c;
    screen_size = s;
    network_type = n;
    battery_life = b;
}

class Apple:public CellPhones
{
    public:
        Apple();
        Apple(std::string, int, std::string, int, std::string, int, std::string, std::string, bool);
        void Display()
        {
            std::cout<<"PID="<<productid<<"   "<<"Pname="<<name<<"  "<<"Has Siri_Support:"<<" "<<Siri_Support<<std::endl;
        }
        void setname()
        {
            productid = 22;
        }
    private:
        bool Siri_Support;
};
Apple::Apple()
{
    Siri_Support = false;
}

Apple::Apple(std::string pname,int pnum, std::string manu, int quantity, std::string c, int s, std::string n, std::string b, bool siri):CellPhones(pname,pnum,manu,quantity,c,s,n,b)
{
    Siri_Support = siri;
}

class Samsung:public CellPhones
{
    public:
        void Display()
        {
            std::cout<<"PID="<<productid<<"   "<<"Pname="<<name<<"  "<<"Has UMI interface:"<<" "<<Usb_Micro_Interface<<std::endl;
        }
        Samsung();
        Samsung(std::string, int, std::string, int, std::string, int, std::string, std::string, bool);
    private:
        bool Usb_Micro_Interface;
};
Samsung::Samsung()
{
    Usb_Micro_Interface = false;
}

Samsung::Samsung(std::string pname,int pnum,std::string manu,int quantity,std::string c, int s, std::string n, std::string b, bool UMI):CellPhones(pname,pnum,manu,quantity,c,s,n,b)
{
    Usb_Micro_Interface = UMI;
}


