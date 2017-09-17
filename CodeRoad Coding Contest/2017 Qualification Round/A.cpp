#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

template <typename T>
class FenwickTree {
 public:
  FenwickTree() {}

  FenwickTree(unsigned int n) { Init(n); }

  T Query(int x) const {
    T result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) result += data[i];
    return result;
  }

  T QueryInterval(int x, int y) const { return Query(y) - Query(x - 1); }

  T QuerySingle(int x) const {
    T result = data[x];
    if (x > 0) {
      int y = (x & (x + 1)) - 1;
      x -= 1;
      while (x != y) {
        result -= data[x];
        x = (x & (x + 1)) - 1;
      }
    }
    return result;
  }

  void Update(int x, T delta) {
    for (int i = x; i < (int)data.size(); i = (i | (i + 1))) data[i] += delta;
  }

  unsigned int size() const { return data.size(); }

  void Init(unsigned int n) { data.assign(n, 0); }

  vector<T> data;
};

class Solution {
public:
  void solve(const vector<int>& chain, int nUniqueElements, const vector<pair<int, int>>& qq)
  {
    const int n = chain.size();
    const int q = qq.size();
    
    FenwickTree<int> ft(n + 1);
    vector<vector<int>> ocpos(nUniqueElements + 1, vector<int>());
    
    for (int i = 0; i < n; ++i) {
      if (ocpos[chain[i]].size() == 0) {
        ocpos[chain[i]].push_back(1);
        ft.Update(i+1, 1);
      }
      ocpos[chain[i]].push_back(i);
    }
    
    vector<pair<pair<int,int>,int>> ranges(q);
    for (int i = 0; i < q; ++i) {
      ranges[i].first.first = qq[i].first;
      ranges[i].first.second = qq[i].second;
      ranges[i].second = i;
    }
    sort(begin(ranges), end(ranges));
    
    vector<int> ans(q);
    
    int nextRange = 0;
    for (int curpos = 0; curpos < n; ++curpos) {
      // Find the answer for the next available ranges
      while (nextRange < q && ranges[nextRange].first.first <= curpos) {
        const int x = ranges[nextRange].first.first;
        if (x == curpos) {
          // Answer the thing
          const int y = ranges[nextRange].first.second;
          const int id = ranges[nextRange].second;
          ans[id] = ft.Query(y + 1);
          // Debug
          /*
          cerr << "Answering (" << (x+1) << ", " << (y+1) << ") = " << ans[id] << endl;
          for (int i = 1; i <= n; ++i) {
            cerr << ft.QuerySingle(i) << " ";
          }
          cerr << endl;
          */
        }
        nextRange += 1;
      }
      
      // Update our data by removing the current element
      const int val = chain[curpos];
      vector<int>& next = ocpos[val];
      next[0] += 1;
      if (next[0] < (int)next.size()) {
        const int newpos = next[next[0]];
        ft.Update(newpos+1, 1);
      }
      ft.Update(curpos+1, -1);
    }
    
    // Print answers
    for (int x : ans) {
      cout << x << endl;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  
  int n, q;
  while (cin >> n >> q) {
    int nextId = 0;
    map<string, int> idMap;
    vector<int> chain(n);
    for (int i = 0; i < n; ++i) {
      string x;
      cin >> x;
      if (idMap.count(x) > 0) {
        chain[i] = idMap[x];
      } else {
        idMap[x] = nextId;
        chain[i] = nextId;
        nextId += 1;
      }
    }
    
    vector<pair<int, int>> qq(q);
    for (int i = 0; i < q; ++i) {
      cin >> qq[i].first >> qq[i].second;
      qq[i].first -= 1;
      qq[i].second -= 1;
    }
    
    Solution s;
    s.solve(chain, nextId, qq);
  }
  return 0;
}
