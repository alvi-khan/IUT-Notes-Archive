#include <iostream>
#include<DM.h>
#include<DB.h>

using namespace std;

int main()
{
    DM obj1(2, 3.0);    //creating two objects
    DB obj2 (2, 3.0);

    obj2.addDist(obj1); //adding DM object to DB object

    cout<<obj2.Getfeet()<<" Feet, "<<obj2.Getinches()<<" inches."<<endl;

    DB obj3;
    obj3 = obj2.addDistRet(obj1, obj2);    //similar
    cout<<obj3.Getfeet()<<" Feet, "<<obj3.Getinches()<<" inches."<<endl;


}
