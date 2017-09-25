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
    vi a(n), freq(n+1, 0);
    
    for (int i = 0; i < n; ++i) {
      int& x = a[i];
      cin >> x;
      freq[x] += 1;
    }
    
    vi toPlace;
    for (int i = 1; i <= n; ++i)
      if (freq[i] == 0) toPlace.push_back(i);
    
    const int nChanges = toPlace.size();
    
    vector<bool> skippedAlready(n+1, false);
    
    int next = 0;
    for (int i = 0; i < n; ++i) {
      if (freq[a[i]] == 1) continue;
      
      if (toPlace[next] > a[i] && !skippedAlready[a[i]]) {
        skippedAlready[a[i]] = true;
        continue;
      }
      
      freq[a[i]] -= 1;
      freq[toPlace[next]] += 1;
      a[i] = toPlace[next];
      next += 1;
    }
    
    //assert(next == (int)toPlace.size());
    
    // Answer
    cout << nChanges << endl;
    for (int x : a) cout << x << " ";
    cout << endl;
  }
  
  return 0;
}
