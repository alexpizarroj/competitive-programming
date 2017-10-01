#include <bits/stdc++.h>
using namespace std;

struct State {
  State() : solved(false) {
    p[0] = p[1] = p[2] = 0.0;
  }
  double p[3];
  bool solved;
};
const State kDummyState = State();

struct Solver {
private:
  State dp[105][105][105];
  
  int getGroup(int r, int s, int p) {
    if (r && !s && !p) {
      return 0;
    } else if (!r && s && !p) {
      return 1;
    } else if (!r && !s && p) {
      return 2;
    }
    return -1;
  }
  
  const State& f(int r, int s, int p) {
    State &ss = dp[r][s][p];
    if (ss.solved) {
      return ss;
    }
    
    int gg = getGroup(r, s, p);
    if (gg != -1) {
      // Base case
      for(int i = 0; i < 3; i++) {
        ss.p[i] = (i == gg ? 1.0 : 0.0);
      }
    } else {
      // General case
      const int n = r + s + p;
      const int space_sz = n * (n - 1) / 2;
      
      const double p_dies_r = double(r * p) / space_sz;
      const double p_dies_s = double(r * s) / space_sz;
      const double p_dies_p = double(p * s) / space_sz;
      const double p_dies_none = 1 - p_dies_r - p_dies_s - p_dies_p;
      
      //cerr << "State(" << r << ", " << s << ", " << p << ") : ";
      //cerr << (p_dies_none + p_dies_r + p_dies_s + p_dies_p) << endl;
      
      const State& s_dies_r = (r * p > 0 ? f(r-1, s, p) : kDummyState);
      const State& s_dies_s = (r * s > 0 ? f(r, s-1, p) : kDummyState);
      const State& s_dies_p = (p * s > 0 ? f(r, s, p-1) : kDummyState);
      
      for(int i = 0; i < 3; i++) {
        ss.p[i] = p_dies_r * s_dies_r.p[i];
        ss.p[i] += p_dies_s * s_dies_s.p[i];
        ss.p[i] += p_dies_p * s_dies_p.p[i];
        ss.p[i] /= (1 - p_dies_none); 
      }
    }
    
    ss.solved = true;
    return ss;
  }
  
public:
  bool solve() {
    int r, s, p;
    if (!(cin >> r >> s >> p)) {
      return false;
    }
    
    auto result = f(r, s, p);
    cout << fixed << setprecision(12);
    cout << result.p[0] << " " << result.p[1] << " " << result.p[2] << '\n';
    
    return true;
  }
  
  static shared_ptr<Solver> getInstance() {
    return shared_ptr<Solver>(new Solver());
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (Solver::getInstance()->solve());
  return 0;
}