#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int tc = 1; tc <= n; ++tc) {
    int b, sg, sb;
    cin >> b >> sg >> sb;

    multiset<int, greater<int>> green, blue;
    for (int i = 0; i < sg; ++i) {
      int x;
      cin >> x;
      green.insert(x);
    }
    for (int i = 0; i < sb; ++i) {
      int x;
      cin >> x;
      blue.insert(x);
    }

    vector<int> green_survivors, blue_survivors;

    while (green.size() > 0 && blue.size() > 0) {
      for (int i = 0; i < b; ++i) {
        if (green.size() == 0 || blue.size() == 0) break;

        int g1 = *green.begin(), b1 = *blue.begin();
        green.erase(green.begin());
        blue.erase(blue.begin());

        if (g1 > b1) green_survivors.push_back(g1 - b1);
        if (b1 > g1) blue_survivors.push_back(b1 - g1);
      }

      for (int x : green_survivors) green.insert(x);
      for (int x : blue_survivors) blue.insert(x);
      green_survivors.clear();
      blue_survivors.clear();
    }

    if (tc > 1) cout << endl;

    if (green.size() == 0 && blue.size() == 0) {
      cout << "green and blue died\n";
    } else if (green.size() > 0) {
      cout << "green wins\n";
      for (int x : green) cout << x << '\n';
    } else {
      cout << "blue wins\n";
      for (int x : blue) cout << x << '\n';
    }
  }

  return 0;
}