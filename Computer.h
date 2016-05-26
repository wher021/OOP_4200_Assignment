class Computer:public Product
{
    public:
        Computer(std::string,int,std::string,int,std::string,std::string,std::string,int,int);//dom fyra forsta fran Product
        Computer();
    protected:
        std::string computer_form;
        std::string color;
        std::string processor_type;
        int ram_size;
        int harddrive_size;
};
Computer::Computer()
{
    computer_form = "";
    color = "";
    processor_type = "";
    ram_size = 0;
    harddrive_size = 0;

}

Computer::Computer(std::string pname,int pid,std::string manu, int quantity, std::string cf, std::string c, std::string p_type, int rs, int hs):Product(pname,pid,manu,quantity)
{
    computer_form = cf;
    color = c;
    processor_type = p_type;
    ram_size = rs;
    harddrive_size = hs;
}

class Laptop:public Computer
{
    public:
        void Display()
        {
            std::cout<<"PID="<<productid<<"   "<<"Pname="<<name<<"  "<<"Manufacturer="<<manufacturer<<"   "<<"Quantity="<<quantity<<std::endl;
        }
        Laptop();
        Laptop(std::string,int,std::string,int,std::string,std::string,std::string,int,int,int,bool);
    private:
        int screen_size;
        bool touch_screen;
};
Laptop::Laptop(std::string pname,int pid,std::string manu,int quantity, std::string cf,std::string c,std::string p_type,int rs,int hs,int ss,bool ts):Computer(pname,pid,manu,quantity,cf,c,p_type,rs,hs)
{
    screen_size = ss;
    touch_screen = ts;
}
Laptop::Laptop():Computer()
{
    screen_size = 0;
    touch_screen = false;
}

class Desktop:public Computer
{
    public:
        void Display()
        {
            std::cout<<"PID="<<productid<<"   "<<"Pname="<<name<<"  "<<"Manufacturer="<<manufacturer<<"   "<<"Quantity="<<quantity<<std::endl;
        }
        Desktop();
        Desktop(std::string,int,std::string,int,std::string,std::string,std::string,int,int,bool);
    private:
        bool mini_tower;
};
Desktop::Desktop()
{
    mini_tower = false;
}
Desktop::Desktop(std::string pname,int pid,std::string manu,int quantity,std::string cf,std::string c,std::string p_type,int rs,int hs, bool mt):Computer(pname,pid,manu,quantity,cf,c,p_type,rs,hs)
{
    mini_tower = mt;
}
