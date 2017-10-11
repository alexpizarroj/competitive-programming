#include <iostream>
#include <map>
#include <vector>
using namespace std;

const vector<vector<int>> kMaskBitSources = {{1, 3},    {0, 2, 4},    {1, 5},
                                             {0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8},
                                             {3, 7},    {4, 6, 8},    {5, 7}};

int ApplyFunctionF(int mask) {
  int new_mask = 0;

  for (int i = 0; i < 9; ++i) {
    int value = 0;
    for (int j : kMaskBitSources[i]) value += ((mask >> j) & 1);
    if (value & 1) new_mask |= (1 << i);
  }

  return new_mask;
}

int ReadGridAsMask() {
  int mask = 0;

  for (int i = 0; i < 3; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < 3; ++j)
      if (row[j] == '1') mask |= 1 << (i * 3 + j);
  }

  return mask;
}

int Solve(int starting_value) {
  int last_value = starting_value;
  map<int, int> iteration_num = {{starting_value, 0}};

  while (true) {
    int new_value = ApplyFunctionF(last_value);

    auto new_value_it = iteration_num.find(new_value);
    if (new_value_it != iteration_num.end()) return (new_value_it->second - 1);

    iteration_num.emplace(new_value, iteration_num.size());
    last_value = new_value;
  }

  return -100;  // should never reach this
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int tc = 1; tc <= n; ++tc) cout << Solve(ReadGridAsMask()) << endl;

  return 0;
}