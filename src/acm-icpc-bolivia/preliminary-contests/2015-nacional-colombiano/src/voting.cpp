// Solved by Alex Pizarro
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Block {
  int size;
  int pos[26];
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, b;
  char char_cand;
  while (cin >> n >> b >> char_cand) {
    const int root = char_cand - 'a';

    vector<Block> g(b);
    for (int i = 0; i < b; ++i) {
      cin >> g[i].size;

      string pref;
      cin >> pref;
      for (int j = 0; j < n; ++j) {
        int guy = pref[j] - 'a';
        g[i].pos[guy] = j;
      }
    }

    vector<vi> adj(n, vi());
    vector<vi> eq_adj(n, vi());

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        // Score for the duel
        int i_val = 0, j_val = 0;
        for (int k = 0; k < b; ++k) {
          if (g[k].pos[i] < g[k].pos[j]) {
            i_val += g[k].size;
          } else {
            j_val += g[k].size;
          }
        }

        // cout << "Duel score for i=" << i << " and j=" << j << " is " << i_val
        // << " and " << j_val << endl;

        // Duel result edges
        if (i_val < j_val) {
          adj[j].push_back(i);
        } else if (i_val > j_val) {
          adj[i].push_back(j);
        } else {
          eq_adj[j].push_back(i);
          eq_adj[i].push_back(j);
        }
      }
    }

    /*
    for (int i = 0; i < n; ++i) {
      cout << "Node " << i << " neighbors:";
      for (int v : adj[i]) {
        cout << " " << v;
      }
      cout << endl;
    }
    */

    int n_reached = 1;
    vector<bool> reached(n, false);

    queue<int> q;
    q.push(root);
    reached[root] = true;

    for (int v : eq_adj[root]) {
      if (reached[v]) {
        continue;
      }
      q.push(v);
      reached[v] = true;
      n_reached += 1;
    }

    while (!q.empty()) {
      const int u = q.front();
      q.pop();

      for (int v : adj[u]) {
        if (reached[v]) {
          continue;
        }
        n_reached += 1;
        reached[v] = true;
        q.push(v);
      }
    }

    bool ans = (n_reached == n);
    cout << (ans ? 'Y' : 'N') << endl;
  }

  return 0;
}
