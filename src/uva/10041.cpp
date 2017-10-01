#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

static int r, *v;


int getsum(int house) {
    int sum = 0;
    for(int i = 0; i < r; i++) sum += abs(v[i]-house);
    return sum;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int caseNo, i, house, house2, sum;

    scanf("%d\n", &caseNo);
    while(caseNo--) {
        // Lectura y ordenamiento de entrada
        cin >> r;
        v = new int[r];
        for (i = 0; i < r; i++) cin >> v[i];
        sort(v, v+r-1);
        // Proceso
        if(r%2 != 0) {
            house = v[(r-1)/2];
            sum = getsum(house);
        } else {
            house2 = r/2;       house = house2 - 1;
            house2 = v[house2]; house = v[house];
            sum = min(getsum(house), getsum(house2));
        }

        for(i = 1; i < r; i++) sum = min(sum, getsum(v[i]));
        // Resultado
        cout << sum << endl;
    }

    return 0;
}
