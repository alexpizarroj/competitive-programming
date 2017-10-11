#include <deque>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int n, S_max, Q_max;
    cin >> n >> S_max >> Q_max;

    vector<deque<int>> Q(n, deque<int>());
    int num_pending_cargo = 0;
    for (int i = 0; i < n; ++i) {
      int num_elements;
      cin >> num_elements;

      num_pending_cargo += num_elements;
      for (int j = 0; j < num_elements; ++j) {
        int x;
        cin >> x;
        Q[i].push_back(x - 1);
      }
    }

    stack<int> cargo;
    int station = 0, totalTimeSpent = 0;

    while (num_pending_cargo > 0) {
      // Unload items
      while (cargo.size() > 0) {
        // ... to the station
        if (cargo.top() == station) {
          cargo.pop();
          totalTimeSpent += 1;
          num_pending_cargo -= 1;
          continue;
        }
        // ... to the queue
        if ((int)Q[station].size() >= Q_max) break;
        Q[station].push_back(cargo.top());
        cargo.pop();
        totalTimeSpent += 1;
      }

      // Load items from the queue
      while ((int)cargo.size() < S_max && Q[station].size() > 0) {
        cargo.push(Q[station].front());
        Q[station].pop_front();
        totalTimeSpent += 1;
      }

      station += 1;
      if (station >= n) station = 0;
      if (num_pending_cargo > 0) totalTimeSpent += 2;
    }

    cout << totalTimeSpent << endl;
  }

  return 0;
}
