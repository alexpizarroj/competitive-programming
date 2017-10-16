#include <iostream>
#include <string>
using namespace std;

string Resolver(int ancho_cinta, int num_corte) {
  int num_corte_simplificado = (num_corte - 1) % (ancho_cinta * 9);

  int digito_parte_izq = (num_corte_simplificado / ancho_cinta) + 1;
  int digito_parte_der = (digito_parte_izq == 9 ? 1 : digito_parte_izq + 1);

  int num_digitos_parte_der = num_corte_simplificado % ancho_cinta;
  int num_digitos_parte_izq = ancho_cinta - num_digitos_parte_der;

  return string(num_digitos_parte_izq, digito_parte_izq + '0') +
         string(num_digitos_parte_der, digito_parte_der + '0');
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ancho_cinta, num_corte;
  while (cin >> ancho_cinta >> num_corte)
    cout << Resolver(ancho_cinta, num_corte) << '\n';

  return 0;
}
