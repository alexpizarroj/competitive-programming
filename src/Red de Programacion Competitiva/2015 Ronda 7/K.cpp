#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int kUnseen = -1, kStacked = -2;

vector<int> son, cc;
int ncc;

void dfs(int u) {
  cc[u] = kStacked;
  
  const int v = son[u];
  if (cc[v] == kUnseen) {
    dfs(v);
    cc[u] = cc[v];
  } else if (cc[v] == kStacked) {
    cc[u] = ncc;
    ncc += 1;
  } else {
    cc[u] = cc[v];
  }
}

int get_cycle_size(int n, int u, int curcc) {
  vector<int> pos(n, -1);
  int next = 0, v = son[u];
  pos[u] = (next++);
  while (pos[v] == -1) {
    pos[v] = (next++);
    u = v;
    v = son[v];
  }
  
  int result = (pos[u] - pos[v] + 1); 
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  while (cin >> n >> k) {
    son.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> son[i];
      son[i] -= 1;
    }
    
    ncc = 0;
    cc.assign(n, kUnseen);
    for (int i = 0; i < n; ++i) {
      if (cc[i] >= 0) {
        continue;
      }
      dfs(i);
    }
    
    /*
    for (int i = 0; i < n; ++i) {
      cerr << cc[i] << " ";
    }
    cerr << '\n';
    */
    
    vector<ii> vec(ncc, make_pair(-1, 0));
    for (int i = 0; i < n; ++i) {
      const int thiscc = cc[i];
      if (vec[thiscc].first == -1) {
        vec[thiscc].first = get_cycle_size(n, i, thiscc);
      }
      vec[thiscc].second += 1;
    }
    
    /*
    cout << ncc << "\n";
    for (int i = 0; i < ncc; ++i) {
      cout << vec[i].first << " " << vec[i].second << '\n';
    }
    */
    
    vector<vector<bool> > dp(ncc + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;
    
    for (int i = 0; i < ncc; ++i) {
      for (int j = 0; j <= k; ++j) {
        if (dp[i][j] == false) {
          continue;
        }
        
        const int rem = k - j;
        dp[i + 1][j] = true;
        
        if (vec[i].first > rem) {
          continue;
        }
        
        const int limit = min(rem, vec[i].second);
        for (int a = vec[i].first; a <= limit; ++a) {
          dp[i + 1][j + a] = true;
        }
      }
    }
    
    // Report the answer
    for (int i = k; i >= 0; --i) {
      if (dp[ncc][i]) {
        cout << i << '\n';
        break;
      }
    }
  }
  
  return 0;
}
