#include <iostream>
using namespace std;

class base {
public:
  int i;
  base(int x) { i = x; }
  virtual void func()
  {
    cout << "Using base version of func(): ";
    cout << i << '\n';
  }
};

class derived1 : public base {
public:
  derived1(int x) : base(x) {}
  void func()
  {
    cout << "Using derived1's version of func(): ";
    cout << i*i << '\n';
  }
};

int main()
{

  base ob(10);
  derived1 d_ob1(10);

  ob.func();
  d_ob1.func();

  return 0;
}
