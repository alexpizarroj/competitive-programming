#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;

  cin >> n;
  cin.ignore();

  while (n--) {
    vector<bool> dat(26, false);
    getline(cin, s);

    for (int i = 0; i < (int)s.size(); ++i) {
      if (isalpha(s[i])) {
        s[i] = tolower(s[i]);
        dat[s[i] - 'a'] = true;
      }
    }

    if (find(dat.begin(), dat.end(), false) == dat.end()) {
      cout << "pangram" << endl;
    }

    else {
      cout << "missing ";

      for (int i = 0; i < (int)dat.size(); ++i) {
        if (dat[i] == false) cout << (char)(i + 'a');
      }
      cout << endl;
    }
  }
  return 0;
}
