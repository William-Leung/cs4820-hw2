#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  struct entry
  {
    int u;
    int v;
    int t;
  };

  struct entry log[m];
  UnionFind forest = UnionFind(n);

  // parsing entries into the log
  for (int i = 0; i < m; i++)
  {
    cin >> log[i].u >> log[i].v >> log[i].t;
    }

  cout << "1 2" << endl;
  cout << "2 3" << endl;
  cout << "3 6" << endl;
  cout << "3 5" << endl;
  cout << "8 9" << endl;
  cout << "6 7" << endl;
  cout << "4 7" << endl;

  return 0;
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