// Solved by Gabriel Garcia
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

string normalizar(string expa) {
  string sa(expa.size(), '\0');
  int na = 0;

  for (int i = 0; i < (int)expa.size(); ++i) {
    char c = expa[i];

    if (c == '(' || c == ')') {
      sa[na++] = c;
    } else if (c >= 'a' && c <= 'z') {
      sa[na++] = 'a';
    } else if (c >= '0' && c <= '9') {
      sa[na++] = 'a';
      i += 1;
      while (expa[i] >= '0' && expa[i] <= '9') {
        i += 1;
      }
      i -= 1;
    } else {  // operador
      sa[na++] = 'b';
    }
  }

  sa.resize(na);

  return sa;
}

#define MAX_L 400005
int f[MAX_L];

void prefixFunction(const string& P) {
  int n = P.size(), k = 0;
  f[0] = 0;
  for (int i = 1; i < n; ++i) {
    while (k > 0 && P[k] != P[i]) k = f[k - 1];
    if (P[k] == P[i]) ++k;
    f[i] = k;
  }
}

// occurrences of P in T
int kmp(const string& P, const string& T) {
  int n = P.size(), L = T.size(), k = 0, ans = 0;

  for (int i = 0; i < L; ++i) {
    while (k > 0 && P[k] != T[i]) k = f[k - 1];
    if (P[k] == T[i]) ++k;

    if (k == n) {
      ++ans;
      k = f[k - 1];
    }
  }

  return ans;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  while (true) {
    string expa, expb;

    getline(cin, expa);
    if (!cin) break;
    getline(cin, expb);

    string norma = normalizar(expa);
    string normb = normalizar(expb);

    // cout << norma << "! in !" << normb << endl;

    prefixFunction(norma);
    int ans = kmp(norma, normb);
    cout << ans << endl;
  }

  return 0;
}
