#include <iostream>
using namespace std;

int main()
{
  cout.width(10);          // set minimum field width
  cout << "hello" << '\n'; // right justify by default
  cout.fill('%');          // set fill character
  cout.width(10);          // set width
  cout << "hello" << '\n'; // right justify by default
  cout.setf(ios::left);    // left justify
  cout.width(10);          // set width
  cout << "hello" << '\n'; // output left justified

  cout.width(10);          // set width
  cout.precision(10);      // set 10 digits of precision
  cout << 123.234567 << '\n';
  cout.width(10);          // set width
  cout.precision(6);       // set 6 digits of precision
  cout << 123.234567 << '\n';

  return 0;
}

