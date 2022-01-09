#ifndef DM_H
#define DM_H


class DM
{
    public:
        DM();
        DM(int a, float b);
        ~DM();

        int Getmeters() { return meters; }
        void Setmeters(int val) { meters = val; }
        float Getcentimeters() { return centimeters; }
        void Setcentimeters(float val) { centimeters = val; }

    protected:

    private:
        int meters;
        float centimeters;
};

#endif // DM_H
