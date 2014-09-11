#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define NOT_SET -1
#define NOT_SOLVABLE -2
typedef vector<int> vi;

vector<vi> flavors;
int memo[201][21];

int best(int pivote, int num1, int num2) {
    if( num1 > pivote && num2 > pivote )
        return NOT_SOLVABLE;
    else if( num1 <= pivote && num2 <= pivote )
        return max(num1, num2);
    else if( num1 <= pivote )
        return num1;
    else
        return num2;
}

int solve(int m, int c) {
    if( c < 0 ) return NOT_SOLVABLE;
    if( memo[m][c] !=  NOT_SET ) return memo[m][c];

    int i, len, idx, k, r;

    idx = c-1;
    len = flavors[idx].size();
    k = NOT_SOLVABLE;

    if ( c == 1 ){

        for(i=0; i<len; i++)
            k = best(m, k, flavors[idx][i]);

    } else {

        for(i=0; i<len; i++) {
            r = solve(m-flavors[idx][i], c-1);
            if( r != NOT_SOLVABLE ) {
                k = best(m, k, flavors[idx][i]+r);
            }
        }

    }

    return memo[m][c] = k;
}

int main() {
    freopen("helado.in", "r", stdin);
    freopen("helado.mine.out", "w", stdout);

    int n, m, c, k;
    vi prices;
    int cost, i;

    cin >> n;
    while ( n-- ) {

        cin >> m >> c;
        flavors.clear();

        for(i=0; i<c; i++) {
            cin >> k;
            prices.clear();

            while( k-- ) {
                cin >> cost;
                prices.push_back(cost);
            }
            sort(ALL(prices));

            flavors.push_back( prices );
        }

        cost = 0;
        for(i=0; i<flavors.size(); i++)
            cost += flavors[i][0];

        if( cost <= m ) {
            memset(memo, NOT_SET, sizeof memo);
            cout << solve(m,c) << endl;
        } else {
            cout << "No es posible" << endl;
        }

    }

    return 0;
}
