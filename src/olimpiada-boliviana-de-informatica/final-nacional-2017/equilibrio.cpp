#include <iostream>
#include <utility>
using namespace std;

void Actualizar(int nuevo_factor, int& menor_factor, int& mayor_factor) {
  if (menor_factor == -1 || menor_factor > nuevo_factor)
    menor_factor = nuevo_factor;

  if (mayor_factor == -1 || mayor_factor < nuevo_factor)
    mayor_factor = nuevo_factor;
}

pair<int, int> EncontrarMenorYMayorFactor(int n) {
  int menor_factor = -1, mayor_factor = -1;

  for (int factor = 2; factor * factor <= n; ++factor) {
    if (n % factor != 0) continue;

    while (n % factor == 0) n /= factor;

    Actualizar(factor, menor_factor, mayor_factor);
  }

  if (n != 1) Actualizar(n, menor_factor, mayor_factor);

  return make_pair(menor_factor, mayor_factor);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num_casos;
  cin >> num_casos;

  for (int nc = 1; nc <= num_casos; ++nc) {
    int n;
    cin >> n;

    pair<int, int> factores = EncontrarMenorYMayorFactor(n);
    if (factores.first == factores.second) {
      cout << "Equilibrio\n";
    } else {
      cout << "[" << factores.first << "," << factores.second << "]\n";
    }
  }

  return 0;
}
