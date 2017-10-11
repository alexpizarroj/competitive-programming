#include <deque>
#include <iostream>
using namespace std;

struct Car {
  int len;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int ferry_len, num_cars;
    cin >> ferry_len >> num_cars;
    ferry_len *= 100;

    deque<Car> Q[2];
    for (int i = 0; i < num_cars; ++i) {
      int len;
      string side_str;
      cin >> len >> side_str;

      int side = side_str == "left" ? 0 : 1;
      Q[side].push_back(Car{len});
    }

    int cur_side = 0, num_crossings = 0;
    int num_pending_cars = num_cars;

    while (num_pending_cars > 0) {
      int used_len = 0;
      while (Q[cur_side].size() > 0) {
        auto car = Q[cur_side].front();
        if (used_len + car.len > ferry_len) break;

        num_pending_cars -= 1;
        used_len += car.len;
        Q[cur_side].pop_front();
      }

      cur_side = 1 - cur_side;
      num_crossings += 1;
    }

    cout << num_crossings << '\n';
  }

  return 0;
}
