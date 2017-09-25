#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using int64 = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

const char kNone = '?';

pair<string, string> bf(const string& p, const string& q) {
  pair<string, string> ans = make_pair("999", "999");
  int curdif = inf;
  
  for (int a = 0; a < 10; ++a)
  for (int b = 0; b < 10; ++b)
  for (int c = 0; c < 10; ++c)
  for (int d = 0; d < 10; ++d)
  for (int e = 0; e < 10; ++e)
  for (int f = 0; f < 10; ++f)
  {
    string x = p, y = q;
    if (x[0] == '?') x[0] = a + '0';
    if (x[1] == '?') x[1] = b + '0';
    if (x[2] == '?') x[2] = c + '0';
    if (y[0] == '?') y[0] = d + '0';
    if (y[1] == '?') y[1] = e + '0';
    if (y[2] == '?') y[2] = f + '0';
    
    int xx = (x[0] - '0') * 100 + (x[1] - '0') * 10 + (x[2] - '0');
    int yy = (y[0] - '0') * 100 + (y[1] - '0') * 10 + (y[2] - '0');
    int dif = abs(xx - yy);
    if (dif < curdif || (dif == curdif && x < ans.first)) {
      curdif = dif;
      ans = make_pair(x, y);
    }
  }
  
  return ans;
}

long long toLL(const string& s) {
  stringstream ss(s);
  long long res;
  ss >> res;
  return res;
}

void find_basic_sol(string& a, string& b, int& splitpos) {
  const int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i] == kNone && b[i] == kNone) {
      a[i] = b[i] = '0';
      continue;
    }
    
    if (a[i] == kNone || b[i] == kNone) {
      char val = min(a[i], b[i]);
      a[i] = b[i] = val;
      continue;
    }
    
    if (a[i] == b[i]) {
      continue;
    }
    
    if (a[i] > b[i]) {
      for(int j = i + 1; j < n; ++j) if (a[j] == kNone) a[j] = '0';
      for(int j = i + 1; j < n; ++j) if (b[j] == kNone) b[j] = '9';
    } else {
      for(int j = i + 1; j < n; ++j) if (a[j] == kNone) a[j] = '9';
      for(int j = i + 1; j < n; ++j) if (b[j] == kNone) b[j] = '0';
    }
    splitpos = i;
    break;
  }
}

void improve(string &a, string &b, string &p, string &q, bool reversed = false) {
  long long diff = abs(toLL(a) - toLL(b));
  long long alt_diff = abs(toLL(p) - toLL(q));
  
  if (!reversed) {
    if (alt_diff < diff || (diff == alt_diff && (p < a || (p == a && q < b)))) {
      a = p;
      b = q;
    }
  } else {
    if (alt_diff < diff || (diff == alt_diff && (q < b || (q == b && p < a)))) {
      a = p;
      b = q;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  for (int caseno = 1; caseno <= T; ++caseno) {
    string p, q;
    cin >> p >> q;
    
    // First candidate solution
    string a = p, b = q;
    long long diff = 0;
    int splitpos = -1;
    bool reversed = false;
    
    find_basic_sol(a, b, splitpos);
    
    diff = toLL(b) - toLL(a);
    if (diff < 0) {
      diff *= -1;
      reversed = true;
      swap(a, b);
      swap(p, q);
    }
    
    // More candidate solutions
    if (splitpos != -1) {
      for (int i = splitpos - 1; i >= 0; --i) {
        if (p[i] == q[i] && q[i] == kNone) {
          string x = p, y = q;
          x[i] = '1', y[i] = '0';
          find_basic_sol(x, y, splitpos);
          improve(a, b, x, y, reversed);
          
        } else if (p[i] == kNone && q[i] < '9') {
          string x = p, y = q;
          x[i] = y[i] + 1;
          find_basic_sol(x, y, splitpos);
          improve(a, b, x, y, reversed);
          
        } else if (q[i] == kNone && p[i] > '0') {
          string x = p, y = q;
          y[i] = x[i] - 1;
          find_basic_sol(x, y, splitpos);
          improve(a, b, x, y, reversed);
        }
      }
    }
    
    if (reversed) swap(a, b);
    cout << "Case #" << caseno << ": " << a << ' ' << b << '\n';
  }
  
  return 0;
}
