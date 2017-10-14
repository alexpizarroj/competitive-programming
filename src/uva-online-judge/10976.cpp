#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void PrintAllSolutions(int k) {
  vector<pair<int, int>> solutions;

  for (int y = k + 1; y <= 2 * k; ++y) {
    auto div_res = div(y * k, y - k);

    if (div_res.rem != 0) continue;

    solutions.emplace_back(div_res.quot, y);
  }

  cout << solutions.size() << '\n';
  for (auto&& sol : solutions)
    cout << "1/" << k << " = 1/" << sol.first << " + 1/" << sol.second << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  while (cin >> k) PrintAllSolutions(k);

  return 0;
}
