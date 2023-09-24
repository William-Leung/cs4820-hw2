#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream outfile("test.txt");

   int n = 2000;
   int m = 50000;
  outfile << n << " " << m << endl;

  for(int i = 0; i < m; i++) {
    outfile << rand() % n << " " << rand() % n << " " << rand() % n << endl;
  }

  outfile.close();
  return 0;
}