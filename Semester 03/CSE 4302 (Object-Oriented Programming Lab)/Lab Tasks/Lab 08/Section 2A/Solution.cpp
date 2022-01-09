#include <iostream>
#include <string>
using namespace std;

// enumerators
enum class Material {Wood, Board, Steel, Foam};
enum class BedSize {Single, SemiDouble, Double};
enum class SofaSize {One, Two, Three, Four, Five};
enum class AlmirahSize {Two, Three, Four};

class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;

    void productDetailsHelper(const string& str)    // prints details
    {
        cout<<string(48, '-')<<endl;
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounted Price: "<<price - discount<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<str<<endl;
        cout<<string(48, '#')<<endl;
    }

public:

    Furniture (double p, double d, Material m): price(0), discount(0), madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice (double val)
    {
        if(val > 0)   price = val;
    }
    void setDiscount (double val)
    {
        if(val <= price)  discount = val;
    }
    double getDiscount()
    {
        return price - discount;
    }
    void setDiscountPercentage (int per)    // storing discount amount
    {
        if (per >= 0 && per <= 100) discount = ((price * 100) * per) / 10000;
        // integer calculations are more accurate
    }
    void setMadeof (Material val)
    {
        madeof = val;
    }

    string getMadeof()
    {
        if (madeof == Material::Wood)       return string("Wood");
        else if (madeof == Material::Board) return string("Board");
        else if (madeof == Material::Steel) return string("Steel");
        else                                return string("");
    }
    virtual void productDetails() = 0;
};


class Bed: public Furniture
{
private:
    BedSize bedSize;

    string getSize()
    {
        if (bedSize == BedSize::Single)             return string("Single");
        else if (bedSize == BedSize::SemiDouble)    return string("SemiDouble");
        else if (bedSize == BedSize::Double)        return string("Double");
        else                                        return string("");
    }

public:
    // keep bedSize and pass rest to parent
    Bed (double p, double d, Material m, BedSize bSize): Furniture(p, d, m), bedSize(BedSize::Single)
    {
        setBedSize(bSize);
    }
    void setBedSize (BedSize bSize)
    {
        bedSize = bSize;
    }
    void productDetails()   // overriding virtual function of parent
    {
        string str = "Bed Size: " + getSize();  // the single unique line
        Furniture::productDetailsHelper(str);   // print details
    }
};

class Sofa: public Furniture
{
private:
    SofaSize sofaSize;

    string getSize()
    {
        if (sofaSize == SofaSize::One)          return string("One");
        else if (sofaSize == SofaSize::Two)     return string("Two");
        else if (sofaSize == SofaSize::Three)   return string("Three");
        else if (sofaSize == SofaSize::Four)    return string("Four");
        else if (sofaSize == SofaSize::Five)    return string("Five");
        else                                    return string("");
    }

public:
    Sofa (double p, double d, Material m, SofaSize sSize): Furniture(p, d, m), sofaSize(SofaSize::One)
    {
        setSofaSize(sSize);
    }
    void setSofaSize (SofaSize sSize)
    {
        sofaSize = sSize;
    }
    void productDetails()
    {
        string str = "Sofa Size: " + getSize();
        Furniture::productDetailsHelper(str);
    }
};

class Almirah: public Furniture
{
private:
    AlmirahSize almirahSize;

    string getSize()
    {
        if (almirahSize == AlmirahSize::Two)        return string("Two");
        else if (almirahSize == AlmirahSize::Three) return string("Three");
        else if (almirahSize == AlmirahSize::Four)  return string("Four");
        else                                        return string("");
    }

public:
    Almirah (double p, double d, Material m, AlmirahSize aSize): Furniture(p, d, m), almirahSize(AlmirahSize::Two)
    {
        setAlmirahSize(aSize);
    }
    void setAlmirahSize (AlmirahSize aSize)
    {
        almirahSize = aSize;
    }
    void productDetails()
    {
        string str = "Almirah Size: " + getSize();
        Furniture::productDetailsHelper(str);
    }
};

/**
    task 4
    sort_furniture_discount will sort the array in descending order based on their discount price.
    You may need to add some member functions
**/
void sort_furniture_discount(Furniture *furnitures[], int no_of_furnitures)
{
    Furniture *temp;
    for (int i=0; i<no_of_furnitures; i++)  // bubble sort
    {
        for (int j=0; j<i; j++)
        {
            if (furnitures[j]->getDiscount() < furnitures[i]->getDiscount())    // pricey stuff first
            {
                temp = furnitures[j];
                furnitures[j] = furnitures[i];
                furnitures[i] = temp;
            }
        }
    }
}


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000, 123, Material::Wood, BedSize::Single);
    f_list[1] = new Sofa(11000, 234, Material::Steel, SofaSize::Five);
    f_list[2] = new Almirah(13000, 345, Material::Wood, AlmirahSize::Two);
    f_list[3] = new Bed(10090, 123, Material::Wood, BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[0]->setDiscountPercentage(30);   // added to test percentage discount works (it does! :D )
    for (int i=0; i<4; i++)  f_list[i]->productDetails();

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**
        task 4
        So that following lines can be executed without error
    */
    sort_furniture_discount(f_list, 4);
    for (int i=0; i<4; i++)  f_list[i]->productDetails();
    /**task 4 ends here*/

    /* deleting pointers */
    delete[] f_list;

}

