#include <iostream>
#include <vector>
using namespace std;

void Resolver(const vector<int>& elementos, const long long suma_buscada) {
  const int n = elementos.size();

  int i = 0, j = 0;
  long long suma_actual = elementos[0];

  while (true) {
    if (suma_actual == suma_buscada) {
      cout << (i + 1) << ' ' << (j + 1) << '\n';
      return;
    }

    if (suma_actual < suma_buscada) {
      j += 1;
      if (j >= n) break;

      suma_actual += elementos[j];
    }

    if (suma_actual > suma_buscada) {
      i += 1;
      if (i >= n) break;

      suma_actual -= elementos[i - 1];
      if (i > j) {
        j = i;
        suma_actual = elementos[i];
      }
    }
  }

  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num_elementos;
  long long suma_buscada;

  while (cin >> num_elementos >> suma_buscada) {
    vector<int> elementos(num_elementos);
    for (int i = 0; i < num_elementos; ++i) cin >> elementos[i];

    Resolver(elementos, suma_buscada);
  }

  return 0;
}
