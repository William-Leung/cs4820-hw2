#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct edge
{
  int v;
  int t;
  edge(int x, int y)
  {
    v = x;
    t = y;
  }
};

void query_helper(int u, int t_0, vector<int> &reached, vector<edge> adj[])
{
  reached[u] = 1;
  for (int i = 0; i < adj[u].size(); i++)
  {
    edge e = adj[u][i];
    if (e.t >= t_0 && !reached[e.v])
    {
      if (reached[e.v] != 1)
        query_helper(e.v, t_0, reached, adj);
    }
  }
}

int main()
{
  bool debug = false;
  ifstream infile("p2.txt");
  // initial parsing
  int n, l, k;
  if (debug)
    infile >> n >> l >> k;
  else
    cin >> n >> l >> k;

  // forming adjacency list
  vector<edge> adjacency[n + 1];

  // parsing forest and forming adjacency list
  for (int i = 0; i < l; i++)
  {
    int u, v, t;
    if (debug)
      infile >> u >> v >> t;
    else
      cin >> u >> v >> t;
    adjacency[u].push_back(edge(v, t));
    adjacency[v].push_back(edge(u, t));
  }

  for (int i = 0; i < k; i++)
  {
    int u, t_0;
    if (debug)
      infile >> u >> t_0;
    else
      cin >> u >> t_0;

    // array of reachable individuals
    vector<int> reachable(n + 1, 0);
    reachable[u] = 1;

    query_helper(u, t_0, reachable, adjacency);

    bool first = true;
    for (int j = 1; j < reachable.size(); j++)
    {
      if (reachable[j] == 1)
      {
        if (first)
        {
          cout << j;
          first = false;
        }
        else
          cout << " " << j;
      }
    }
    cout << endl;
  }

  return 0;
}