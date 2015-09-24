#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int inf = 1000000007;

struct Node {
  int s, e, son[2];
  ii p[2];
  char ok;
  
  Node() {
    ok = 0;
  }
  
  bool is_valid_pair(int i) const {
    return (((int)ok >> i) & 1);
  }
  
  void init_from(const ii& val) {
    ok = 3;
    p[0].first = val.first, p[0].second = val.first;
    p[1].first = val.second, p[1].second = val.second;
  }
  
  void update_from(const Node& n1, const Node& n2) {
    ok = 0;
    for (int i = 0; i < 2; i++) {
      if (!n1.is_valid_pair(i)) {
        continue;
      }
      
      int ending = inf;
      for (int j = 0; j < 2; j++) {
        if (!n2.is_valid_pair(j)) {
          continue;
        }
        if (n1.p[i].second <= n2.p[j].first) {
          ending = min(ending, n2.p[j].second);
        }
      }
      
      if (ending != inf) {
        p[i].first = n1.p[i].first;
        p[i].second = ending;
        ok |= (1 << i);
      }
    }
  }
  
  bool good() const {
    return ((int)ok > 0);
  }
};

struct SegmentTree {
  vector<Node> T;

  SegmentTree(const vector<ii>& vec) {
    const int N = vec.size();
    
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;

    T.reserve(4 * N);
    T.push_back(n);
    init(0, vec);
  }

  void init(int u, const vector<ii>& vec) {
    Node &n = T[u];
    if (n.e - n.s == 1)
    {
      n.init_from(vec[n.s]);
      return;
    }
    
    int mid = (n.s + n.e) / 2;
    for (int i = 0; i < 2; i++) {
      Node c(n);
      if (i == 0)
        c.e = mid;
      else {
        c.son[0] = -1;
        c.s = mid;
      }
      n.son[i] = T.size();
      T.push_back(c);
      init(n.son[i], vec);
    }
    
    n.update_from(T[n.son[0]], T[n.son[1]]);
  }

  void update(int u, int pos, const ii& val) {
    Node &n = T[u];
    if (n.e <= pos || n.s >= pos + 1) return;

    if (n.s == pos && n.e == pos + 1) {
      n.init_from(val);
      return;
    }

    if (pos < T[n.son[0]].e) {
      update(n.son[0], pos, val);
    } else {
      update(n.son[1], pos, val);
    }
    n.update_from(T[n.son[0]], T[n.son[1]]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  vector<ii> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
  }
  
  SegmentTree st(vec);
  
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1, b -= 1;
    swap(vec[a], vec[b]);
    
    st.update(0, a, vec[a]);
    st.update(0, b, vec[b]);
    
    cout << (st.T[0].good() ? "TAK\n" : "NIE\n");
  }
  
  return 0;
}
