#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct entry
{
  int u;
  int v;
  int t;
};

bool compareEntry(entry e1, entry e2)
{
  return e1.t > e2.t;
}

class UnionFind
{
  /*
    id will be an array where if id[i]=i, we are looking at parent
    else id[i] is i's parent
  */
  int *id;

public:
  // initialize an empty UnionFind that has n disjoint sets
  UnionFind(int n)
  {
    id = new int[n];
    for (int i = 0; i < n; i++)
    {
      id[i] = i;
    }
  }

  // deletion
  ~UnionFind()
  {
    delete[] id;
  }

  // find the parent (representative element) of p
  int find(int p)
  {
    // finds parent by traversing up
    int parent = p;
    while (parent != id[parent])
    {
      parent = id[parent];
    }

    // updates parents of each of the traversed nodes
    while (p != parent)
    {
      int new_parent = id[p];
      id[p] = parent;
      p = new_parent;
    }
    return parent;
  }

  void merge(int e1, int e2)
  {
    int x = find(e1);
    int y = find(e2);
    // a and b are already in the same set
    if (x == y)
    {
      return;
    }

    // point parents at each other
    id[x] = y;
  }

  // true iff e1 and e2 are in the same set
  bool connected(int e1, int e2)
  {
    return find(e1) == find(e2);
  }
};

int main()
{
  int n, m;
  cin >> n >> m;

  entry log[m];
  // parsing entries into the log
  for (int i = 0; i < m; i++)
  {
    cin >> log[i].u >> log[i].v >> log[i].t;
  }
  sort(log, log + m, compareEntry);

  UnionFind forest(n);

  for (int i = 0; i < m; i++)
  {
    int e1 = log[i].u;
    int e2 = log[i].v;
    if (!forest.connected(e1, e2))
    {
      cout << e1 << " " << e2 << endl;
      forest.merge(e1, e2);
    }
  }

  return 0;
}
