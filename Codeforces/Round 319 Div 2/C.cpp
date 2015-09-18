#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

vi get_primes(int n) {
  vi primes;
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    bool prime = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        prime = false;
        break;
      }
    }
    if (prime) primes.push_back(i);
  }
  return primes;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    if (n == 1) {
      cout << "0" << endl;
      continue;
    }
    
    vi primes = get_primes(n), ans;
    for (int p : primes) {
      for (int i = p; i <= n; i *= p) {
        ans.push_back(i);
      }
    }
    
    cout << ans.size() << endl;
    for (int x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
  
  return 0;
}
