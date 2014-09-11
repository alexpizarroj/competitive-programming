// IO
#include <iostream>
#include <cstdio>
// STL
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
// STRINGS
#include <string>
#include <cstring>
// OTROS
#include <cstdlib>
#include <memory.h>
#include <cmath>
// MACROS
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()


int main() {
    //freopen("data.in", "r", stdin);

    int n, v[1005], i, current;
    vector<int> st;
    st.reserve(1005);
    bool possible;

    while ( scanf("%d", &n) != EOF && n > 0 )
    {
        while ( true )
        {
            scanf("%d", v);
            if( v[0] == 0 ) break;
            for(i=1; i<n; i++) scanf("%d", v+i);

            possible = true;
            st.clear();
            i = 0;
            current = 1;
            while ( ( current <= n || st.size() > 0) && possible )
            {
                if( current < v[i] )
                {
                    while ( current < v[i] )
                    {
                        st.push_back(current);
                        current++;
                    }
                }

                if ( current == v[i] )
                {
                    current++;
                    i++;
                }
                else
                {
                    if( st.back() == v[i] )
                    {
                        i++;
                        st.pop_back();
                    }
                    else
                    {
                        possible = false;
                    }
                }
            }

            if (possible) puts("Yes");
            else puts("No");
        }
        puts("");
    }

    return 0;
}
