// Solved by Alex Pizarro
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

string to_string(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

bool isPalindrome(const string &s) {
  const int n = s.size();
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}

string getNext(string s) {
  assert(isPalindrome(s));

  int n = s.size();
  int m = (n + 1) / 2;
  vector<bool> done(m, false);

  done[m - 1] = (s[m - 1] == '9');
  for (int i = m - 2; i >= 0; --i) {
    done[i] = done[i + 1] && s[i] == '9';
  }

  // Special case
  if (done[0]) {
    s = string(n + 1, '0');
    s[0] = s[n] = '1';
    return s;
  }

  // Regular case
  for (int i = 0; i < m; ++i) {
    if (i == m - 1) {
      char c = s[i] + 1;
      s[i] = s[n - i - 1] = c;
      // break;

    } else if (done[i + 1]) {
      int p = i + 1;
      int q = n - 1 - p;
      for (; p <= q; ++p, --q) {
        s[p] = s[q] = '0';
      }

      char c = s[i] + 1;
      s[i] = s[n - 1 - i] = c;

      break;
    }
  }

  return s;
}

string getClosestPalindrome(string s) {
  const int n = s.size();

  string t = s;
  for (int i = 0; i < n / 2; ++i) {
    t[n - i - 1] = t[i];
  }

  if (t <= s) {
    t = getNext(t);
  }

  return t;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  string d;
  while (cin >> n >> d) {
    string palind = getClosestPalindrome(d);
    cout << palind << endl;

    for (int i = 1; i < n; ++i) {
      palind = getNext(palind);
      cout << palind << endl;
    }
  }

  return 0;
}
