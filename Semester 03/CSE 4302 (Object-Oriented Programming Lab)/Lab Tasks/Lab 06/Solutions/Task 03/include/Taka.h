#ifndef TAKA_H
#define TAKA_H


class Taka
{
    public:
        Taka():one(0), two(0), five(0), ten(0), twenty(0){};
        Taka(int a, int b, int c, int d, int e);

        int Getone() { return one; }
        void Setone(int val);
        int Gettwo() { return two; }
        void Settwo(int val);
        int Getfive() { return five; }
        void Setfive(int val);
        int Getten() { return ten; }
        void Setten(int val);
        int Gettwenty() { return twenty; }
        void Settwenty(int val);

        int getTaka();

        bool operator == (Taka obj);
        bool operator > (Taka obj);
        bool operator < (Taka obj);

        Taka operator + (Taka obj);
        Taka operator - (Taka obj);

    protected:

    private:
        int one;
        int two;
        int five;
        int ten;
        int twenty;
};

#endif // TAKA_H
