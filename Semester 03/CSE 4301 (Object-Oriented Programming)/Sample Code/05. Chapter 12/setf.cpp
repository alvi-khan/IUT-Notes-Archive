#include <iostream>
using namespace std;

int main()
{
  // display using default settings
  cout << 123.23 << " hello " << 100 << '\n';
  cout << 10 << ' ' << -10 << '\n';
  cout << 100.0 << "\n\n";

  // now, change formats
  cout.unsetf(ios::dec); // not required by all compilers
  cout.setf(ios::hex | ios::scientific);
  cout << 123.23 << " hello " << 100 << '\n';

  cout.setf(ios::showpos);
  cout << 10 << ' ' << -10 << '\n';

  cout. setf(ios::showpoint | ios::fixed);
  cout << 100.0;

  return 0;
}
