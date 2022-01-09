#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  if(argc!=3) {
    cout << "Usage: CONVERT <input> <output>\n";
    return 1;
  }

  ifstream fin(argv[1]); // open input file
  ofstream fout(argv[2]);  // create output file

  if(!fout) {
    cout << "Cannot open output file.\n";
    return 1;
  }
  if(!fin) {
    cout << "Cannot open input file.\n";
    return 1;
  }

  char ch;

  fin.unsetf(ios::skipws);  // do not skip spaces
  while(!fin.eof()) {
    fin >> ch;
    if(ch==' ') ch = '|';
    if(!fin.eof()) fout << ch;
  }

  fin.close();
  fout.close();

  return 0;
}
