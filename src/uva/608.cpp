#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  const string kCoins = "ABCDEFGHIJKL";

  auto contains = [](const string& s, char ch) {
    return s.find(ch) != string::npos;
  };

  int n;
  cin >> n;

  for (int tc = 1; tc <= n; ++tc) {
    vector<bool> heavy(12, true), light(12, true);

    for (int i = 0; i < 3; ++i) {
      string a, b, c;
      cin >> a >> b >> c;

      if (c == "even") {
        for (char ch : a) heavy[ch - 'A'] = light[ch - 'A'] = false;
        for (char ch : b) heavy[ch - 'A'] = light[ch - 'A'] = false;
      } else {
        if (c == "up") {
          for (char ch : a) light[ch - 'A'] = false;
          for (char ch : b) heavy[ch - 'A'] = false;
        } else if (c == "down") {
          for (char ch : a) heavy[ch - 'A'] = false;
          for (char ch : b) light[ch - 'A'] = false;
        }
        for (char ch : kCoins)
          if (!contains(a, ch) && !contains(b, ch))
            heavy[ch - 'A'] = light[ch - 'A'] = false;
      }
    }

    for (int i = 0; i < 12; ++i) {
      if (heavy[i] != light[i]) {
        cout << (char)('A' + i) << " is the counterfeit coin and it is ";
        cout << (heavy[i] ? "heavy" : "light") << "." << endl;
        break;
      }
    }
  }

  return 0;
}