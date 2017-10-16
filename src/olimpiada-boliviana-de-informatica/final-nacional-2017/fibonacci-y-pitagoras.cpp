#include <iostream>
#include <vector>
using namespace std;

vector<long long> CalcularSerieFibos(int num_elementos) {
  vector<long long> fibo;

  fibo.push_back(0);
  fibo.push_back(1);

  while ((int)fibo.size() < num_elementos) {
    long long nuevo_fib = *(fibo.end() - 1) + *(fibo.end() - 2);
    fibo.push_back(nuevo_fib);
  }

  return fibo;
}

vector<long long> CalcularSerieFibosPitagoricos(int num_elementos) {
  vector<long long> fibo = CalcularSerieFibos(num_elementos + 1);

  vector<long long> serie;
  for (int i = 0; i < num_elementos; ++i) {
    long long valor = (long long)fibo[i] * fibo[i] + fibo[i + 1] * fibo[i + 1];
    serie.push_back(valor);
  }

  return serie;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<long long> serie = CalcularSerieFibosPitagoricos(44);

  int num_casos;
  cin >> num_casos;

  for (int nc = 1; nc <= num_casos; ++nc) {
    int n;
    cin >> n;
    cout << serie[n] << '\n';
  }

  return 0;
}
