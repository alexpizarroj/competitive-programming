#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    nNodes = edges.size();
    vector<vector<int>> originalInput = edges;
    
    map<int, int> mapFromOriginalToNew;
    for (int i = 0; i < nNodes; ++i) {
      for (int j = 0; j < 2; ++j) {
        int &u = edges[i][j];
        
        if (mapFromOriginalToNew.count(u) == 0) {
          int index = mapFromOriginalToNew.size();
          mapFromOriginalToNew[u] = index;
        }
        
        u = mapFromOriginalToNew[u];
      }
    }
    
    for (int i = nNodes - 1; i >= 0; --i) {
      buildEdgesWithException(edges, i);
      if (isTree()) return originalInput[i];
    }
    
    return vector<int>{0, 0};
  }
private:
  int nNodes;
  vector<vector<int>> adj;
  vector<bool> seen;
  int seenCount;
  
  void buildEdgesWithException(const vector<vector<int>>& edges, int skipIndex) {
    adj = vector<vector<int>>(nNodes);
    for (int i = 0; i < nNodes; ++i) {
      if (i == skipIndex) continue;
      
      int u = edges[i][0], v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  
  bool isTree() {
    seen = vector<bool>(nNodes, false);
    seenCount = 0;
    dfs(0);
    return (seenCount == nNodes);
  }
  
  void dfs(int u) {
    seen[u] = true;
    seenCount += 1;
    
    for (int v : adj[u]) {
      if (seen[v]) continue;
      dfs(v);
    }
  }
};

void print(const vector<int>& v) {
  for (int x : v) cout << x << " ";
  cout << endl;
}

int main() {
  vector<vector<int>> c1{{1,2}, {1,3}, {2,3}};
  vector<vector<int>> c2{{1,2}, {1,3}, {3,1}};
  
  Solution s;
  print(s.findRedundantConnection(c1));
  print(s.findRedundantConnection(c2));
  
  return 0;
}
