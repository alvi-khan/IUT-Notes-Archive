#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
  ofstream out("test.txt", ios::out | ios::binary);

  if(!out) {
    cout << "Cannot open output file.\n";
    return 1;
  }

  double num = 100.45;
  char str[] = "This is a test";

  out.write((char *) &num, sizeof(double));
  out.write(str, strlen(str));

  out.close();

  return 0;
}
