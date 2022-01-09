#ifndef COORD_H
#define COORD_H


class Coord
{
    public:
        Coord();
        Coord(double a, double b);
        ~Coord();

        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Getj() { return j; }
        void Setj(double val) { j = val; }

        double distance(const Coord other);
        int getQuadrant();
        void setCoordInPolar(double distance, double angleInDegree);

    protected:

    private:
        double x;
        double j;
};

#endif // COORD_H
