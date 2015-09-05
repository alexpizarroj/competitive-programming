#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  enum class MerchantKind { honest = 0, generous, greedy };
  
  int g, c, n;
  while (cin >> g >> c >> n) {
    vector<MerchantKind> kind(n);
    vector<int> s(n), p(n), gold_change(n);
    
    for (int i = 0; i < n; ++i) {
      string kindstr;
      cin >> kindstr >> p[i] >> s[i];
      gold_change[i] = ((g - s[i]) / p[i]) * p[i];
      if (kindstr[1] == 'o') {
        kind[i] = MerchantKind::honest;
        if (2 * ((g - s[i]) % p[i]) >= p[i]) {
          gold_change[i] += p[i];
        }
      } else if (kindstr[1] == 'e') {
        kind[i] = MerchantKind::generous;
        if ((g - s[i]) % p[i] > 0) {
          gold_change[i] += p[i];
        }
      } else {
        kind[i] = MerchantKind::greedy;
      }
    }
    
    int state_psize[] = {n + 1, c + 1, g * n + 1};
    const int n_states = state_psize[0] * state_psize[1] * state_psize[2];
    auto to_state = [&](int cur, int gold, int plate) {
      int first_param_we = state_psize[1] * state_psize[2];
      int second_param_we = state_psize[2];
      return cur * first_param_we + gold * second_param_we + plate;
    };
    
    const unsigned char not_solved = 255;
    vector<unsigned char> dp(n_states, not_solved);
    
    function<int(int, int, int)> f = [&](int cur, int gold, int plate) -> int {
      if (cur == n) return 0;
      const int state = to_state(cur, gold, plate);
      if (dp[state] != not_solved) return (int)dp[state];
      
      int result = f(cur + 1, gold, plate);
      if (plate >= s[cur]) {
        int cand = 1 + f(cur + 1, gold, plate - s[cur]);
        result = max(result, cand);
      }
      if (gold > 0 && (kind[cur] != MerchantKind::generous || plate < s[cur])) {
        int cand = 1 + f(cur + 1, gold - 1, plate + gold_change[cur]);
        result = max(result, cand);
      }
      
      dp[state] = (unsigned char)result;
      
      return (int)dp[state];
    };
    
    cout << f(0, c, 0) << endl;
  }
  
  return 0;
}
