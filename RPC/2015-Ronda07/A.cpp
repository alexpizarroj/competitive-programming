#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int solve(int n, int m) {
  vector<int> color(n, -1);
  vector<vector<int> > adj(n, vector<int>());
  
  bool good_start = true;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a -= 1, b -= 1;
    
    if (c != 1) {
      int p = (c == 0 ? 0 : 1), q = 1 - p;
      if (color[a] == q || color[b] == q) { good_start = false; }
      color[a] = color[b] = p;
    } else {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  
  if (!good_start) {
    return -1;
  }
  
  vector<int> realcolor(n, -1);
  int ans = 0;
  
  for (int x = 0; x < n; ++x) {
    if (color[x] == -1) {
      continue;
    }
    
    if (realcolor[x] == -1) {
      queue<int> q;
      q.push(x);
      realcolor[x] = color[x];
      
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += realcolor[u];
        
        for (int i = 0; i < (int)adj[u].size(); ++i) {
          const int v = adj[u][i];
          if (realcolor[v] == -1) {
            realcolor[v] = 1 - realcolor[u];
            q.push(v);
          } else if (realcolor[v] == realcolor[u]) {
            return -1;
          }
        }
      }
    } else if (realcolor[x] != color[x]) {
      return -1;
    }
  }
  
  for (int x = 0; x < n; ++x) {
    if (realcolor[x] != -1) {
      continue;
    }
    
    queue<int> q;
    q.push(x);
    realcolor[x] = 0;
    
    int freq[2];
    freq[0] = freq[1] = 0;
    
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      
      freq[realcolor[u]] += 1;
      
      for (int i = 0; i < (int)adj[u].size(); ++i) {
        const int v = adj[u][i];
        if (realcolor[v] == -1) {
          realcolor[v] = 1 - realcolor[u];
          q.push(v);
        } else if (realcolor[v] == realcolor[u]) {
          return -1;
        }
      }
    }
    
    ans += min(freq[0], freq[1]);
  }
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  while (cin >> n >> m) {
    int res = solve(n, m);
    if (res == -1) {
      cout << "impossible\n";
    } else {
      cout << res << '\n';
    }
  }
  
  return 0;
}
