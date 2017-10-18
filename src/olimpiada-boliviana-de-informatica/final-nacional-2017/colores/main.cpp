#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<int> prec_color_dominante;

void PrecalcularColoresDominantes(int num_max_colores) {
  prec_color_dominante.resize(num_max_colores + 1);
  
  prec_color_dominante[1] = 1;
  for (int c = 2; c <= num_max_colores; ++c) {
    int color = prec_color_dominante[c - 1] + 2;
    if (prec_color_dominante[c - 1] == c - 1) color = 1;
    prec_color_dominante[c] = color;
  }
}

bool EsColorMersenne(int color) {
  if (color <= 1) return false;

  int num = color + 1;
  while (num > 1) {
    if (num % 2 == 1) return false;
    num /= 2;
  }

  return true;
}

const int kPintarConFirmaMelchor = -1, kPintarConColorBlanco = 1;

int ObtenerPinturaDeCelda(const int nro_celda) {
  if (nro_celda == 0) return kPintarConFirmaMelchor;
  
  int color = prec_color_dominante[nro_celda];
  if (!EsColorMersenne(color)) color = kPintarConColorBlanco;
  return color;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int kCantidadMaximaDeCeldas = 1000 * 1000;
  PrecalcularColoresDominantes(kCantidadMaximaDeCeldas);

  int num_casos;
  cin >> num_casos;

  for (int nc = 1; nc <= num_casos; ++nc) {
    int num_filas, num_columnas;
    cin >> num_filas >> num_columnas;

    cout << "Cuadro " << nc << '\n';

    for (int i = 0; i < num_filas; ++i) {
      for (int j = 0; j < num_columnas; ++j) {
        int num_colores = i * num_columnas + j;

        int pintura = ObtenerPinturaDeCelda(num_colores);
        if (pintura == kPintarConFirmaMelchor)
          cout << 'M';
        else if (pintura == kPintarConColorBlanco)
          cout << '*';
        else
          cout << pintura;
      }
      cout << '\n';
    }
  }

  return 0;
}
