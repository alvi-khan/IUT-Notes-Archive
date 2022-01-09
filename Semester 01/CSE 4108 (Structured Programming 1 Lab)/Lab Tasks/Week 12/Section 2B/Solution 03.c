#include<stdio.h>
#include"geometry.h"

int main()
{
    double triangle = TriArea(15.0, 15.0*cos(60.0*3.14159265/180), 15.0*sin(60.0*3.14159265/180));
    double parallelogram = ParArea(15.0, 23.0, 60.0);

    printf("%lf", parallelogram-(2*triangle));
}
