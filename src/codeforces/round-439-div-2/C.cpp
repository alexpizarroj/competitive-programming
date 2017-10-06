// http://codeforces.com/problemset/problem/869/C

#include <bits/stdc++.h>
using namespace std;

const int inf2 =  998244353;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

int C[5005][5005], F[5005];

void Init() {
  memset(C, -1, sizeof C);
  
  F[0] = 1;
  for (int i = 1; i <= 5000; ++i) {
    F[i] = ((long long)F[i-1] * i) % inf2;
  }
}

int Comb(int m, int n) {
  if (n == 0 || n == m) return 1;
  if (C[m][n] != -1) return C[m][n];
  
  int ans = Comb(m-1, n) + Comb(m-1, n-1);
  if (ans >= inf2) ans -= inf2;
  
  return C[m][n] = ans;
}

int Fact(int n) {
  return F[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int a[3];
  Init();
  
  while (cin >> a[0] >> a[1] >> a[2]) {
    long long pre[3] = {0, 0, 0};
    
    for (int i = 0; i < 3; ++i) {
      int m = a[i], n = a[(i+1)%3];
      if (m < n) swap(m, n);
      
      for (int k = 0; k <= n; ++k) {
        long long ways;
        ways = Comb(m, k);
        ways = (ways * Comb(n, k)) % inf2;
        ways = (ways * Fact(k)) % inf2;
        
        pre[i] += ways;
        if (pre[i] >= inf2) pre[i] -= inf2;
        
      }
    }
    
    long long ans;
    ans = (pre[0] * pre[1]) % inf2;
    ans = (ans * pre[2]) % inf2;
    
    cout << ans << endl;
  }
  
  return 0;
}
