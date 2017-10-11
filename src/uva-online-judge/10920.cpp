#include <iostream>
using namespace std;

long long CountValuesUnderLayer(int layer_num) {
  return 4LL * layer_num * layer_num - 4LL * layer_num + 1LL;
}

int FindLayer(int p, int sz) {
  if (p == 1) return 1;

  const int num_layers = 1 + (sz - 1) / 2;
  int lo = 1, hi = num_layers;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (p <= CountValuesUnderLayer(mid))
      hi = mid;
    else
      lo = mid;
  }

  return hi;
}

pair<int, int> TranslateToCatersian(pair<int, int> coord, int sz) {
  int half_sz = (sz - 1) / 2;
  return {coord.second + half_sz + 1, coord.first + half_sz + 1};
}

pair<int, int> Solve(int sz, long long p) {
  if (p == 1) return {0, 0};

  const int target_layer = FindLayer(p, sz);
  const int layer_sz = target_layer * 2 - 1;

  long long current_pos = CountValuesUnderLayer(target_layer);
  int x = target_layer - 1, y = target_layer - 1;

  // Walking backwards: Top->Bottom
  long long side_min_pos = current_pos - layer_sz + 2;
  y -= layer_sz - 1;
  if (p >= side_min_pos) return {x, y + p - side_min_pos + 1};

  // Walking backwards: Right->Left
  side_min_pos -= layer_sz - 1;
  x -= layer_sz - 1;
  if (p >= side_min_pos) return {x + p - side_min_pos + 1, y};

  // Walking backwards: Bottom->Top
  side_min_pos -= layer_sz - 1;
  y += layer_sz - 1;
  if (p >= side_min_pos) return {x, y - (p - side_min_pos + 1)};

  // Walking backwards: Left->Right
  side_min_pos -= layer_sz - 1;
  x += layer_sz - 1;
  if (p >= side_min_pos) return {x - (p - side_min_pos + 1), y};

  return {0, 0}; // Should never reach this
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int sz;
  long long p;
  while (cin >> sz >> p && sz != 0) {
    auto ans = TranslateToCatersian(Solve(sz, p), sz);
    cout << "Line = " << ans.first << ", column = " << ans.second << ".\n";
  }
  
  return 0;
}
