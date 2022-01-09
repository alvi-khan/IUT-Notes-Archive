#ifndef SQUARE_H
#define SQUARE_H


class Square
{
    public:
        Square():side(0){}
        Square(int val);

        int Getside() { return side; }
        void Setside(int val);

        int getPerimeter() { return side*4;};
        int getArea() { return side*side;};
        float getDiagonal();

        Square operator ++();
        Square operator ++(int i);

        Square operator --();
        Square operator --(int i);

        Square operator +(Square obj);
        Square operator -(Square obj);

        bool operator == (Square obj);
        bool operator >(Square obj);
        bool operator <(Square obj);

    protected:

    private:
        int side;
};

#endif // SQUARE_H
