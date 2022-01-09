#include "People.h"

People::People(std::string v_name, int v_age):name(v_name),age(v_age)
{
    //ctor
}

void People::display()
{
    std::cout<<"Age of "<<name<<" is "<<age<<std::endl;
}
