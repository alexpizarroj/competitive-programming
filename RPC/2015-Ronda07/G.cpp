#include <bits/stdc++.h>
using namespace std;

void translate(vector<int> &vec) {
  sort(vec.begin(), vec.end());
  
  const int n = vec.size();
  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    if (j < i) {
      result[i] = (360000 - vec[i]) + vec[j];
    } else {
      result[i] = vec[j] - vec[i];
    }
  }
  
  swap(vec, result);
}

void duplicate(vector<int> &vec) {
  const int n = vec.size();
  vec.reserve(n * 2);
  for (int i = 0; i < n; ++i) {
    vec.push_back(vec[i]);
  }
}

vector<int> kmp_ff(const vector<int>& P) {
  const int n = P.size();
  vector<int> f(n, 0);
  
  int k = 0;
  for (int i = 1; i < n; ++i) {
    while (k > 0 && P[k] != P[i]) { k = f[k - 1]; }
    if (P[k] == P[i]) { k += 1; }
    f[i] = k;
  }
  
  return f;
}

int kmp(const vector<int>& T, const vector<int>& P,
    const vector<int> &f) {
  const int n = P.size(), m = T.size();
  int k = 0, ans = 0;
  
  for (int i = 0; i < m; ++i) {
    while (k > 0 && P[k] != T[i]) { k = f[k - 1]; }
    if (P[k] == T[i]) { k += 1; }
    
    if (k == n) {
      ans += 1;
      k = f[k - 1];
    }
  }
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while (cin >> n) {
    vector<int> cks[2];
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        int x;
        cin >> x;
        cks[i].push_back(x);
      }
    }
    
    translate(cks[0]);
    duplicate(cks[0]);
    translate(cks[1]);
    
    /*
    for (int i = 0; i < 2*n; ++i) {
      cout << cks[0][i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
      cout << cks[1][i] << " ";
    }
    cout << endl;
    */
    
    vector<int> ff = kmp_ff(cks[1]);
    int res = kmp(cks[0], cks[1], ff);
    cout << (res == 0 ? "im" : "") << "possible\n";
  }
  
  return 0;
}
