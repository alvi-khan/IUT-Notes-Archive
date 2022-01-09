#include <iostream>
#include <fstream>
using namespace std;
//

int main(int argc, char *argv[])
{
//  if(argc!=2) {
//    cout << "Usage: WRITE <filename>\n";
//    return 1;
//  }


  ofstream out("output_1.txt"); // output file

  if(!out) {
    cout << "Cannot open output file.\n";
    return 1;
  }

  char str[80];
  cout << "Write strings to disk, '$' to stop\n";

  do {
    cout << ": ";
    cin >> str;
    out << str << endl;
  } while (*str != '$');

  out.close();
  return 0;
}

