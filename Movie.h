class Movie:public Product
{
    public:
        Movie(std::string,int,std::string,int,std::string,int,int);//first four are from Product
        Movie();
    protected:
        std::string genre;
        int age_rating;
        int movie_length;
};

Movie::Movie(std::string pname, int pid, std::string distributor, int quantity, std::string genre, int age, int length):Product(pname,pid,distributor,quantity)
{
    this->genre = genre;
    age_rating = age;
    movie_length = length;
}
Movie::Movie()// This will call parents constructor!!
{
    genre = "";
    age_rating = 0;
    movie_length = 0;
}

class Action_Movie:public Movie
{
    public:
        void Display()
        {
          std::cout<<"PID="<<productid<<"   "<<"Pname="<<name<<"   "<<"Distributor="<<manufacturer<<"   "<<"A_F="<<action_factor<<"  "<<
            "Quantity="<<quantity<<std::endl;
        }
        void setActionFactor(int af)
        {
            action_factor = af;
        }
        Action_Movie();
        Action_Movie(std::string,int,std::string,int,std::string,int,int,int);
    private:
        int action_factor;
};

Action_Movie::Action_Movie(std::string pname, int pid, std::string distributor, int quantity, std::string genre, int age, int length, int af):Movie(pname,pid,distributor,quantity,genre,age,length)
{
    action_factor = af;
}

Action_Movie::Action_Movie():Movie()//:Movie("",0,"",0.0,"",0,0)//Default Horror_Movie Constructor
{
    action_factor = 0;
}

class Horror_Movie:public Movie
{
    public:
        void Display()
        {
            std::cout<<"PID="<<productid<<"   "<<"Pname="<<name<<"    "<<"Distributor="<<manufacturer<<"   "<<"S_F="<<scare_factor<<"  "<<
            "Quantity="<<quantity<<std::endl;
        }
        void setScareFactor(int sf)
        {
            scare_factor = sf;
        }
        Horror_Movie();
        Horror_Movie(std::string,int,std::string,int,std::string,int,int,int);
    private:
        int scare_factor;
};

Horror_Movie::Horror_Movie(std::string pname, int pid, std::string distributor, int quantity, std::string genre, int age, int length, int sf):Movie(pname,pid,distributor,quantity,genre,age,length)
{
    scare_factor = sf;
}

Horror_Movie::Horror_Movie():Movie()//:Movie("",0,"",0.0,"",0,0)//Default Horror_Movie Constructor
{
    scare_factor = 0;
}
