#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ContarOvejasConectadas(int oveja_inicial,
                           const vector<vector<int> >& parejas,
                           vector<bool>& fue_vista) {
  int total_ovejas = 0;
  queue<int> ovejas_pendientes;

  ovejas_pendientes.push(oveja_inicial);
  fue_vista[oveja_inicial] = true;

  while (!ovejas_pendientes.empty()) {
    const int oveja = ovejas_pendientes.front();
    ovejas_pendientes.pop();
    total_ovejas += 1;

    for (int i = 0; i < (int)parejas[oveja].size(); ++i) {
      const int oveja_pareja = parejas[oveja][i];
      if (fue_vista[oveja_pareja]) continue;

      ovejas_pendientes.push(oveja_pareja);
      fue_vista[oveja_pareja] = true;
    }
  }

  return total_ovejas;
}

void Resolver(int num_ovejas, const vector<vector<int> >& parejas) {
  int tam_max_raza = 0;
  int num_razas = 0;
  vector<bool> fue_vista(num_ovejas + 1, false);

  for (int oveja = 1; oveja <= num_ovejas; ++oveja) {
    if (fue_vista[oveja]) continue;

    int ovejas_contadas = ContarOvejasConectadas(oveja, parejas, fue_vista);

    tam_max_raza = max(tam_max_raza, ovejas_contadas);
    num_razas += 1;
  }

  cout << "Existen " << num_razas << " posibles razas\n";
  cout << "La raza que tiene mas obejas tiene " << tam_max_raza << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num_ovejas, num_pares;
  while (cin >> num_ovejas >> num_pares) {
    if (num_ovejas == 0) break;

    vector<vector<int> > parejas(num_ovejas + 1, vector<int>());

    for (int i = 0; i < num_pares; ++i) {
      int oveja1, oveja2;
      cin >> oveja1 >> oveja2;

      parejas[oveja1].push_back(oveja2);
      parejas[oveja2].push_back(oveja1);
    }

    Resolver(num_ovejas, parejas);
  }

  return 0;
}
