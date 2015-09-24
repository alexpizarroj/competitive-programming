// Solved by José de la Campa
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

unsigned long long pascal[33][100], pascal_sz[33];

void genPascal() {
  pascal[0][0] = 1;
  pascal_sz[0] = 1;

  pascal[1][0] = 1;
  pascal[1][1] = 2;
  pascal[1][2] = 1;
  pascal_sz[1] = 3;

  for (int i = 2; i < 33; ++i) {
    int sz = pascal_sz[i - 1] + 1;
    pascal_sz[i] = sz;

    pascal[i][0] = pascal[i][sz - 1] = 1;
    for (int j = 1; j < sz - 1; ++j) {
      pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
    }
  }
}

void calcular(int i, int &a, int &b) {
  if (i == 0) {
    a = 1;
    b = 0;
    return;
  }
  if (i == 1) {
    a = -1;
    b = 1;
    return;
  }

  a = b = 0;

  int sz = pascal_sz[i - 1];
  int sign = 1;
  for (int j = 0; j < sz; ++j) {
    int ie = i - j;
    int ke = ie % 4;

    int v = pascal[i - 1][j] * sign;

    switch (ke) {
      case 0:
        a += v;
        break;
      case 1:
        b += v;
        break;
      case 2:
        a -= v;
        break;
      case 3:
        b -= v;
        break;
    }

    sign *= -1;
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  genPascal();

  int n;
  while (cin >> n) {
    int ansa, ansb;
    ansa = ansb = 0;

    for (int i = 0; i < 32; ++i) {
      int bit = n & (1 << i);
      if (bit == 0) continue;

      int a, b;

      calcular(i, a, b);

      ansa += a;
      ansb += b;
    }

    cout << ansa << ' ' << ansb << endl;
  }

  return 0;
}
