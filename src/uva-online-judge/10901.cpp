#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct Arrival {
  int time, side;
};

vector<int> FindCrossingTimes(const vector<Arrival>& arrivals,
                              const int kFerryCapacity,
                              const int kRiverCrossingTime) {
  vector<int> ans(arrivals.size(), -1);

  deque<int> Q[2];
  int cur_side = 0, cur_time = 0;
  int next_arrival = 0, pending_cars = arrivals.size();

  while (pending_cars > 0) {
    // Update all variables to match the current time
    while (next_arrival < (int)arrivals.size() &&
           arrivals[next_arrival].time <= cur_time) {
      const Arrival& arr = arrivals[next_arrival];
      Q[arr.side].push_back(next_arrival);
      next_arrival += 1;
    }

    // If there are no cars yet, move ahead to the next arrival time
    if (Q[0].size() == 0 && Q[1].size() == 0) {
      cur_time = arrivals[next_arrival].time;
      continue;
    }

    // I wanna move it, move it~!
    for (int i = 0; i < kFerryCapacity && Q[cur_side].size() > 0; ++i) {
      int car = Q[cur_side].front();
      Q[cur_side].pop_front();
      ans[car] = cur_time + kRiverCrossingTime;

      pending_cars -= 1;
    }

    cur_time += kRiverCrossingTime;
    cur_side = 1 - cur_side;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int n, t, m;
    cin >> n >> t >> m;

    vector<Arrival> arrivals;
    for (int i = 0; i < m; ++i) {
      int arrival_time;
      string side;
      cin >> arrival_time >> side;
      arrivals.push_back(Arrival{arrival_time, side == "left" ? 0 : 1});
    }

    vector<int> ans = FindCrossingTimes(arrivals, n, t);
    if (tc > 1) cout << '\n';
    for (int x : ans) cout << x << '\n';
  }

  return 0;
}
