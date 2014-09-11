#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;


bool customCmp (int i, int j) { return (abs(i)>abs(j)); }
inline int signo(int x) { return x/abs(x); }

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int casos, pisos, i, k, ans;
    vector<int> v; vector<int>::iterator it;

    cin >> casos; getchar();
    while(casos--) {
        cin >> pisos; getchar();
        ans = 1; v.clear();
        // Ordenar pisos
        while (pisos--) {
            scanf("%d\n", &k);
            v.push_back(k);
        }
        sort(v.begin(), v.end(), customCmp);
        // Contar posibles
        it=v.begin(); i = (*it); it++;
        while(it != v.end()) {
            k = (*it);
            if(signo(i)!=signo(k)) {
                i = k;
                ans++;
            }
            it++;
        }
        // Resultado
        cout << ans << endl;
    }

    #ifndef ONLINE_JUDGE
        fclose(stdout);
    #endif
    return 0;
}
