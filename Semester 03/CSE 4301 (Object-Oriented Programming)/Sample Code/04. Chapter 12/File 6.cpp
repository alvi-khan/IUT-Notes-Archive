#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream in("test.txt", ios::in | ios::binary);

  if(!in) {
    cout << "Cannot open input file.\n";
    return 1;
  }

  double num;
  char str[80];

  in.read((char *) &num, sizeof(double));
  in.read(str, 14);
  str[14] = '\0'; // null terminate str

  cout << num << ' ' << str;

  in.close();

  return 0;
}

