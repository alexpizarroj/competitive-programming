#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    map<string,int> m;
    map<string,int>::iterator it;
    string linea, pais;
    int n;

    // Entrada
    cin >> n; getchar();

    // Conteo
    while( n-- )
    {
        getline(cin,linea);
        pais = linea.substr(0, linea.find(' ') );
        m[pais]++;
    }

    // Salida
    for( it = m.begin(); it != m.end(); it++ )
        cout << (*it).first << " " << (*it).second << endl;

    return 0;
}