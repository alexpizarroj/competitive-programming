#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

vii solve(const vi& p) {
  const int n = p.size();
  vii result;
  
  // Get all cycles
  vector<vi> cycles;
  vector<bool> added(n, false);
  for (int i = 0; i < n; ++i) {
    if (added[i]) continue;
    
    vi cycle;
    int cur = i;
    cycle.push_back(cur);
    added[cur] = true;
    while (!added[p[cur]]) {
      cur = p[cur];
      added[cur] = true;
      cycle.push_back(cur);
    }
    
    cycles.emplace_back(std::move(cycle));
  }
  const int m = cycles.size();
  
  // Sort cycles by non decreasing size
  sort(begin(cycles), end(cycles), [](const vi& a, const vi& b) {
    return a.size() < b.size();
  });
  
  // Check first cycle req. + cycles' sizes multiplicity
  const int bcs = cycles[0].size();
  if (bcs > 2) return result;
  for (int i = 1; i < m; ++i) {
    if (int(cycles[i].size()) % bcs != 0) return result;
  }
  
  // Get all the edges!
  // cerr << "There is a solution! Got " << m << " cycle(s)" << endl;
  
  if (cycles[0].size() == 2) {
    result.emplace_back(cycles[0][0], cycles[0][1]);
  }
  for (int i = 1; i < m; ++i) {
    int idx = 0;
    for (int j = 0; j < (int)cycles[i].size(); ++j) {
      result.emplace_back(cycles[0][idx], cycles[i][j]);
      idx = (idx + 1) % bcs;
    }
  }
  
  //assert((int)result.size() == n - 1);
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vi p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      p[i] -= 1;
    }
    
    if (n == 1) {
      cout << "YES\n";
      continue;
    }
    
    auto res = solve(p);
    if (res.size() == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto&& item : res) {
        cout << (item.first + 1) << " " << (item.second + 1) << '\n';
      }
    }
  }
  
  return 0;
}
