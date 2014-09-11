#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    vector<int> v;
    vector<int>::iterator it;
    const int tope = 10000;
    int aux, diff, caso;

    v.reserve(20);
    aux = 1;
    while( aux <= tope ) {
        v.push_back(aux);
        aux = aux<<1;
    }
    v.push_back(aux);

    caso = 1;
    scanf("%d", &aux);
    while( aux >= 1 ) {
        it = lower_bound(v.begin(), v.end(), aux);
        diff = it-v.begin();
        printf("Case %d: %d\n", caso++, diff);

        scanf("%d", &aux);
    }

    return 0;
}
