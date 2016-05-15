/*
** UNNECESSARILY COMPLEX SOLUTION BELOW
** Proceed with care. :D
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

// ---

vector<vii> g;

long long ans;
vi cnt;
vi reds, reds_x;
vi red_paths_cnt, red_paths_cnt_x;
vi triplets_with_me, triplets_with_me_x;

void dfs(const int u, const int p) {
  cnt[u] = 1;
  reds[u] = 0;
  red_paths_cnt[u] = 0;
  triplets_with_me[u] = 0;
  
  int p_index = -1;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    const int v = g[u][i].first;
    const int col = g[u][i].second;
    if (v == p) {
      p_index = i;
      continue;
    }
    
    dfs(v, u);
    
    cnt[u] += cnt[v];
    
    reds_x[v] = (col == (int)'r' ? cnt[v] : reds[v]);
    reds[u] += reds_x[v];
  }
  
  // Get rid of the edge to u's parent
  if (p_index != -1) {
    swap(g[u][p_index], g[u].back());
    g[u].pop_back();
  }
  
  const int nch = g[u].size();
  
  //cerr << "Vertex " << (1 + u) << " with " << nch << " subtree(s) and parent " << (1 + p) << endl;
  //cerr << "\tcnt = " << cnt[u] << endl;
  //cerr << "\treds = " << reds[u] << endl;
  
  // Is this a leaf? Then we are done.
  if (nch == 0) {
    return;
  }
  
  // Update the value of red_paths_cnt[u]
  {
    red_paths_cnt[u] = reds[u];
    
    int rem_vertices = cnt[u] - 1;
    int rem_reds = reds[u];
    
    for (int i = 0; i < nch; ++i) {
      const int v = g[u][i].first;
      
      rem_vertices -= cnt[v];
      rem_reds -= reds_x[v];
      
      red_paths_cnt_x[v] = red_paths_cnt[v];
      
      red_paths_cnt_x[v] += ((long long)reds_x[v] * rem_vertices) % inf;
      red_paths_cnt_x[v] += ((long long)(cnt[v] - reds_x[v]) * rem_reds) % inf;
      red_paths_cnt_x[v] %= inf;
      
      red_paths_cnt[u] += red_paths_cnt_x[v];
      red_paths_cnt[u] %= inf;
    }
  }
  
  //cerr << "\tred_paths_cnt = " << red_paths_cnt[u] << endl;
  
  /*
   * Unordered triplets containing 'u' (let's say: u, x, y)
   */
  {
    int rem_reds = reds[u];
    
    for (int i = 0; i < nch; ++i) {
      const int v = g[u][i].first;
      const int col = g[u][i].second;
      
      rem_reds -= reds_x[v];
      
      //  Case 1: Choosing 'x' from one subtree and 'y' from the other
      triplets_with_me_x[v] = ((long long)reds_x[v] * rem_reds) % inf;
      triplets_with_me_x[v] %= inf;
      
      //  Case 2: Choosing 'x' and 'y' from the same subtree
      if (col == (int)'r') {
        // Add the # of unordered pairs of vertices in v's subtree that have a red path
        triplets_with_me_x[v] += red_paths_cnt[v];
        triplets_with_me_x[v] %= inf;
      } else {
        // Add all the triplets that include v
        triplets_with_me_x[v] += triplets_with_me[v];
        triplets_with_me_x[v] %= inf;
      }
      
      triplets_with_me[u] += triplets_with_me_x[v];
      triplets_with_me[u] %= inf;
    }
  }
  
  //cerr << "\ttriplets_with_me = " << triplets_with_me[u] << endl;
  
  ans += triplets_with_me[u];
  ans %= inf;
  
  /*
   * Unordered triplets not containing 'u', but having it as their common ancestor
   */
  {
    int rem_red_paths = (red_paths_cnt[u] - reds[u] + inf) % inf;
    int rem_triplets_with_me = triplets_with_me[u];
    int rem_reds = reds[u];
    int rem_vertices = cnt[u] - 1;
    
    for (int i = 0; i < nch; ++i) {
      const int v = g[u][i].first;
      const int col = g[u][i].second;
      
      rem_red_paths = (rem_red_paths - red_paths_cnt_x[v] + inf) % inf;
      rem_triplets_with_me = (rem_triplets_with_me - triplets_with_me_x[v] + inf) % inf;
      rem_reds -= reds_x[v];
      rem_vertices -= cnt[v];
      
      //cerr << rem_red_paths << rem_triplets_with_me << rem_reds << rem_vertices << endl;
      
      if (col == (int)'r') {
        ans += ((long long)cnt[v] * rem_red_paths) % inf;
        ans %= inf;
        
        ans += ((long long)red_paths_cnt[v] * rem_vertices) % inf;
        ans %= inf;
      } else {
        ans += ((long long)reds_x[v] * rem_red_paths) % inf;
        ans %= inf;
        
        ans += ((long long)(cnt[v] - reds_x[v]) * rem_triplets_with_me) % inf;
        ans %= inf;
        
        ans += ((long long)triplets_with_me[v] * rem_vertices) % inf;
        ans %= inf;
        
        int tmp = ((long long)red_paths_cnt[v] - triplets_with_me[v] + inf) % inf;
        ans += ((long long)tmp * rem_reds) % inf;
        ans %= inf;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    g.assign(n, vii());
    
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      string co;
      cin >> x >> y >> co;
      x -= 1, y -= 1;
      
      g[x].push_back(ii(y, (int)co[0]));
      g[y].push_back(ii(x, (int)co[0]));
    }
    
    ans = 0;
    cnt.resize(n);
    
    reds.resize(n);
    red_paths_cnt.resize(n);
    triplets_with_me.resize(n);
    
    reds_x.resize(n);
    red_paths_cnt_x.resize(n);
    triplets_with_me_x.resize(n);
    
    dfs(0, -1);
    cout << ans << endl;
    
  }
  
  return 0;
}
