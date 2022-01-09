#include <iostream>
using namespace std;

template <class T>
void swaps (T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

int main()
{
	int a = 10, b = 20;
	cout<<"\nTesting Integers..."<<endl;
	cout<<"a = "<<a<<" b = "<<b<<endl;
	cout<<"Swapping..."<<endl;
	swaps(a, b);
	cout<<"a = "<<a<<" b = "<<b<<endl;

	double c = 15.5, d = 35.8;
	cout<<"\nTesting Doubles..."<<endl;
	cout<<"c = "<<c<<" d = "<<d<<endl;
	cout<<"Swapping..."<<endl;
	swaps(c, d);
	cout<<"c = "<<c<<" d = "<<d<<endl;

	float e = 15.5, f = 35.8;
	cout<<"\nTesting Floats..."<<endl;
	cout<<"e = "<<e<<" f = "<<f<<endl;
	cout<<"Swapping..."<<endl;
	swaps(e, f);
	cout<<"e = "<<e<<" f = "<<f<<endl;

	char g = 'i', h = 'j';
	cout<<"\nTesting Chars..."<<endl;
	cout<<"g = "<<g<<" h = "<<h<<endl;
	cout<<"Swapping..."<<endl;
	swaps(g, h);
	cout<<"g = "<<g<<" h = "<<h<<endl;

}
