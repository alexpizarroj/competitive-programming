#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  set<pair<int, int>> data;
  map<int, int> period_from_id;

  string op;
  while (cin >> op && op != "#") {
    int id, period;
    cin >> id >> period;
    data.emplace(period, id);
    period_from_id[id] = period;
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    auto next = *data.begin();
    data.erase(data.begin());

    const int id = next.second, scheduled_time = next.first;
    cout << id << '\n';
    data.emplace(scheduled_time + period_from_id[id], id);
  }

  return 0;
}
