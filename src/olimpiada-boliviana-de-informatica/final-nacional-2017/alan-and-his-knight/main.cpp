#include <iostream>
#include <string>
using namespace std;

int mcd(int a, int b) {
  if (b == 0) return a;
  return mcd(b, a % b);
}

long long mcm(int a, int b) { return (long long)a / mcd(a, b) * b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num_casos;
  cin >> num_casos;

  for (int caso_actual = 1; caso_actual <= num_casos; ++caso_actual) {
    int nf, nc, f, c, df, dc;
    string dir;
    cin >> nf >> nc >> f >> c >> df >> dc >> dir;

    int num_pasos_por_ciclo_f = mcm(nf, df) / df;
    int num_pasos_por_ciclo_c = mcm(nc, dc) / dc;
    long long resp = mcm(num_pasos_por_ciclo_f, num_pasos_por_ciclo_c);

    cout << resp << '\n';
  }

  return 0;
}
