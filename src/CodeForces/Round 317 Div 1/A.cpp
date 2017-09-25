#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

long long f(int a) {
  long long res = a + 1;
  res = (res * a) / 2;
  return res;
}

long long g(int a, int b) {
  long long res = f(b) - f(a - 1);
  return res;
}

// c = maximum; (a <= b and a < c and b < c) holds
long long ways1(int a, int b, int c, int len) {
  const int min_inc = max(c - a - b + 1, 0);
  const int a_max_inc = (c - 1 - a);
  const int b_max_inc = (c - 1 - b);
  const int max_inc = min(a_max_inc + b_max_inc, len);
  
  long long result = 0;
  
  if (min_inc <= max_inc) {
    // Part 1
    if (min_inc <= b_max_inc) {
      result += g(min_inc + 1, min(b_max_inc, max_inc) + 1);
    }
    // Part 2
    if (b_max_inc + 1 <= max_inc && b_max_inc + 1 <= a_max_inc) {
      long long cnt = min(a_max_inc, max_inc) - b_max_inc;
      result += cnt * (b_max_inc + 1);
    }
    // Part 3
    if (a_max_inc + 1 <= max_inc) {
      int lo = (a_max_inc + 1) - b_max_inc;
      int hi = (max_inc) - b_max_inc;
      int q = a_max_inc - lo + 1;
      int p = a_max_inc - hi + 1;
      result += g(p, q);
    }
  }
  
  return result;
}

// b = c = maximum; (b = c and a < b and a < c) holds
long long ways2(int a, int b, int len) {
  long long result = min(b - a, len + 1);
  return result;
}

long long solve(vector<int> v, int len) {
  sort(begin(v), end(v));
  const int sum = v[0] + v[1] + v[2];
  const int mx = max(v[2], max(v[0], v[1]));
  long long ans = 0;
  
  for (int a = mx; a <= mx + len; ++a) {
    long long add = 0, tmp;
    
    //cerr << "For a max value of " << a << endl;
    
    // Ways 1
    tmp = 0;
    for (int i = 0; i < 3; ++i) {
      int need = a - v[i];
      
      bool ok = (need <= len);
      int args[2], cnt = 0;
      for (int j = 0; j < 3; ++j) {
        if (j == i) {
          continue;
        }
        if (v[j] == a) {
          ok = false;
          break;
        } else {
          args[cnt++] = v[j];
        }
      }
      
      if (ok) {
        tmp += ways1(args[0], args[1], a, len - need);
      }
    }
    
    //cerr << "\tWays 1: " << tmp << endl;
    add += tmp;
    
    // Ways 2
    tmp = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        const int z = (i == 0 ? (j == 1 ? 2 : 1) : 0);
        int need = 2 * a - v[i] - v[j];
        if (need <= len && v[z] < a) {
          tmp += ways2(v[z], a, len - need);
        }
      }
    }
    
    //cerr << "\tWays 2: " << tmp << endl;
    add += tmp;
    
    // Ways 3
    tmp = 0;
    if (3 * a - sum <= len) {
      tmp += 1;
    }
    
    //cerr << "\tWays 3: " << tmp << endl;
    add += tmp;
    
    //cerr << "\tTotal: " << add << '\n';
    ans += add;
  }
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int len;
  vector<int> v(3);
  while (cin >> v[0] >> v[1] >> v[2] >> len) {
    long long ans1 = solve(v, len);
    cout << ans1 << endl;
  }
  
  return 0;
}
