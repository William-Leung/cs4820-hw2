#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int arr[10] = {};
  arr[1] = 1;
  arr[1] = 0;
  for (int i = 0; i < 10; i++)
  {
    if (arr[i])
      cout << "Index " << i << ": " << arr[i] << endl;
  }

  return 0;
}