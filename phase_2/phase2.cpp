#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct node
{
  int v;
  int t;

  node(int x, int y)
  {
    v = x;
    t = y;
  }
};

int main()
{
  ifstream infile("p2.txt");

  //=======Parsing======
  int n, l, k;
  infile >> n >> l >> k;

  vector<node> adjacency[n];

  // parsing forest
  for (int i = 0; i < l; i++)
  {
    int u, v, t;
    infile >> u >> v >> t;
    adjacency[u].push_back(node(v, t));
    adjacency[v].push_back(node(u, t));
  }
  cout <<"h";
  return 0;
}