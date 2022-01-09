#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream out("test.txt", ios::out | ios::binary);

  if(!out) {
    cout << "Cannot open output file.\n";
    return 1;
  }

  double nums[4] = {1.1, 2.2, 3.3, 4.4 };

  out.write((char *) nums, sizeof(nums));
  out.close();

  ifstream in("test.txt", ios::in | ios::binary);

  if(!in) {
    cout << "Cannot open input file.\n";
    return 1;
  }

  in.read((char *) &nums, sizeof(nums));

  int i;
  for(i=0; i<4; i++)
    cout << nums[i] << ' ';

  cout << '\n';

  cout << in.gcount() << " characters read\n";
  in.close();

  return 0;
}

