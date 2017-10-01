#include <ctime>
#include <cassert>
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
#include <numeric>

#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define forn(i, n)      for(int i = 0; i < int(n); ++i)
#define fore(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define foreach(it, a)  for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)

using namespace std;

const int inf = int(1e9+7);
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

char EMPTY_NAME[] = " ";
char fname[100005][55], lname[100005][55];

int main()
{
	int n;
    while ( cin >> n )
    {
        forn(i, n)
        {
            scanf("%s %s", fname[i], lname[i]);
            if ( strcmp(lname[i], fname[i]) < 0 )
                swap(lname[i], fname[i]);
            // cout << fname[i] << ", " << lname[i] << endl;
        }
        bool possible = true;
        char *last = EMPTY_NAME;
        forn(i, n)
        {
            int next;
            scanf("%d", &next);
            --next;
            if ( !possible )  continue;
            // cout << "Now placing " << next << ", last was " << last << endl;
            if ( strcmp(last, fname[next]) < 0 )
                last = fname[next];
            else if ( strcmp(last, lname[next]) < 0 )
                last = lname[next];
            else
                possible = false;
        }
        puts(possible ? "YES" : "NO");
    }
    return 0;
}
