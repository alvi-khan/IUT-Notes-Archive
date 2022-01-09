#include <iostream>
#include <fstream>
using namespace std;

int main()
{

  ofstream fout("test.txt");  // create output file

  if(!fout) {
    cout << "Cannot open output file.\n";
    return 1;
  }

  fout << "Hello!\n";
  fout << 100 << endl;

  fout.close();

  ifstream fin("test.txt"); // open input file

  if(!fin) {
    cout << "Cannot open input file.\n";
    return 1;
  }

  char str[80];
  int i;

  fin >> str >> i;
  cout << str << ' ' << i << endl;

  fin.close();

  return 0;
}
