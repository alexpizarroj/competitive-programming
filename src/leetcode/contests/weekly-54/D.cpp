// https://leetcode.com/problems/falling-squares/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    vector<int> slots = GetUniqueSlots(positions);
    vector<int> height(slots.size(), 0), ans(positions.size(), -1);
    int top_height = 0;

    for (int idx = 0; idx < (int)positions.size(); ++idx) {
      const pair<int, int>& p = positions[idx];
      const int le = p.first, ri = p.first + p.second - 1;

      int a = distance(begin(slots), lower_bound(begin(slots), end(slots), le));
      int b = distance(begin(slots), lower_bound(begin(slots), end(slots), ri));

      int highest_spot = *max_element(begin(height) + a, begin(height) + b + 1);
      highest_spot += p.second;
      for (int i = a; i <= b; ++i) height[i] = highest_spot;

      if (highest_spot > top_height) top_height = highest_spot;
      ans[idx] = top_height;
    }

    return ans;
  }

 private:
  vector<int> GetUniqueSlots(const vector<pair<int, int>>& positions) {
    vector<int> slots;
    slots.reserve(2 * positions.size());

    for (auto&& p : positions) {
      slots.push_back(p.first);
      slots.push_back(p.first + p.second - 1);
    }

    sort(begin(slots), end(slots));
    slots.resize(distance(begin(slots), unique(begin(slots), end(slots))));

    return slots;
  }
};

void PrintVector(const vector<int>& vec) {
  cout << '{';
  for (int i = 0; i < (int)vec.size(); ++i) {
    if (i > 0) cout << ", ";
    cout << vec[i];
  }
  cout << "}\n";
}

void main_impl() {
  vector<pair<int, int>> test1 = {{1, 2}, {2, 3}, {6, 1}};
  vector<pair<int, int>> test2 = {{100, 100}, {200, 100}};
  vector<pair<int, int>> test3 = {{9, 7}, {1, 9}, {3, 1}};
  PrintVector(Solution().fallingSquares(test1));
  PrintVector(Solution().fallingSquares(test2));
  PrintVector(Solution().fallingSquares(test3));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifndef ONLINE_JUDGE
  using get_time = chrono::steady_clock;
  using ms = chrono::milliseconds;
  auto startingTime = get_time::now();
#endif
  main_impl();
#ifndef ONLINE_JUDGE
  auto endingTime = get_time::now();
  auto diff = endingTime - startingTime;
  auto elapsedTime = chrono::duration_cast<ms>(diff).count();
  cerr << "Elapsed time: " << elapsedTime << " [ms]" << endl;
#endif
  return 0;
}
