// Create a table of square roots and squares.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;

    cout.precision(4);
    cout << "      x   sqrt(x)     x^2\n\n";

    for(x = 2.0; x <= 20.0; x++)
    {
        cout.width(7);
        cout << x << "  ";
        cout.width(7);
        cout << sqrt(x) << "  ";
        cout.width(7);
        cout << x*x << '\n';
    }

    return 0;
}
