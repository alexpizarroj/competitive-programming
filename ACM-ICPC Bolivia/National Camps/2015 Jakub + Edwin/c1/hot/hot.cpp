#include <bits/stdc++.h>
using namespace std;

using i16 = short;
using i64 = long long;
using vi = vector<int>;
using vi16 = vector<i16>;
vector<vi16> adj, dst;
vi16 nv, subtree_parent;

void read_input() {
  int n;
  cin >> n;
  
  adj.assign(n, vi16());
  for (int i = 0; i < n - 1; i++) {
    i16 u, v;
    cin >> u >> v;
    u -= 1, v -= 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  nv.resize(n);
  subtree_parent.resize(n);
}

void precalc_APSP() {
  const int n = adj.size();
  
  dst.assign(n, vi16(n, -1));
  for (int u = 0; u < n; u++) {
    vi16& cost = dst[u];
    
    queue<i16> q;
    q.push(u);
    cost[u] = 0;
    
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for(int t : adj[v]) {
        if (cost[t] != -1) {
          continue;
        }
        cost[t] = cost[v] + 1;
        q.push(t);
      }
    }
  }
}

void calc_nv(i16 u, i16 parent, vi16& vertices) {
  vertices.push_back(u);
  
  nv[u] = 1;
  for(i16 v : adj[u]) {
    if (v == parent) {
      continue;
    }
    calc_nv(v, u, vertices);
    nv[u] += nv[v];
  }
}

void calc_subtree_parent(i16 u, i16 parent) {
  for(i16 v : adj[u]) {
    if (v == parent) {
      continue;
    }
    subtree_parent[v] = subtree_parent[u];
    calc_subtree_parent(v, u);
  }
}

i16 find_centroid(int n, i16 t) {
  const int half = (n + 1) / 2;
  i16 parent = -1;
  bool ok;
  
  do {
    ok = true;
    
    for(i16 v : adj[t]) {
      if (v == parent) {
        continue;
      }
      
      if (nv[v] > half) {
        ok = false;
        parent = t;
        t = v;
        break;
      }
    }
  } while (!ok);
  
  return t;
}

i64 solve() {
  long long result = 0;
  queue<i16> q;
  q.push(0);
  
  while (!q.empty()) {
    const i16 t = q.front();
    q.pop();
    
    vi16 vertices;
    calc_nv(t, -1, vertices);
    const int n = vertices.size();
    //cerr << "Tree of size " << n << " rooted at " << t << '\n';
    // Skip subtree if it is too small
    if (n < 3) { continue; }
    
    const int ct = find_centroid(n, t);
    
    // Label each vertex's subtree
    subtree_parent[ct] = -1;
    for(int i = 0; i < (int)adj[ct].size(); i++) {
      const int v = adj[ct][i];
      subtree_parent[v] = i;
      calc_subtree_parent(v, ct);
    }
    
    // Sort vertices according to their subtree
    sort(begin(vertices), end(vertices), [](int u, int v) {
      return subtree_parent[u] < subtree_parent[v];
    });
    
    // Show current tree data
    /*
    cerr << "\tVlist:";
    for(i16 x : vertices) {
      cerr << setw(4) << x;
    }
    cerr << "\t\n\tSlist:";
    for(i16 x : vertices) {
      cerr << setw(4) << subtree_parent[x];
    }
    cerr << "\t\n";
    */
    
    // Subtree start/end
    vector<pair<short, short>> subtree_inter;
    {
      short st = 0, i = 1, j = 1;
      while (j < n) {
        if (subtree_parent[vertices[i]] != subtree_parent[vertices[j]]) {
          subtree_inter.emplace_back((short)i, (short)j - 1);
          i = j, st += 1;
        }
        j += 1;
      }
      subtree_inter.emplace_back((short)i, (short)j - 1);
    }
    
    // Frequency of distances from the centroid to the vertices
    vi16 dist_freq(n, 0);
    vector<vi16> subtree_dist_freq((int)adj[ct].size(), vi16(n, 0));
    for(int i = 0; i < n; i++) {
      const int u = vertices[i];
      if (u == ct) {
        continue;
      }
      int d = dst[ct][u];
      dist_freq[d] += 1;
      subtree_dist_freq[subtree_parent[u]][d] += 1;
    }
    
    // Triplets (assume centroid as root)
    long long new_triplets = 0;
    
    // ****
    // Triplets that include the centroid
    // ****
    for(int i = 1; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        i16 u = vertices[i], v = vertices[j];
        if (dst[ct][u] == dst[ct][v] && dst[ct][u] == dst[u][v]) {
          new_triplets += 1;
        }
      }
    }
    
    // ****
    // Triplets that include 2 vertices from one subtree and 1 from another
    // ****
    for(int st = 0; st < (int)subtree_inter.size(); st++) 
    {
      int a = subtree_inter[st].first, b = subtree_inter[st].second;
      // [a, b] are the vertices from a subtree of the centroid
      
      for(int i = a; i <= b; i++) {
        for(int j = i + 1; j <= b; j++) {
          i16 u = vertices[i], v = vertices[j];
          if (dst[u][ct] != dst[v][ct]) {
            continue;
          }
          
          int x = dst[u][ct], y = dst[u][v] - x;
          if (y <= 0) {
            continue;
          }
          
          new_triplets += (dist_freq[y] - subtree_dist_freq[st][y]);
        }
      }
    }
    
    // ****
    // Triplets whose vertices belong to a different subtree (each)
    // ****
    for(int st = 0; st < (int)adj[ct].size(); ++st) {
      long long cnt = 0;
      // u belongs to subtree[st]
      for(int u = subtree_inter[st].first; u <= subtree_inter[st].second; ++u) {
        // v belongs to some subtree after subtree[st]
        for(int v = subtree_inter[st].second + 1; v < n; v++) {
          if (dst[vertices[u]][ct] != dst[vertices[v]][ct]) {
            continue;
          }
          
          int x = dst[vertices[u]][ct];
          int st1_cnt = subtree_dist_freq[st][x];
          int st2_cnt = subtree_dist_freq[subtree_parent[vertices[v]]][x];
          cnt += dist_freq[x] - st1_cnt - st2_cnt;
        }
      }
      assert(cnt % 2 == 0);
      cnt /= 2;
      
      // Get rid of the subtree data for the next iteration
      for(int d = 1; d < n; d++) {
        dist_freq[d] -= subtree_dist_freq[st][d];
      }
      
      new_triplets += cnt;
    }
    
    // Remove the centroid from the tree
    for(i16 v : adj[ct]) {
      for(int i = 0; i < (int)adj[v].size(); i++) {
        if (adj[v][i] == ct) {
          adj[v].erase(adj[v].begin() + i);
          break;
        }
      }
      q.push(v);
    }
    
    //cerr << "\tNew triplets: " << new_triplets << '\n';
    result += new_triplets;
  }
  
  return result;
} 

int main() {
  read_input();
  
  precalc_APSP();
  
  i64 ans = solve();
  cout << ans << '\n';
  
  return 0;
}
