#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vi t(n), d(n), p(n), itemIndex(n);
    vector<pair<int, pair<ii, int>>> lst;
    
    for (int i = 0; i < n; ++i) {
      cin >> t[i] >> d[i] >> p[i];
      lst.push_back({d[i], {{t[i], p[i]}, i+1}});
    }
    
    sort(begin(lst), end(lst)); 
    for (int i = 0; i < n; ++i) {
      d[i] = lst[i].first;
      t[i] = lst[i].second.first.first;
      p[i] = lst[i].second.first.second;
      itemIndex[i] = lst[i].second.second;
    }
    
    const int kTimeUBound = 2002;
    vector<vi> dp(n+1, vi(kTimeUBound, 0));
    vector<vi> nItems(n+1, vi(kTimeUBound, 0));
    vector<vi> choiceWasToTake(n+1, vi(kTimeUBound, 0));
    
    for (int tt = 2001; tt >= 0; --tt) {
      for (int e = n-1; e >= 0; --e) {
        int best = 0;
        
        // Try not to take
        {
          int cand = dp[e+1][tt];
          
          if (cand > best) {
            nItems[e][tt] = nItems[e+1][tt];
            best = cand;
          }
        }
          
        // Try to take
        bool canTake = (tt + t[e] < d[e]);
        if (canTake) {
          int newtt = tt+t[e];
          int cand = p[e] + (newtt < kTimeUBound ? dp[e+1][newtt] : 0);
          
          if (cand > best) {
            nItems[e][tt] = 1 + (newtt < kTimeUBound ? nItems[e+1][newtt] : 0);
            best = cand;
            choiceWasToTake[e][tt] = 1;
          }
        }
        
        dp[e][tt] = best;
      }
    }
    
    // Answer that shit
    
    cout << dp[0][0] << endl;
    cout << nItems[0][0] << endl;
    
    if (nItems[0][0] > 0) {
      int curtime = 0;
      for (int e = 0; e < n; ++e) {
        if (curtime >= kTimeUBound) break;
        
        if (choiceWasToTake[e][curtime]) {
          cout << itemIndex[e] << " ";
          curtime += t[e];
        }
      }
      cout << endl;
    }
  }
  
  return 0;
}
