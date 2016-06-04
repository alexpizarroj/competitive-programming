#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1000000007;
using int64 = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

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

  int n, q;
  while (cin >> n >> q) {
    vector<vi> p(n, vi(n, false));
    vi antigen_cnt(n);
    bool found_full_parent = false;

    for (int i = 0; i < n; ++i) {
      cin >> antigen_cnt[i];

      if (antigen_cnt[i] == n) {
        found_full_parent = true;
      }

      for (int j = 0; j < antigen_cnt[i]; ++j) {
        int x;
        cin >> x;
        p[i][x - 1] = true;
      }
    }

    for (int i = 0; i < q; ++i) {
      int b;
      cin >> b;

      if (b == 0) {
        cout << (found_full_parent ? "N\n" : "Y\n");
        continue;
      }

      MCBM solver;
      solver.n = n;
      solver.m = n + 1;
      solver.lst.assign(n, vi());

      for (int j = 0; j < b; ++j) {
        int x;
        cin >> x;
        x -= 1;

        // Add edges to the vertex representing this antigen
        for (int k = 0; k < n; ++k) {
          if (!p[k][x]) continue;
          solver.lst[k].push_back(x);
        }
      }

      // Add edges to the vertex representing the absence of an antigen (O)
      if (b < n) {
        for (int k = 0; k < n; ++k) {
          if (antigen_cnt[k] == n) continue;
          solver.lst[k].push_back(n);
        }
      }

      int req_matching = (b == n ? n : b + 1);
      cout << (req_matching == solver.maximum_matching() ? "Y\n" : "N\n");
    }
  }

  return 0;
}
