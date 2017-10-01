#include <iostream>
#include <vector>
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
  int n, q;
  vector<vector<int>> adj;
  vector<int> P;
  vector<pair<int,int>> Q; // (password, serverId)
  // Useful piss of shite from now on
  vector<pair<int,int>> pwdNodePairs;
  vector<pair<int,int>> nodeRange;
  vector<pair<pair<int,int>, int>> querriesSortedByPwd;
  vector<int> vec; // to debug
  
  void solve() {
    prepareAll();
    
    FenwickTree<int> ft(n + 1);
    vector<int> ans(q);
    vector<pair<int, int>> addedQueue;
    int nextNode = 0, nextRemoval = 0;
    for (int i = 0; i < q; ++i) {
      const int queryPwd = querriesSortedByPwd[i].first.first;
      const int queryNode = querriesSortedByPwd[i].first.second;
      const int queryId = querriesSortedByPwd[i].second;
      
      // Clear unused
      while (nextRemoval < (int)addedQueue.size() && addedQueue[nextRemoval].first < queryPwd) {
        const int nodeId = addedQueue[nextRemoval].second;
        ft.Update(nodeRange[nodeId].first + 1, -1);
        nextRemoval += 1;
        
        //cerr << "Clearing (Pwd=" << nodePwd << ", NodeId=" << (nodeId+1) << ")" << endl;
      }
      
      // Update state before answering
      while (nextNode < n && pwdNodePairs[nextNode].first <= queryPwd) {
        const int nodePwd = pwdNodePairs[nextNode].first;
        if (nodePwd == queryPwd) {
          const int nodeId = pwdNodePairs[nextNode].second;
          ft.Update(nodeRange[nodeId].first + 1, 1);
          addedQueue.push_back({nodePwd, nodeId});
          
          //cerr << "Setting (Pwd=" << nodePwd << ", NodeId=" << (nodeId+1) << ")" << endl;
        }
        nextNode += 1;
      }
      
      // Save the answer now
      ans[queryId] = ft.QueryInterval(nodeRange[queryNode].first+1, nodeRange[queryNode].second+1);
      //cerr << "Answering (" << (queryNode+1) << ", " << queryPwd << ") = " << ans[queryId] << endl;
    }
    
    // Print answers
    for (int x : ans) cout << x << '\n';
  }
  
  void prepareAll() {
    n = adj.size();
    q = Q.size();
    
    vec.clear();
    nodeRange = vector<pair<int,int>>(n);
    dfs(0, -1);
    
    querriesSortedByPwd.reserve(q);
    for (int i = 0; i < q; ++i) {
      querriesSortedByPwd.push_back({{Q[i].second, Q[i].first}, i});
    }
    sort(begin(querriesSortedByPwd), end(querriesSortedByPwd));
    
    pwdNodePairs.reserve(n);
    for (int u = 0; u < n; ++u) {
      pwdNodePairs.push_back({P[u], u});
    }
    sort(begin(pwdNodePairs), end(pwdNodePairs));
    
    // Debug
    /*
    for (int x : vec) cerr << x << " ";
    cerr << endl;
    for (int x : vec) cerr << x << " (" << nodeRange[x].first << ", " << nodeRange[x].second << ")" << endl;
    cerr << endl;
    */
  }
  
  void dfs(int u, int parent) {
    nodeRange[u].first = vec.size();
    vec.push_back(u);
    
    for (int v : adj[u]) {
      if (v == parent) continue;
      dfs(v, u);
    }
    
    nodeRange[u].second = vec.size() - 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  while (cin >> n) {
    Solution s;
    
    s.adj = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      a -= 1, b -= 1;
      s.adj[a].push_back(b);
      s.adj[b].push_back(a);
    }
    
    s.P = vector<int>(n);
    for (int& x : s.P) cin >> x;
    
    int q;
    cin >> q;
    s.Q = vector<pair<int, int>>(q);
    for (int i = 0; i < q; ++i) {
      cin >> s.Q[i].first >> s.Q[i].second;
      s.Q[i].first -= 1;
    }
    
    s.solve();
  }
  
  return 0;
}
