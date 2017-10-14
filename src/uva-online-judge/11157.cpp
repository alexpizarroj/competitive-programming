#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool CanCross(const vector<int>& big_stones, set<int>& rem_small_stones,
              const int max_leap_distance) {
  const int river_length = big_stones.back();

  int pos = 0;
  while (pos != river_length) {
    auto it1 = upper_bound(begin(big_stones), end(big_stones),
                           pos + max_leap_distance);
    if (it1 == end(big_stones)) return true;

    int next_leapable_big_rock = *(it1 - 1);
    if (next_leapable_big_rock > pos) {
      pos = next_leapable_big_rock;
      continue;
    }

    if (rem_small_stones.size() == 0) return false;

    auto it2 = rem_small_stones.upper_bound(pos);
    auto it3 = rem_small_stones.upper_bound(pos + max_leap_distance);
    if (distance(it2, it3) == 0) return false;

    int next_leapable_small_rock = *(--it3);

    if (next_leapable_small_rock > pos) {
      pos = next_leapable_small_rock;
      rem_small_stones.erase(next_leapable_small_rock);
      continue;
    }
  }

  return true;
}

bool IsSolvableWithSpecificMaxLeapDistance(const vector<int>& big_stones,
                                           const vector<int>& small_stones,
                                           const int max_leap_distance) {
  // Way forward
  set<int> rem_small_stones(begin(small_stones), end(small_stones));
  if (!CanCross(big_stones, rem_small_stones, max_leap_distance)) return false;

  // Way backwards
  const int river_length = big_stones.back();
  const int num_big_stones = (int)big_stones.size();

  vector<int> big_stones_way_back(num_big_stones);
  for (int i = 0; i < num_big_stones; ++i)
    big_stones_way_back[i] = river_length - big_stones[num_big_stones - i - 1];

  set<int> rem_small_stones_way_back;
  for (int stone : rem_small_stones)
    rem_small_stones_way_back.insert(river_length - stone);

  if (!CanCross(big_stones_way_back, rem_small_stones_way_back,
                max_leap_distance))
    return false;

  return true;
}

int MinLeapDistance(const vector<int>& big_stones,
                    const vector<int>& small_stones) {
  int lo = 0, hi = big_stones.back();

  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (IsSolvableWithSpecificMaxLeapDistance(big_stones, small_stones, mid))
      hi = mid;
    else
      lo = mid;
  }

  return hi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int n, D;
    cin >> n >> D;

    vector<int> small_stones, big_stones;
    big_stones.push_back(0);

    for (int i = 1; i <= n; ++i) {
      string stone_detail;
      cin >> stone_detail;

      char kind;
      int location;
      sscanf(stone_detail.c_str(), "%c-%d", &kind, &location);

      if (kind == 'S')
        small_stones.push_back(location);
      else
        big_stones.push_back(location);
    }

    big_stones.push_back(D);

    auto ans = MinLeapDistance(big_stones, small_stones);
    cout << "Case " << tc << ": " << ans << '\n';
  }

  return 0;
}
