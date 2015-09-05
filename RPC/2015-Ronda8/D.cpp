#include <iostream>
#include <vector>
using namespace std;

const int inf = 1000000007;
typedef vector<int> vi;
typedef pair<int, int> ii;

int bitpos[(1<<10) + 1];
void precalc_bitpos() {
  for (int i = 0; i < 10; ++i) {
    bitpos[1 << i] = i;
  }
}

struct Solver {
  int h, w, n;
  vector<ii> carpets;
  bool solved;
  
  void solve() {
    solved = false;
    
    vector<vector<bool> > covered(h, vector<bool>(w, 0));
    rec(0, 0, 0, covered);
  }
  
  void rec(int r, int c, int used_mask, vector<vector<bool> >& covered) {
    restart_rec:
    
    // Are we done?
    if (r == h) {
      solved = true;
      return;
    }
    
    // Next position
    int next_r = r, next_c = c + 1;
    if (c == w - 1) {
      next_r = r + 1, next_c = 0;
    }
    
    // Skip if covered
    if (covered[r][c]) {
      r = next_r, c = next_c;
      goto restart_rec;
      return;
    }
    
    // Check what can we use?
    int unused_mask = (~used_mask) & ((1 << n) - 1);
    while (!solved && unused_mask > 0) {
      const int bit = unused_mask & ~(unused_mask - 1);
      const int i = bitpos[bit];
      unused_mask -= bit;
      
      for (int rot = 0; !solved && rot < 2; ++rot) {
        int cand_h = carpets[i].second, cand_w = carpets[i].first;
        if (rot == 1) swap(cand_h, cand_w);
        if (r + cand_h > h || c + cand_w > w) {
          continue;
        }
        
        bool ok = true;
        for (int it1 = 0; it1 < cand_w; ++it1) {
          if (covered[r][c + it1] == true) {
            ok = false;
            break;
          }
        }
        if (!ok) {
          continue;
        }
        
        int new_used_mask = used_mask | (1 << i);
        for (int it1 = 0; it1 < cand_h; ++it1) {
          for (int it2 = 0; it2 < cand_w; ++it2) {
            covered[r + it1][c + it2] = true;
          }
        }
        
        rec(next_r, next_c, new_used_mask, covered);
        
        for (int it1 = 0; it1 < cand_h; ++it1) {
          for (int it2 = 0; it2 < cand_w; ++it2) {
            covered[r + it1][c + it2] = false;
          }
        }
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  precalc_bitpos();
  
  while (true) {
    Solver s;
    if (!(cin >> s.w >> s.h)) {
      break;
    }
    
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
      int a, w, h;
      cin >> a >> w >> h;
      for (int j = 0; j < a; ++j) {
        s.carpets.push_back(ii(w, h));
      }
    }
    s.n = s.carpets.size();
    
    s.solve();
    cout << (s.solved ? "yes" : "no") << endl;
  }
  
  return 0;
}
