#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
    int t, n, caseNo = 1;
    char m[30][30];
    bool valid, tried;

    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d", &n); getchar();
        fup(i,0,n) gets(m[i]);

        valid = 1, tried = 0;
        fup(i,0,n)
        {
            if ( tried ) break;
            fup(j,0,n)
            {
                if ( m[i][j] != '#' ) continue;

                int h=0, w=0, k;
                for(k = i; k < n && m[k][j] == '#'; ++k) ++h;
                for(k = j; k < n && m[i][k] == '#'; ++k) ++w;

                if ( h == w )
                {
                    fup(k,i,i+h) fup(h,j,j+w)
                    {
                        if ( m[k][h] == '.' ) valid = 0;
                        m[k][h] = '.';
                    }
                    fup(k,0,n) fup(h,0,n)
                    {
                        if ( m[k][h] == '#' ) valid = 0;
                    }
                }
                else
                {
                    valid = 0;
                }

                tried = 1; break;
            }
        }

        printf("Case #%d: %s\n", caseNo++, tried && valid ? "YES" : "NO");
    }

    return 0;
}
