#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct MCBM {
  // n = # of left elements, m = # of right elements
  int n, m;
  // adj list for left elements
  // left elements are [0..n-1], right elements are [0..m-1]
  vector<vector<int> > lst;

  bool find_match(int s, vector<int>& lema, vector<int>& rima) {
    vector<int> from(n, -1);
    queue<int> q;
    int where, match, next;
    bool found = false;

    q.push(s), from[s] = s;
    while (!found && !q.empty()) {
      where = q.front();
      q.pop();
      for (int i = 0; i < (int)lst[where].size(); ++i) {
        match = lst[where][i];
        next = rima[match];
        if (where != next) {
          if (next == -1) {
            found = true;
            break;
          }
          if (from[next] == -1) q.push(next), from[next] = where;
        }
      }
    }

    if (found) {
      while (from[where] != where) {
        next = lema[where];
        lema[where] = match, rima[match] = where;
        where = from[where], match = next;
      }
      lema[where] = match, rima[match] = where;
    }

    return found;
  }

  int maximum_matching()  // O(V*E)
  {
    int ans = 0;
    vector<int> lema(n, -1), rima(m, -1);
    for (int i = 0; i < n; ++i) {
      ans += find_match(i, lema, rima);
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    MCBM match;
    match.n = match.m = n;
    match.lst.assign(n, vector<int>());
    
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        // i -> x
        match.lst[i].push_back(x);
      }
    }
    
    int ans = n - match.maximum_matching();
    cout << ans << '\n';
  }
  
  return 0;
}
