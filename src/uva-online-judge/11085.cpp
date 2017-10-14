#include <iostream>
#include <vector>
using namespace std;

using Config = vector<short>;
vector<Config> valid_configs;
const unsigned int kBoardSizeLen = 8;

bool AttackingEachOther(short x1, short y1, short x2, short y2) {
  if (x1 == x2 || y1 == y2) return true;
  return abs(x1 - x2) == abs(y1 - y2);
}

bool AttacksConfig(const Config& config, short x1, short y1) {
  for (short y2 = 0; y2 < (short)config.size(); ++y2) {
    short x2 = config[y2];
    if (AttackingEachOther(x1, y1, x2, y2)) return true;
  }
  return false;
}

void Rec(Config& config) {
  if (config.size() == kBoardSizeLen) {
    valid_configs.push_back(config);
    return;
  }

  const int col = config.size();
  for (auto row = 0u; row < kBoardSizeLen; ++row) {
    if (AttacksConfig(config, row, col)) continue;
    config.push_back(row);
    Rec(config);
    config.pop_back();
  }
}

void Precalc() {
  valid_configs.clear();

  Config config;
  config.reserve(kBoardSizeLen);
  Rec(config);
}

int CostBetweenConfigs(const Config& config1, const Config& config2) {
  int cost = 0;
  for (auto i = 0u; i < kBoardSizeLen; ++i)
    if (config1[i] != config2[i]) cost += 1;
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  Precalc();

  for (int x, tc = 1; cin >> x; ++tc) {
    Config config;
    config.reserve(kBoardSizeLen);

    config.push_back(x - 1);
    for (auto i = 1u; i < kBoardSizeLen; ++i) {
      cin >> x;
      config.push_back(x - 1);
    }

    int ans = 1000000007;
    for (auto&& good_config : valid_configs) {
      ans = min(ans, CostBetweenConfigs(config, good_config));
    }

    cout << "Case " << tc << ": " << ans << '\n';
  }

  return 0;
}
