#include <iostream>
using namespace std;

class base {
public:
  int i;
};

// Inherit base as virtual.
class derived1 : virtual public base {
public:
  int j;
};

// Inherit base as virtual, here too.
class derived2 : virtual public base {
public:
  int k;
};

/* Here, derived3 inherits both derived1 and derived2.
   However, only one copy of base is present.
*/
class derived3 : public derived1, public derived2 {
public:
  int product() { return i * j * k; }
};

int main()
{
  derived3 ob;

  ob.i = 10; // unambiguous because only one copy present
  ob.j = 3;
  ob.k = 5;

  cout << "Product is " << ob.product() << '\n';

  return 0;
}
