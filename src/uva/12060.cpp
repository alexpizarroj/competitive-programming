#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

void prettyPrint(int a, int b) {
  if (a % b == 0) {
    int q = a / b;
    if (q < 0) {
      cout << "- ";
      q = -q;
    }
    cout << q << endl;
    return;
  }

  string mid_pre;
  if (a < 0) {
    mid_pre = "- ";
    a = -a;
  }

  int q = a / b;
  a -= q * b;
  int g = gcd(a, b);
  a /= g, b /= g;

  if (q > 0) mid_pre += to_string(q);
  string mid_suf(to_string(b).size(), '-');

  cout << string(mid_pre.size(), ' ') << setw(mid_suf.size()) << a << '\n';
  cout << mid_pre << mid_suf << '\n';
  cout << string(mid_pre.size(), ' ') << b << '\n';
}

int main() {
  for (int n, tc = 1; cin >> n && n != 0; ++tc) {
    cout << "Case " << tc << ":" << '\n';

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      sum += x;
    }

    prettyPrint(sum, n);
  }

  return 0;
}