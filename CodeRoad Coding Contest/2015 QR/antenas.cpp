#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

void fill_reachable(vector<ii>& adj, int val, int c, int top) {
  //top = 1000000000;
  adj.clear();
  
  int cost = 0;
  set<int> done;
  while (true) {
    for (int i = 0, tmp = val; tmp <= top; tmp *= c, i += 1) {
      if (done.count(tmp) > 0) {
        break;
      }
      adj.emplace_back(tmp, cost + i);
      done.insert(tmp);
    }
    
    if (val == 0) {
      break;
    }
    
    cost += 1;
    val /= c;
  }
  
  sort(begin(adj), end(adj));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tc;
  cin >> tc;
  assert(1 <= tc && tc <= 21);
  
  for (int cas = 1; cas <= tc; ++cas) {
    int n, c;
    cin >> n >> c;
    assert(1 <= n && n <= 100000);
    assert(2 <= c && c <= 9);
    
    vector<int> vec(n);
    vector<vector<ii>> adj(n);
    
    int maxval = 0;
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
      assert(1 <= vec[i] && vec[i] <= 10000);
      maxval = max(maxval, vec[i]);
    }
    for (int i = 0; i < n; ++i) {
      fill_reachable(adj[i], vec[i], c, maxval);
      /*for (auto&& x : adj[i]) {
        cerr << "(" << x.first << ", " << x.second << ") ";
      }
      cerr << endl;*/
    }
    
    int ans = inf;
    for (auto&& p : adj[0]) {
      int cand = p.second, target = p.first;
      
      for (int i = 1; i < n; ++i) {
        auto it = lower_bound(begin(adj[i]), end(adj[i]), target,
          [](ii a, int b) -> bool {
            return a.first < b;
        });
        
        if (it != end(adj[i]) && it->first == target) {
          cand += it->second;
        } else {
          cand = inf;
          break;
        }
      }
      
      ans = min(ans, cand);
    }
    
    assert(ans != inf);
    cout << ans << '\n';
  }
  
  return 0;
}
