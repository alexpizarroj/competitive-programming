#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using int64 = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  const vector<char> keys = {'Z', 'X', 'W', 'U', 'G', 'S', 'R', 'F', 'O', 'N'};
  const vector<int> keys_num = {0, 6, 2, 4, 8, 7, 3, 5, 1, 9};
  const vector<string> keys_strnum =
    { "ZERO", "SIX", "TWO", "FOUR", "EIGHT", "SEVEN", "THREE", "FIVE", "ONE", "NINE"};
  
  int T;
  cin >> T;
  for (int caseno = 1; caseno <= T; ++caseno) {
    cout << "Case #" << caseno << ": ";
    
    string s;
    cin >> s;
    
    vi letcnt('z' - 'a' + 1, 0);
    for (char c : s) {
      letcnt[(int)c - 'A'] += 1;
    }
    
    vector<int> numcnt(10, 0);
    for (int i = 0; i < 10; ++i) {
      int key = keys[i] - 'A';
      while (letcnt[key] > 0) {
        numcnt[keys_num[i]] += 1;
        for (char c : keys_strnum[i]) {
          letcnt[(int)c - 'A'] -= 1;
        }
      }
    }
    
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < numcnt[i]; ++j) {
        cout << i;
      }
    }
    cout << endl;
  }
  
  return 0;
}
