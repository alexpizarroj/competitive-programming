#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define uint unsigned int

using namespace std;


void putOnV(vector<uint> *v, int valor) {
    vector<uint>::iterator it = find(v->begin(), v->end(), valor);
    if (it == v->end()) v->push_back(valor);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    uint casos, oc, c, r, i, j, k, lim;
    vector<uint> v; vector<uint>::iterator it;

    scanf("%d\n", &casos);
    for(i=1; i <= casos; i++) {
        scanf("%d %d\n", &oc, &r);
        c = oc-r; v.clear();
        if(i==11) {
            i=11;
        }
        // Resolución
        if (oc==r) {
            v.push_back(0);
        } else if (c > r) {
            v.push_back(c);
            lim = floor(sqrt(c));
            for(j=2; j<=lim; j++) {
                if(c%j==0) {
                    k = c/j;
                    if(k > r) putOnV(&v, k);
                    if(j > r) putOnV(&v, j);
                }
            }
            if(r==0) putOnV(&v, 1);
            sort(v.begin(), v.end());
        }
        // Respuesta
        printf("Case #%d:", i);
        it = v.begin();
        while (it != v.end()) {
            printf(" %d", *it);
            it++;
        }
        cout << endl;
    }

    #ifndef ONLINE_JUDGE
        fclose(stdout);
    #endif
    return 0;
}
