// http://ccc.contest.codeforces.com/group/sqatZBP56w/contest/216136/problem/B

#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

const int kNoTarget = -inf;
int n, nControlPoints, maxDist, nWantedCenters, rootNode;
vector<vi> adj, adj2;
vector<bool> isControlPoint;
vi dp1, dp2, worstDist, vec1, vec2;

void dfs1(int u, int parent) {
  if (isControlPoint[u]) dp1[u] = 0;
  
  for (int v : adj[u]) {
    if (v == parent) continue;
    
    adj2[u].push_back(v);
    dfs1(v, u);
    
    if (dp1[v] != kNoTarget && dp1[v]+1 > dp1[u]) dp1[u] = dp1[v]+1;
  }
}

void dfs2(int u) {
  const int nc = adj2[u].size();
  
  for (int i = 0, j = nc-1; i < nc; ++i, --j) {
    const int v1 = adj2[u][i], v2 = adj2[u][j];
    vec1[i+1] = max(vec1[i], dp1[v1]);
    vec2[i+1] = max(vec2[i], dp1[v2]);
  }
  
  worstDist[u] = dp2[u];
  
  for (int i = 0; i < nc; ++i) {
    const int v = adj2[u][i];
    
    int cand = dp2[u];
    int cand2 = max(vec1[i], vec2[nc-1-i]);
    
    if (cand2 != kNoTarget && cand2+1 > cand) cand = cand2+1;
    dp2[v] = cand+1;
    
    worstDist[u] = max(worstDist[u], dp1[v]+1);
  }
  
  for (int v : adj2[u]) {
    dfs2(v);
  }
}

int modPow(int b, int e, int m) {
  if (e == 0) return 1%m;
  if (e == 1) return b%m;
  
  long long half = modPow(b, e/2, m);
  long long ans = (half * half) % m;
  if (e & 1) ans = (ans * b) % m;
  
  return (int)ans;
}

int modComb(int N, int K, int m) {
  if (N-K > K) K = N-K;
  
  long long num = 1, dem = 1;
  for (int i = K+1; i <= N; ++i) {
    num = (num * i) % m;
  }
  for (int i = 1; i <= N-K; ++i) {
    dem = (dem * i) % m;
  }
  
  int demInv = modPow(dem, m-2, m);
  int ans = (num * demInv) % m;
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  while (cin >> n >> nControlPoints >> maxDist >> nWantedCenters) {
    isControlPoint = vector<bool>(n, false);
    for (int i = 0; i < nControlPoints; ++i) {
      int cp;
      cin >> cp;
      cp -= 1;
      
      rootNode = cp;
      isControlPoint[cp] = true;
    }
    
    adj = vector<vi>(n, vi());
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      u -= 1, v -=1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    dp1 = vi(n, kNoTarget);
    adj2 = vector<vi>(n, vi());
    dfs1(rootNode, -1);
    
    dp2 = vi(n, kNoTarget);
    dp2[rootNode] = 0;
    worstDist = vi(n);
    vec1 = vi(n+1); vec1[0] = kNoTarget;
    vec2 = vi(n+1); vec2[0] = kNoTarget;
    dfs2(rootNode);
    
    /*
    cerr << "DP1:" << endl;
    for (int i = 0; i < n; ++i) cerr << dp1[i] << " ";
    cerr << endl;
    
    cerr << "DP2:" << endl;
    for (int i = 0; i < n; ++i) cerr << dp2[i] << " ";
    cerr << endl;
    
    cerr << "WorstDist:" << endl;
    for (int x : worstDist) cerr << x << " ";
    cerr << endl;
    */
    
    int nPossible = 0;
    for (int x : worstDist) if (x <= maxDist) nPossible += 1;
    
    int ans = 0;
    if (nPossible >= nWantedCenters) {
      ans = modComb(nPossible, nWantedCenters, inf);
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
