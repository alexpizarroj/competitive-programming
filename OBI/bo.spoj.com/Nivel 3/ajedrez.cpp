#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#define FOR(i,n) for(i=0;i<n;i++)
#define FOR2(i,n) for(i=1;i<=n;i++)
#define PB push_back

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool **used;
int n, nt;
vii movimientos;


inline bool valido(int x, int y) { return ( x >= 1 && x <= n ) && ( y >= 1 && y <= n ); }

int contar(int x, int y) {
    int i, mx, my, cnt=1;

    used[x][y] = true;
    FOR(i,nt) {
        mx = x + movimientos[i].first;
        my = y + movimientos[i].second;
        if( valido(mx,my) && used[mx][my] == false ) cnt += contar(mx,my);
    }

    return cnt;
}

inline int resolver(int x, int y) {
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) used[i][j] = false;
    return contar(x,y);
}

int main() {
    //freopen("ajedrez.in", "r", stdin);
    //freopen("ajedrez.mine.out", "w", stdout);

    int caseNo, x, y, i, cnt;

    cin >> caseNo;
    while ( caseNo-- ) {

        cin >> n >> nt;
        movimientos.clear();
        FOR(i,nt) {
            cin >> x >> y;
            movimientos.PB(make_pair(x,y));
        }

        used = new bool*[n+1];
        for(i=0; i<=n; i++) used[i] = new bool[n+1];

        cnt = resolver(1, 1);
        cnt = max( cnt, resolver(1, n) );
        cnt = max( cnt, resolver(n, 1) );
        cnt = max( cnt, resolver(n, n) );

        delete[] used;

        cout << cnt << endl;
    }

    return 0;
}
