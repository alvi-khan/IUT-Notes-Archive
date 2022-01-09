#include <iostream>
#include <string>
using namespace std;

enum Material {Wood,Board,Steel};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Wood)
            return string("Wood");
        else if(madeof==Board)
            return string("Board");
        else if(madeof==Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()=0;
};


enum BedSize {Single,SemiDouble,Double};
class Bed:public Furniture
{
};

class Sofa:public Furniture
{
};

class DiningTable:public Furniture
{
};


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Wood,Single);
    f_list[1] = new Sofa(11000,234,Steel,Five);
    f_list[2] = new DiningTable(13000,345,Wood,Double);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    for(int i=0;i<1;i++)
    {
        f_list[i]->productDetails();
    }

     /**task 2 ends here*/
     /**task 3 ends here*/

    /**
        task 4
        Add one more derived class of Furniture, think of some properties of that furniture to display
        You can take a look in https://www.regalfurniturebd.com/

    */

}
