class Product//This is an Abstract class
{
    public:
        virtual void Display() = 0;
        virtual void setScareFactor(int){}
        virtual void setActionFactor(int){}
        int getProductId()
        {
            return productid;
        }
        void setProductId(int id)
        {
            productid = id;
        }
        std::string getProductName()
        {
            return name;
        }
        void setProductName(std::string name)
        {
            this->name = name;
        }
        int getQuantity()
        {
            return quantity;
        }
        void setQuantity(int quan)
        {
            quantity = quan;
        }
        void setManufacturer(std::string man)
        {
            manufacturer = man;
        }
        Product(std::string,int,std::string,int);
        Product();
    protected:
        int productid;
        std::string name;
        std::string manufacturer;
        int quantity;
};
Product::Product(std::string pname, int pid, std::string manufacturer, int quantity)
{
    name = pname;
    productid = pid;
    this->manufacturer = manufacturer;
    this->quantity = quantity;
}
Product::Product()
{
    name = "";
    productid = 0;
    this->manufacturer = "";
    this->quantity = 0;
}

