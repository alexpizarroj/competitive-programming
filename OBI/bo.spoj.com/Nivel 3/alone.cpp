#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;

int main() {
    //freopen("alone.in", "r", stdin);
    //freopen("alone.mine.out", "w", stdout);

    int n, len, i, j;
    int cnt[256];
    string s;

    while ( cin >> n && n != 0 ) {
        getchar();
        getline(cin, s);
        len = s.size();

        memset(cnt, 0, sizeof cnt);
        FOR(i,len) cnt[s[i]]++;

        FOR(i,256) if( cnt[i] == 1 ) {
            FOR(j,len) if( s[j] == i ) {
                cout << j+1 << endl;
                break;
            }
            break;
        }
    }

    return 0;
}
