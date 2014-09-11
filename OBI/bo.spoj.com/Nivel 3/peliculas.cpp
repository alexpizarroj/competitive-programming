#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;

#define DIAS 7
const int precio_dia[DIAS] = {20, 20, 10, 20, 20, 30, 30};

int main() {
    //freopen("input.txt", "r", stdin);

    int tc, i;
    int costo, dias, peliculas;
    vector<int> precios;

    cin >> tc;
    while ( tc-- )
    {
        cin >> dias >> peliculas;
        if( dias > 0 )
        {
            precios.resize(dias);
            FOR(i,dias) precios[i] = precio_dia[i%DIAS];
            sort(precios.begin(), precios.end());

            costo = 0;
            FOR(i,peliculas) costo += precios[i];
        }
        cout << costo << endl;
    }

    return 0;
}
