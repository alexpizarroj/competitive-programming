#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    vec[i] *= 2;
  }
  
  vector<int> want(n, 0);
  vector<int> decision(n , -1);
  
  auto decide = [&](int g) -> int {
    if (decision[g] != -1) {
      want[decision[g]] -= 1;
      decision[g] = -1;
    }
    
    const int le = g, ri = (g + 1) % n;
    int leval = vec[le], rival = vec[ri];
    if (want[le] == 1) { leval /= 2; }
    if (want[ri] == 1) { rival /= 2; }
    
    if (leval > rival) {
      want[le] += 1;
      decision[g] = le;
    } else {
      want[ri] += 1;
      decision[g] = ri;
    }
    
    return decision[g];
  };
  
  bool changed = true;
  while (changed) {
    changed = false;
    for (int g = 0; g < n; g++) {
      int old = decision[g];
      if (old != decide(g)) {
        changed = true;
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << (i > 0 ? " " : "") << (decision[i] + 1);
  }
  cout << endl;
  
  return 0;
}