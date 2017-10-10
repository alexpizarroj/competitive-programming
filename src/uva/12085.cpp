#include <iostream>
#include <string>
using namespace std;

void printRange(int a, int b) {
  cout << "0" << a;

  if (a != b) {
    cout << "-";

    string as = to_string(a);
    string bs = to_string(b);

    bool foundMismatch = false;
    for (int i = 0; i < (int)as.size(); ++i) {
      if (as[i] != bs[i]) foundMismatch = true;
      if (foundMismatch) cout << bs[i];
    }
  }

  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int n, tc = 1; cin >> n && n != 0; ++tc) {
    cout << "Case " << tc << ":" << '\n';

    int x, last, lastBegin;
    cin >> x;
    last = lastBegin = x;

    auto dryBody = [&] {
      if (x != last + 1) {
        printRange(lastBegin, last);
        lastBegin = x;
      }
      last = x;
    };

    for (int i = 1; i < n; ++i) {
      cin >> x;
      dryBody();
    }

    x = -100;
    dryBody();

    cout << endl;
  }

  return 0;
}
