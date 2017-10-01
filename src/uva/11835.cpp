#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <memory.h>
#include <algorithm>
#define piv  int, vector<int>

using namespace std;


vector<int> newIntVector() {
    vector<int> v;
    return v;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int g, p, tablas, *tabla, pos, i, j, k, best;
    map<piv> m; //formato: puesto, vector(Pilotos)
    map<piv>::iterator it;
    vector<int> v, campeones; //pilotos
    vector<int>::iterator it2;
    int* puntajes;

    while (1) {
        scanf("%d %d\n", &g, &p);
        if(g+p==0) break;
        m.clear();
        // Lectura puestos
        for(i=0;i<g;i++) {
            for(j=1;j<p+1;j++) {
                scanf("%d", &pos);
                if(m.find(pos)==m.end()) {
                    v = newIntVector();
                    m[pos] = v;
                    m[pos].push_back(j);
                } else m[pos].push_back(j);
            }
        }

        /*// Mostrar mapa
        it = m.begin();
        while(it != m.end()) {
            v = (*it).second;
            it2 = v.begin();
            cout << (*it).first << ":";
            while(it2 != v.end()) {
                cout << " " << (*it2);
                it2++;
            }
            cout << endl;
            it++;
        }
        cout << "----" << endl;*/

        // Puntajes
        puntajes = new int[p+1];
        scanf("%d\n", &tablas);
        while(tablas--) {
            memset(puntajes, 0, (p+1)*sizeof(int));
            // Tabla de puntajes por puestos
            scanf("%d", &i);
            tabla = new int[i];
            for(j=0;j<i;j++) {
                scanf("%d", &k);
                tabla[j]=k;
            }
            // Realizar puntajes
            it = m.begin();
            while(it != m.end()) {
                if ((*it).first <= i){
                    v = (*it).second;
                    it2 = v.begin();
                    while(it2 != v.end()) {
                        puntajes[(*it2)] += tabla[(*it).first-1];
                        it2++;
                    }
                }
                it++;
            }
            // Comprobar qué pilotos son campeones
            campeones.clear(); best=0;
            for(i=1;i<=p;i++) best=max(best, puntajes[i]);
            for(i=1;i<=p;i++) {
                if(puntajes[i]==best) campeones.push_back(i);
            }
            sort(campeones.begin(), campeones.end());
            it2 = campeones.begin(); i=0;
            while(it2 != campeones.end()) {
                cout << (i!=0 ? " " : "") << (*it2);
                it2++; i++;
            }
            cout << endl;
        }
    }

    #ifndef ONLINE_JUDGE
        fclose(stdout);
    #endif
    return 0;
}
