#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nombre;
    cin >> nombre;
    cout << (nombre.size()%2 == 0 ? "Es Genial" : "No es Genial") << '\n';
    return 0;
}