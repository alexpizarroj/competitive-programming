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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int LOGIN = 1, LOGOUT = -1;
const int NOTSET = -1000, CANDIDATE = 1, MEMBER = 0;
struct Record { int action, user; };

Record input[100005];
int onrec[100005], localmp[100005], globalmp[100005], status[100005];

int main()
{
    int n, m, x, nlogin, k, act;
    vi anslist; char actchar;
    
    while ( scanf("%d %d", &n, &m) != EOF )
    {
        getchar();
        fill(onrec, onrec+n+1, NOTSET);
        nlogin = k = 0;
        fup(i,0,m)
        {
            scanf("%c %d", &actchar, &x); getchar();
            input[i].action = (actchar == '+'? LOGIN : LOGOUT);
            input[i].user = x;
            if ( onrec[x] == NOTSET )
            {
                onrec[x] = input[i].action;
                localmp[x] = k;
                globalmp[k++] = x;
                if ( onrec[x] == LOGOUT ) ++nlogin;
            }
        }
        anslist.clear();
        fupi(id,1,n) if ( onrec[id] == NOTSET ) anslist.PB(id);
        
        bool swept = false;
        //printf("Logged in %d\n", nlogin);
        n = k;
        fill(status, status+n, NOTSET);
        fup(rid,0,m)
        {
            x = localmp[input[rid].user], act = input[rid].action;
            if ( act == LOGIN )
            {
                if ( nlogin == 0 )
                {
                    if ( !swept )
                    {
                        k = status[x];
                        fup(i,0,n) status[i] = MEMBER;
                        if ( k != MEMBER ) status[x] = CANDIDATE;
                    }
                    else if ( status[x] == MEMBER )
                    {
                        fup(i,0,n) status[i] = MEMBER;
                        break;
                    }
                    
                    swept = true;
                    //printf("%d loggin in first\n", globalmp[x]);
                }
                else status[x] = MEMBER;
            }
            else // if ( act == LOGOUT )
            {
                if ( nlogin == 1 )
                {
                    if ( !swept )
                    {
                        k = status[x];
                        fup(i,0,n) status[i] = MEMBER;
                        if ( k != MEMBER ) status[x] = CANDIDATE;
                    }
                    else if ( status[x] == MEMBER )
                    {
                        fup(i,0,n) status[i] = MEMBER;
                        break;
                    }
                    
                    swept = true;
                    //printf("%d loggin out last\n", globalmp[x]);
                }
                else status[x] = MEMBER;
            }
            nlogin += act;
        }
        fup(i,0,n) if ( status[i] == CANDIDATE ) anslist.PB(globalmp[i]);
        
        printf("%d\n", (int)anslist.size());
        sort(ALL(anslist));
        foreach(it,anslist) printf("%d ", *it);
        if ( anslist.size() > 0 ) puts("");
    }
	
    return 0;
}
