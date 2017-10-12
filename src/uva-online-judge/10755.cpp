#include <iostream>
#include <vector>
using namespace std;

using Line = vector<long long>;
using Area = vector<Line>;
using Space = vector<Area>;

long long MaxSum(const Line& line) {
  const int n = line.size();
  long long ans = line[0], sum = 0;

  for (int i = 0; i < n; ++i) {
    sum += line[i];
    if (sum > ans) ans = sum;
    if (sum < 0) sum = 0;
  }

  return ans;
}

long long MaxSum(const Area& area) {
  const int m = area.size(), n = area[0].size();
  long long ans = area[0][0];

  for (int p = 0; p < m; ++p) {
    Line line(n, 0);

    for (int i = p; i < m; ++i) {
      // Update
      for (int j = 0; j < n; ++j) line[j] += area[i][j];

      // Solve
      auto cand = MaxSum(line);
      if (cand > ans) ans = cand;
    }
  }

  return ans;
}

long long MaxSum(const Space& space) {
  const int l = space.size(), m = space[0].size(), n = space[0][0].size();
  long long ans = space[0][0][0];

  for (int p = 0; p < l; ++p) {
    Area area(m, Line(n, 0));

    for (int i = p; i < l; ++i) {
      // Update
      for (int j = 0; j < m; ++j)
        for (int k = 0; k < n; ++k) area[j][k] += space[i][j][k];

      // Solve
      auto cand = MaxSum(area);
      if (cand > ans) ans = cand;
    }
  }

  return ans;
}

Space BuildEmptySpace(int l, int m, int n) {
  return Space(l, Area(m, Line(n, 0)));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int l, m, n;
    cin >> l >> m >> n;

    auto space = BuildEmptySpace(l, m, n);

    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
          cin >> space[i][j][k];
        }
      }
    }

    if (tc > 1) cout << '\n';
    cout << MaxSum(space) << '\n';
  }

  return 0;
}
