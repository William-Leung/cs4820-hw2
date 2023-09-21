#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  cout << n << "" << m << endl;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int next_entry;
      scanf("%i", &next_entry);
      cout << next_entry << " ";
    }
    cout << endl;
  }

  return 0;
}