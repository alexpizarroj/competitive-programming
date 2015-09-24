#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool cmp(ii a, ii b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

bool solve() {
  int s, k, n;
  cin >> s >> k >> n;
  
  long long a1 = 0;
  vector<ii> inter;
  bool zero_covered = false, got_issues = false;
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    
    if (got_issues) {
      continue;
    }
    
    if (i % 2 == 0) {
      if (k < x + s) {
        got_issues = true;
      }
      
      long long a2 = a1 + x + s;
      //cerr << a1 << " " << a2 << endl;
      
      int d0 = ((a1 / k) + (a1 % k != 0 ? 1 : 0)) * k - a1;
      //cerr << "\td0 = " << d0 << endl;
      
      if (d0 >= x + s) {
        inter.push_back(make_pair(d0 - x - s, d0));
      } else {
        int d1 = ((a2 / k) + (a2 % k != 0 ? 1 : 0)) * k - a2;
        //cerr << "\td1 = " << d0 << endl;
        
        inter.push_back(make_pair(d1, k));
        if (d0 > 0) {
          inter.push_back(make_pair(0, d0));
          zero_covered = true;
        }
      }
    }
    
    a1 += x;
  }
  
  if (got_issues) {
    return false;
  }
  
  if (!zero_covered) {
    return true;
  }
  
  sort(inter.begin(), inter.end(), cmp);
  int b = inter[0].second, sz = inter.size();
  
  for (int i = 1; i < sz; i++) {
    if (b > inter[i].first) {
      b = max(b, inter[i].second);
    } else {
      return true;
    }
  }
  
  return (b != k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << (solve() ? "TAK\n" : "NIE\n"); 
  }
  
  return 0;
}
