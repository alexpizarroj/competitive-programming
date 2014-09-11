#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define set(a,v) memset(a, v, sizeof(a))
#define len(a) (int)(a.length())


char line[105];

inline bool isValidChar(const char c) { return ('a'<=c && c<='z') || c==' ' || c==':' || c=='(' || c==')'; }

bool isBalanced(int startFrom, int n, int left)
{
    if( left < 0 ) return false;

    int i; char c, cp;
    bool defined = false, result;

    cp = '-';
    for(i=startFrom; i<n && !defined; cp = c, i++)
    {
        c = line[i];
        if( c=='(' || c==')' )
        {
            if( cp==':' )
            {
                defined = true;
                result = max(
                                isBalanced(i+1,n,left),                  // We take the face
                                isBalanced(i+1,n,left+(c=='('?1:-1))     // We don't take the face
                            );
            }
            else
            {
                if( c=='(' )
                    left++;
                else if( left > 0 )
                    left--;
                else
                {
                    defined=true;
                    result=false;
                }
            }
        }
    }

    return (defined ? result : left==0);
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int T,t,i,n;
    bool balanced;

    scanf("%d", &T); getchar();
    REP(t,T)
    {
        gets(line);
        i=0; n=strlen(line);
        balanced = true;

        FOR(i,n)
            if( !isValidChar(line[i]) )
            {
                balanced = false;
                break;
            }

        if( balanced )
            balanced = isBalanced(0, n, 0);

        printf("Case #%d: %s\n", t, balanced ? "YES" : "NO");
    }

    fclose(stdout);
    return 0;
}
