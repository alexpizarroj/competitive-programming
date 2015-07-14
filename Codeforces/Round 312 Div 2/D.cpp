#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using i64 = long long;
using ll = pair<i64, i64>;

void simplify(vector<ll>& vec) {
  if (vec.size() == 0) {
    return;
  }
  
  const int n = vec.size();
  sort(begin(vec), end(vec));
  
  i64 a = vec[0].first, b = a;
  
  vector<ll> result;
  for (int i = 0; i < n; i++) {
    if (b + 1 >= vec[i].first) {
      b = max(b, vec[i].second);
    } else {
      result.emplace_back(a, b);
      a = vec[i].first;
      b = vec[i].second;
    }
  }
  result.emplace_back(a, b);
  
  vec = result;
}

void solve(int h, int q) {
  vector<vector<ll>> inter(h + 1, vector<ll>());
  for (int i = 0; i < q; i++) {
    int d, ans;
    i64 le, ri;
    cin >> d >> le >> ri >> ans;
    
    vector<ll> news;
    if (ans == 1) {
      i64 s = (1LL << (d - 1)), e = (1LL << d) - 1;
      if (s != le) {
        news.emplace_back(s, le - 1);
      }
      if (ri != e) {
        news.emplace_back(ri + 1, e);
      }
    } else {
      news.emplace_back(le, ri);
    }
    
    for (ll info : news) {
      ll p = info;
      for (int i = d - 1; i >= 1; --i) {
        p.first = (p.first % 2 == 0 ? p.first / 2 : p.first / 2 + 1);
        p.second = (p.second % 2 == 0 ? p.second / 2 - 1: p.first / 2);
        if (p.first > p.second) {
          break;
        }
        inter[i].push_back(p);
      }
      inter[d].push_back(info);
      for (int i = d + 1; i <= h; ++i) {
        info.first *= 2;
        info.second = (info.second * 2) + 1;
        inter[i].push_back(info);
      }
    }
  }
  
  for (int d = 1; d <= h; d++) {
    i64 s = (1LL << (d - 1)), e = (1LL << d) - 1;
    simplify(inter[d]);
    if (inter[d].size() == 1 && inter[d][0] == make_pair(s, e)) {
      cout << "Game cheated!\n";
      return;
    }
  }
  
  i64 cnt = 0, last = 0, ss = (1LL << (h - 1)), ee = (1LL << h) - 1;
  
  if (inter[h].size() > 0) {
    if (inter[h][0].first != ss) {
      cnt += inter[h][0].first - ss;
      last = ss;
    }
    
    for (int i = 1; i < (int)inter[h].size(); i++) {
      cnt += inter[h][i].first - inter[h][i - 1].second - 1;
      last = inter[h][i - 1].second + 1;
    }
    
    if (inter[h].back().second != ee) {
      cnt += ee - inter[h].back().second;
      last = ee;
    }
  } else if (h == 1) {
    cnt = last = 1;
  }
  
  if (cnt == 1) {
    cout << last << '\n';
  } else {
    cout << "Data not sufficient!\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int h, q;
  while (cin >> h >> q) {
    solve(h, q);
  }
  
  return 0;
}