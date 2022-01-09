#ifndef DB_H
#define DB_H
#include"DM.h"


class DB
{
    public:
        DB();
        DB(int a, float b);
        ~DB();

        int Getfeet() { return feet; }
        void Setfeet(int val) { feet = val; }
        float Getinches() { return inches; }
        void Setinches(float val) { inches = val; }

        void addDist(DM obj);
        DB addDistRet(DM obj1, DB obj2);

    protected:

    private:
        int feet;
        float inches;
};

#endif // DB_H
