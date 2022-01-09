#include <iostream>
using namespace std;

// Create first base class.
class B1 {
  int a;
public:
  B1(int x) {
      cout<<"Constructing: B1\n";
      a = x;
  }
  ~B1(){ cout<<"Destructing: B1\n";  }
  int geta() { return a; }
};

// Create second base class.
class B2 {
  int b;
public:
  B2(int x)
  {
      cout<<"Constructing: B2\n";
      b = x;
  }
  ~B2(){ cout<<"Destructing: B2\n";  }
  int getb() { return b; }
};
// Directly inherit two base classes.
class D : public B1, public B2 {
  int c;
public:
  // here, z and y are passed directly to B1 and B2
  D(int x, int y, int z) : B1(z), B2(y)
  {
      cout<<"Constructing: D\n";
      c = x;
  }
  ~D(){ cout<<"Destructing: D\n";  }

  /* Because bases inherited as public, D has access
     to public elements of both B1 and B2. */
  void show() {
    cout <<"\n"<<geta() << ' ' << getb() << ' ';
    cout << c << "\n\n";
  }
};

int main()
{
  D ob(1, 2, 3);

  ob.show();

  return 0;
}

