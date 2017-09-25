#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

string solve(int n, int m, vi& a) {
  vi f(n), b(m);
  vi freq(n + 1, 0);
  vi pos(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    cin >> f[i];
    freq[f[i]] += 1;
    pos[f[i]] = i + 1;
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  // Reading done
  int result = 0;
  a.resize(m);

  for (int i = 0; i < m; ++i) {
    if (freq[b[i]] == 0) result = max(result, 2); // Impossible
    if (freq[b[i]] >= 2) result = max(result, 1); // Ambiguous
    int a_i = pos[b[i]]; // this is a[i]
    a[i] = a_i;
  }

  if (result == 0) return "Possible";
  else if (result == 1) return "Ambiguity";
  return "Impossible";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m) {
    vi a;
    string res = solve(n, m, a);

    cout << res << endl;
    if (res[0] == 'P') {
      for (int i = 0; i < m; ++i) {
        cout << a[i] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
