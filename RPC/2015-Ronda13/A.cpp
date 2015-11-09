#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

// ---

struct GameResult {
  GameResult() : mr(-1), wins(false) {}
  GameResult(int _mr, bool _wins) : mr(_mr), wins(_wins) {}
  int mr;
  bool wins;
};

bool operator<(const GameResult &lhs, const GameResult &rhs) {
  if (lhs.wins != rhs.wins) return !lhs.wins;
  return (lhs.wins ? lhs.mr < rhs.mr : lhs.mr > rhs.mr);
}

GameResult dp[501][501];

GameResult f(int h, int w) {
  // Base cases
  if (dp[h][w].mr != -1) return dp[h][w];
  if (h == 1 && w == 1)
    return dp[h][w] = GameResult(0, false);
  else if (h == 1)
    return dp[h][w] = GameResult(w - 1, false);
  else if (w == 1)
    return dp[h][w] = GameResult(h - 2, true);

  // General case
  GameResult &ans = dp[h][w];
  ans.mr = inf;
  ans.wins = false;

  const int a[2] = {w, w};

  // for (int cut = 1; cut < h; ++cut) {
  const int cut = h / 2;
  {
    const int b[2] = {cut, h - cut};
    GameResult cand(inf, true);

    // It's up to P2's choice in which side to begin playing
    for (int s = 0; s < 2; ++s) {
      GameResult iter_res;
      // ---
      auto gr1 = f(a[s], b[s]);  // P2 starts plays on side 's'
      if (gr1.wins) {
        // P2 won, and he's carrying gr1.mr extra moves
        // It's P1's turn
        auto gr2 = f(b[1 - s], a[1 - s]);
        if (gr2.wins) {
          // P1 won, and he's carrying gr2.mr extra moves
          // It's P2's turn
          if (gr2.mr >= gr1.mr) {
            iter_res.mr = gr2.mr - gr1.mr;
            iter_res.wins = true;
          } else {
            iter_res.mr = gr1.mr - gr2.mr - 1;
            iter_res.wins = false;
          }
        } else {
          // P2 won twice
          iter_res.mr = gr1.mr + gr2.mr;
          iter_res.wins = false;
        }
      } else {
        // P1 won, and now he's carrying gr1.mr extra moves
        // It's P2's turn
        auto gr2 = f(a[1 - s], b[1 - s]);
        if (gr2.wins) {
          // P2 won, and now he's carrying gr2.mr extra moves
          // It's P1's turn
          if (gr2.mr >= gr1.mr) {
            iter_res.mr = gr2.mr - gr1.mr;
            iter_res.wins = false;
          } else {
            iter_res.mr = gr1.mr - gr2.mr - 1;
            iter_res.wins = true;
          }
        } else {
          // P1 won twice
          iter_res.mr = gr1.mr + gr2.mr;
          iter_res.wins = true;
        }
      }
      // ---
      cand = min(cand, iter_res);
    }  // end of side choice loop

    ans = max(ans, cand);
  }  // end of cut loop

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; ++i) {
    int b, d;
    string name;
    cin >> b >> d >> name;

    GameResult gr = (name[0] == 'H' ? f(d, b) : f(b, d));

    cout << name << (gr.wins ? " can win" : " cannot win") << endl;
  }

  return 0;
}
