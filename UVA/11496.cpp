#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, ans, h, h1, h2, i;
    bool inicio, alto;

    while (true) {
        cin >> n; ans=1;
        if(n==0) break; else getchar();
        // Contar picos
        cin >> h1 >> h2;
        h = h1;
        n -= 2;
        alto = (h1 > h2); inicio = alto;
        for(i=0; i<=n; i++) {
            if(i!=n) {
                swap(h1,h2); cin >> h2;
            } else {
                swap(h1,h2); h2=h;
                if(alto!=inicio) break;
            }
            if(alto) {
                if(h1 < h2) {ans++; alto = false;}
            } else {
                if(h1 > h2) {ans++; alto = true;}
            }
        }
        cout << ans << endl;
    }

    #ifndef ONLINE_JUDGE
        fclose(stdout);
    #endif
    return 0;
}
