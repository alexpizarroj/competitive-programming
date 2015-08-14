#include <bits/stdc++.h>
using namespace std;

class UnionFind {
protected:
  function<void(int, int, vector<int>&)> do_union;
  
public:
  vector<int> pset;
  
  void initSet(int N) {
    pset.assign(N, 0);
    for (int i = 0; i < N; i++) pset[i] = i;
  }

  int findSet(int i) {
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
  }
  
  bool isSameSet(int i, int j) { 
    return findSet(i) == findSet(j);
  }
  
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      i = findSet(i), j = findSet(j);
      if (i > j) {
        swap(i, j);
      }
      do_union(i, j, pset);
    }
  }
};

class MaxUnionFind : public UnionFind {
public:
  MaxUnionFind() {
    do_union = [](int i, int j, vector<int>& parent) {
      parent[i] = j;
    };
  }
};

class MinUnionFind : public UnionFind {
public:
  MinUnionFind() {
    do_union = [](int i, int j, vector<int>& parent) {
      parent[j] = i;
    };
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, q;
  while (cin >> n >> q) {
    MinUnionFind le;
    le.initSet(n);
    
    MaxUnionFind ri, team;
    ri.initSet(n), team.initSet(n);
    
    auto try_extend = [&](int& xx, int& x) -> bool {
      bool changed = false;
      
      if (x + 1 < n && team.isSameSet(x, x + 1)) {
        const int zz = x + 1, z = ri.findSet(zz);
        
        ri.unionSet(x, z);
        le.unionSet(zz, xx);
        team.unionSet(x, z);
        
        x = z;
        changed = true;
      }
      
      if (xx - 1 >= 0 && team.isSameSet(xx, xx - 1)) {
        const int z = xx - 1, zz = le.findSet(z);
        
        ri.unionSet(z, x);
        le.unionSet(xx, zz);
        team.unionSet(x, z);
        
        xx = zz;
        changed = true;
      }
      
      return changed;
    };
    
    for (int i = 0; i < q; ++i) {
      int tt, x, y;
      cin >> tt >> x >> y;
      x -= 1, y -= 1;
      
      if (tt == 1) {
        if (!team.isSameSet(x, y)) {
          x = ri.findSet(x), y = ri.findSet(y);
          int xx = le.findSet(x), yy = le.findSet(y);
          
          team.unionSet(x, y);
          
          bool repeat = true;
          while (repeat) {
            repeat = false;
            
            if (try_extend(xx, x)) {
              repeat = true;
              y = ri.findSet(y);
              yy = le.findSet(y);
            }
            
            if (try_extend(yy, y)) {
              repeat = true;
              x = ri.findSet(x);
              xx = le.findSet(x);
            }
          }
        }
      } else if (tt == 2) {
        int xx = le.findSet(x), yy = le.findSet(y);
        x = ri.findSet(x), y = ri.findSet(y);
        
        while (x < y) {
          int zz = x + 1, z = ri.findSet(zz);
          assert(z == ri.findSet(zz));
          assert(zz == le.findSet(z));
          
          ri.unionSet(x, z);
          le.unionSet(zz, xx);
          team.unionSet(x, z);
          
          x = z;
        }
        //assert(x == y);
        
        bool repeat = true;
        while (repeat) {
          repeat = try_extend(xx, x);
        }
      } else  if (tt == 3) {
        cout << (team.isSameSet(x, y) ? "YES\n" : "NO\n");
      }
    }
  }
  
  return 0;
}
