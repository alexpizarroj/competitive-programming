// Solved by Alex Pizarro
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

using vi = vector<int>;

bool try_recover(const vector<int>& t, vector<vector<int>>& g) {
  assert(t.size() + 2 == g.size());
  const int n = g.size();

  vi deg(n, 1);
  for (int i = 0; i < n - 2; ++i) {
    int x = t[i];
    if (x >= n) {
      cerr << "Element at index=" << i << " has an impossible value" << endl;
      return false;
    }
    deg[x] += 1;
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 1) {
      pq.push(i);
    }
  }

  vi degleft = deg;
  for (int i = 0; i < n - 2; ++i) {
    if (pq.empty()) {
      cerr << "Queue ran empty at the middle of the process" << endl;
      return false;
    }
    const int u = t[i];
    const int v = pq.top();
    pq.pop();

    g[u].push_back(v);
    g[v].push_back(u);
    degleft[u] -= 1;
    degleft[v] -= 1;

    if (degleft[u] == 1) pq.push(u);
  }

  if (pq.size() != 2) {
    cerr << "Wrong number of items in queue, got=" << pq.size();
    cerr << ", expected=2" << endl;
    return false;
  } else {
    const int u = pq.top();
    pq.pop();
    const int v = pq.top();
    pq.pop();
    g[u].push_back(v);
    g[v].push_back(u);
    degleft[u] -= 1;
    degleft[v] -= 1;
  }

  for (int i = 0; i < n; ++i) {
    if ((int)g[i].size() != deg[i]) {
      cerr << "Degree mistmatch for u=" << i << ", got=" << g[i].size();
      cerr << ", expected=" << deg[i] << endl;
      return false;
    }
  }

  // Check for connectivy
  int nreached = 1;
  queue<int> q;
  vector<bool> reached(n, false);
  q.push(0);
  reached[0] = true;
  while (!q.empty()) {
    const int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (reached[v]) continue;
      reached[v] = true;
      q.push(v);
      nreached += 1;
    }
  }
  if (nreached != n) {
    cerr << "The graph is not connected\n";
    return false;
  }

  // Sort the lists, as required by the output
  for (int i = 0; i < n; ++i) {
    sort(begin(g[i]), end(g[i]));
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  bool first_case = true;
  string ts;

  while (getline(cin, ts)) {
    if (!first_case) cout << "*\n";
    first_case = false;

    istringstream iss(ts);
    vi t;
    for (int item; iss >> item;) {
      t.push_back(item);
    }

    vector<vi> g(t.size() + 2, vi());
    if (try_recover(t, g)) {
      // Output the whole tree
      cout << g.size() << '\n';

      for (int i = 0; i < (int)g.size(); ++i) {
        cout << g[i][0];
        for (int j = 1; j < (int)g[i].size(); ++j) {
          cout << " " << g[i][j];
        }
        cout << '\n';
      }

      continue;
    }

    // Signal the inevitavel!
    cout << "impossible\n";
  }

  return 0;
}
