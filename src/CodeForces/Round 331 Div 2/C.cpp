#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;
using iii = pair<int, ii>;

int take(vector<int>& vec) {
  assert(vec.size() > 0);
  int res = vec.back();
  vec.pop_back();
  return res;
}

bool solve(int n, vector<ii> &ans) {
  vector<ii> vec(n);
  int maxx = 0, maxy = 0;
  for (int i = 0; i < n; ++i) {
    cin >> vec[i].first >> vec[i].second;
    maxx = max(maxx, vec[i].first);
    maxy = max(maxy, vec[i].second);
  }
  
  vi xlen(maxx + 1), ylen(maxy + 1);
  for (const ii& p : vec) {
    xlen[p.first] = max(xlen[p.first], p.second);
    ylen[p.second] = max(ylen[p.second], p.first);
  }
  
  // Make buckets out of each special value
  const int rmin = -ylen[0], rmax = xlen[0];
  const int rsize = rmax - rmin + 1;
  //cerr << "xlen[0] = " << xlen[0] << ", ylen[0] = " << ylen[0] << endl;
  
  vector<vi> values(rsize);
  {
    bool good = true;
    
    for (int i = 1; i <= n; ++i) {
      int w;
      cin >> w;
      
      if (!good) continue;
      
      if (w < rmin || w > rmax) {
        //cerr << "Failing special value weight constraint for " <<  w << endl;
        //cerr << "\trmin = " << rmin << ", rmax = " << rmax << endl;
        good = false;
        continue;
      }
      
      values[w - rmin].push_back(i);
    }
    
    if (!good) return false;
  }
  
  // Check for the buckets size to be enough
  {
    vi real_cnt(rsize);
    for (const ii& p : vec) {
      int sv = p.second - p.first;
      real_cnt[sv - rmin] += 1;
    }
      
    for (int i = rmin; i <= rmax; ++i) {
      if (real_cnt[i - rmin] != (int)values[i - rmin].size()) {
        //cerr << "Failing count check" << endl;
        return false;
      }
    }
  }
  
  // Sort each bucket
  for (int i = 0; i < rsize; ++i) {
    sort(begin(values[i]), end(values[i]), greater<int>());
  }
  
  // Check for the assigment to be correct (while building it)
  vector<iii> result;
  const int n_zero_values = (int)values[0 - rmin].size();
  vi last_ver(xlen[0] + 1), last_hor(ylen[0] + 1);
  
  for (int row = 0; row < n_zero_values; ++row) {
    const int sy = row, sx = row;
    const int baseval = take(values[0 - rmin]);
    result.push_back(make_pair(baseval, ii(sx, sy)));
    
    for (int le = sx + 1, last = baseval; le <= ylen[sx]; ++le) {
      const int wb = -(le - sx) - rmin;
      int cur = take(values[wb]);
      
      if (cur < last || (row > 0 && cur < last_hor[le])) {
        //cerr << "The assigment was invalid" << endl;
        return false;
      }
      
      result.push_back(make_pair(cur, ii(le, sy)));
      last_hor[le] = cur;
      last = cur;
    }
    
    for (int bo = sy + 1, last = baseval; bo <= xlen[sy]; ++bo) {
      const int wb = (bo - sy) - rmin;
      int cur = take(values[wb]);
      
      if (cur < last || (row > 0 && cur < last_ver[bo])) {
        //cerr << "The assigment was invalid" << endl;
        return false;
      }
      
      result.push_back(make_pair(cur, ii(sx, bo)));
      last_ver[bo] = cur;
      last = cur;
    }
  }
  
  // Return the assigment
  assert((int)result.size() == n);
  sort(begin(result), end(result));
  for (int i = 0; i < n; ++i) {
    ans.push_back(result[i].second);
  }
  
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vector<ii> ans;
    bool res = solve(n, ans);
    if (res) {
      cout << "YES\n";
      assert((int)ans.size() == n);
      for (int i = 0; i < n; ++i) {
        cout << ans[i].first << " " << ans[i].second << '\n';
      }
    } else {
      cout << "NO\n";
    }
  }
  
  return 0;
}
