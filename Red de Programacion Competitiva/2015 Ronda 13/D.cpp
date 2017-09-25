#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;
using iii = pair<int, ii>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  while (cin >> n >> k) {
    const int kStart = 1, kEnd = 0;
    vector<iii> events;
    vi end_time(n);
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      end_time[i] = y;
      events.push_back(iii(x, ii(kStart, i)));
      events.push_back(iii(y, ii(kEnd, i)));
    }
    sort(begin(events), end(events));

    // The set pair holds (ending time, id)
    set<ii, greater<ii>> rec;

    int ans = 0;
    for (const auto& e : events) {
      const int kind = e.second.first;
      const int id = e.second.second;

      if (kind == kStart) {
        auto p = ii(end_time[id], id);

        if ((int)rec.size() < k) {
          // We have room to record
          rec.insert(p);
        } else {
          // We don't have room to record
          if (rec.begin()->first > p.first) {
            rec.erase(rec.begin());
            rec.insert(p);
          }
        }

        continue;
      }

      // Here we have kind = kEnd
      auto p = ii(end_time[id], id);

      if (rec.count(p) > 0) {
        rec.erase(p);
        ans += 1;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
