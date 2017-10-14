#include <iostream>
#include <set>
#include <vector>
using namespace std;

const long long kImpossible = -1;

long long MinCostToSlay(const vector<int>& heads, const vector<int>& knights) {
  multiset<int> remaining_knights(begin(knights), end(knights));
  long long cost = 0;
  
  for (int head : heads) {
    auto knight_it = remaining_knights.lower_bound(head);
    if (knight_it == remaining_knights.end()) return kImpossible;

    int knight_height = *knight_it;
    cost += knight_height;
    remaining_knights.erase(knight_it);
  }

  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m && n != 0) {
    vector<int> heads(n), knights(m);
    for (int i = 0; i < n; ++i) cin >> heads[i];
    for (int i = 0; i < m; ++i) cin >> knights[i];

    auto ans = MinCostToSlay(heads, knights);
    if (ans == kImpossible)
      cout << "Loowater is doomed!\n";
    else
      cout << ans << '\n';
  }

  return 0;
}
