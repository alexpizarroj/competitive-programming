// http://codeforces.com/contest/867/problem/C

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
  
  int n, nSlicesPerPizza;
  while (cin >> n >> nSlicesPerPizza) {
    long long baseAns = 0, nTotalSlices = 0;
    vii vec(n);
    
    for (int i = 0; i < n; ++i) {
      int a, b, ns;
      cin >> ns >> a >> b;
      
      vec[i].first = b - a;
      vec[i].second = ns;
      nTotalSlices += ns;
      baseAns += (long long)ns * a;
    }
    
    long long nPizzas = (nTotalSlices / nSlicesPerPizza);
    if (nPizzas * nSlicesPerPizza < nTotalSlices) nPizzas += 1;
    long long nBoughtSlices = nPizzas * nSlicesPerPizza;
    
    sort(begin(vec), end(vec), greater<ii>());
    
    /*
    cerr << "We got " << nBoughtSlices << " slice(s) out of " << nTotalSlices << " needed" << endl;
    for (auto&& item : vec) {
      cerr << item.first << " " << item.second << endl;
    }
    */
    
    int nWantedSwitches = 0;
    long long sumOfSwitches = 0;
    for (int i = 0; i < n; ++i) {
      if (vec[i].first <= 0) break;
      nWantedSwitches += 1;
      sumOfSwitches += vec[i].second;
    }
    
    //cerr << "# Switches: " << nWantedSwitches << ". Sum of Switches: " << sumOfSwitches << endl;
    
    long long t[2];
    t[1] = t[0] = (sumOfSwitches / nSlicesPerPizza);
    if (t[1] * nSlicesPerPizza < sumOfSwitches) t[1] += 1;
    if (t[1] > nPizzas) t[1] = nPizzas;
    
    //cerr << "Suggested # of Pizza Switches: " << t[0] << ", " << t[1] << endl;
    
    long long ans = baseAns;
    
    for (int k = 0; k < 2; ++k) {
      if (k == 1 && t[1] == t[0]) break;
      
      //cerr << "Swap try #" << k << endl;
      
      const long long nDesiredSwaps = t[k] * nSlicesPerPizza;
      if (nDesiredSwaps == 0) continue;
      
      long long cand = baseAns;
      long long remTypeA = nBoughtSlices - nTotalSlices;
      long long switched = 0;
      
      int lastSeen = 0, lastSeenAmount = 0;
      for (int i = 0; i < n; ++i) {
        int nSwapsToDo = min(nDesiredSwaps - switched, (long long)vec[i].second);
        //cerr << "  Gotta swap (" << nSwapsToDo << "/" << vec[i].second << ") to match " << nDesiredSwaps << endl;
        //cerr << "    Each swap valued at " << vec[i].first << endl;
        
        cand += (long long)vec[i].first * nSwapsToDo;
        
        switched += nSwapsToDo;
        lastSeen = i;
        lastSeenAmount = nSwapsToDo;
        if (switched == nDesiredSwaps) break;
      }
      
      //cerr << "Available type A recoveries: " << remTypeA << endl;
      
      for (int j = lastSeen; j >= 0; --j) {
        if (vec[j].first >= 0) break;
        
        long long amount = (j == lastSeen ? lastSeenAmount : vec[j].second);
        int nSwapsToDo = min(remTypeA, amount);
        //cerr << "  Gotta de-swap (" << nSwapsToDo << "/" << vec[j].second << ") to match recover value " << vec[j].first << " per each swap" << endl;
        
        cand -= (long long)vec[j].first * nSwapsToDo;
        
        remTypeA -= nSwapsToDo;
        if (remTypeA == 0) break;
      }
      
      //cerr << "cand: " << cand << " VS ans: " << ans << endl;
      ans = max(ans, cand);
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
