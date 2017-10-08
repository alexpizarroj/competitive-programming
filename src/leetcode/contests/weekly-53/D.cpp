#include <bits/stdc++.h>
using namespace std;

const int kInf = 1000000007;
const long long kLongInf = (long long)kInf * kInf;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

struct Cover {
  Cover() { memset(val, 0, sizeof val); }
  short val[26];
};

class Solution {
 public:
  int n, m;
  string target;
  Cover cTarget;
  vector<Cover> cStickers;
  vector<vector<int>> dp;

  int minStickers(vector<string>& stickers, string target) {
    n = stickers.size();
    m = target.size();

    this->target = target;
    cTarget = getCoverFromWord(target);
    cStickers = vector<Cover>();
    cStickers.reserve(n);
    for (int i = 0; i < n; ++i) {
      cStickers.push_back(getCoverFromWord(stickers[i]));
    }

    dp = vector<vector<int>>(1<<m, vector<int>(n+1, -1));

    int ans = f(0, 0);
    if (ans == kInf) ans = -1;
    return ans;
  }

  Cover getCoverFromWord(const string& s) {
    Cover result;
    for (char c : s) {
      int v = c - 'a';
      result.val[v] += 1;
    }
    return result;
  }

  Cover getCoverFromMask(int mask) {
    Cover result;

    for (int i = 0; i < m; ++i) {
      bool on = (mask >> i) & 1;
      if (!on) continue;

      int c = target[i] - 'a';
      result.val[c] += 1;
    }

    return result;
  }

  int getMaskFromCover(Cover C) {
    int mask = 0;

    for (int i = 0; i < m; ++i) {
      int c = target[i] - 'a';
      if (C.val[c] > 0) {
        mask |= (1 << i);
        C.val[c] -= 1;
      }
    }

    return mask;
  }

  Cover addCovers(const Cover& c1, const Cover& c2) {
    Cover result;
    for (int i = 0; i < 26; ++i) {
      result.val[i] = c1.val[i] + c2.val[i];
    }
    return result;
  }

  int f(int mask, int idx) {
    if (dp[mask][idx] != -1) return dp[mask][idx];

    Cover cov = getCoverFromMask(mask);

    if (idx == n) {
      for (int i = 0; i < 26; ++i)
        if (cTarget.val[i] > cov.val[i]) return kInf;
      return 0;
    }

    int nextNoUsage = f(mask, idx + 1);
    int newMaskWithUsage = getMaskFromCover(addCovers(cov, cStickers[idx]));
    int nextWithUsage1 = kInf, nextWithUsage2 = kInf;
    if (mask != newMaskWithUsage) {
      nextWithUsage1 = f(newMaskWithUsage, idx + 1) + 1;
      nextWithUsage2 = f(newMaskWithUsage, idx) + 1;
    }

    int res = min(min(min(nextNoUsage, nextWithUsage1), nextWithUsage2), kInf);
    dp[mask][idx] = res;
    return res;
  }
};

void main_impl() {
  Solution s;

  vector<string> test1 = {"with", "example", "science"};
  cout << s.minStickers(test1, "thehat") << endl;

  vector<string> test2 = {"notice", "possible"};
  cout << s.minStickers(test2, "basicbasic") << endl;
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
