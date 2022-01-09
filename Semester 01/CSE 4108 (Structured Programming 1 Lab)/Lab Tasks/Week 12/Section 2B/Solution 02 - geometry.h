#include <math.h>
#include <stdlib.h>

double TriArea(double a, double b, double c)
{
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
double SqArea(double a)
{
    return a*a;
}

double RecArea(double a, double b)
{
    return a*b;
}
double ParArea(double a, double b, double angle)
{
    double c = sin(angle*3.14159265/180);
    return a*b*c;
}
