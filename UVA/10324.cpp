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
#include <cmath>
#include <climits>
#include <cctype>
#include <fstream>
#define PB 				        push_back
#define MP 				        make_pair
#define fup(i,a,b) 		        for(int i = (a); (i) < (b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > (b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= (b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= (b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define all(a)       	        (a).begin(), (a).end()
#define set(a,v) 		        memset(a, v, sizeof(a))
#define clr(a)                  memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, std::greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = 1E9+7;


char cad[1000005];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif

    int l, r, len, n, tc=1;
    vector<int> vec;
    char last;

    while( gets(cad) != NULL )
    {
        // Input and string processing
        len = strlen(cad);
        if( len == 0 ) break;
        vec.clear();
        vec.PB(0);
        last = cad[0];
        fup(i,1,len)
        {
            if( cad[i] != last )
            {
                last = cad[i];
                vec.PB(i);
            }
        }

        // Case
        printf("Case %d:\n", tc++);
        //foreach(it,vec) cout << (*it) << " "; cout << endl;

        scanf("%d", &n);
        while( n-- )
        {
            scanf("%d %d", &l, &r);
            if( l > r ) swap(l, r);

            int end_pos, start_pos;
            if( binary_search( all(vec), l ) )
            {
                end_pos = upper_bound( all(vec), l ) - vec.begin();
            }
            else
            {
                end_pos = lower_bound( all(vec), l ) - vec.begin();
            }
            start_pos = end_pos - 1;

            int start = between( 0,start_pos,int(vec.size()-1) ) ? vec[start_pos] : 0;
            int end   = between( 0,end_pos,  int(vec.size()-1) ) ? vec[end_pos]-1 : len-1;

            //cout << " Req " << l << "-" << r << " : Closer " << start << "-" << end << endl;
            if( start <= l && r <= end )
                puts("Yes");
            else
                puts("No");
        }
        getchar();
    }

    fclose(stdout);
    return 0;
}


// SOLUCION ALTERNATIVA
/*
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


#define MAXN 1000001
int n;
char a[MAXN];
struct nodo{
    bool zero, one;
    nodo() { }
    nodo(bool _zero, bool _one){
        zero = _zero;
        one = _one;
    }
}T[MAXN*4];


void init(int b, int e, int node)
{
    if(b == e)
    {
        if( a[b]=='1' ) { T[node].one = true;  T[node].zero = false; }
        else            { T[node].one = false; T[node].zero = true;  }
    }
    else
    {
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        init(b, mid, le);
        init(mid + 1, e, ri);

        T[node].zero = T[le].zero || T[ri].zero;
        T[node].one  = T[le].one  || T[ri].one;
    }
}

nodo query(int b, int e, int node, int i, int j)
{
    if(i <= b && e <= j) return T[node];

    int mid = (b + e) / 2, le = 2*node + 1, ri = 2*node + 2;

    if(j <= mid) return query(b, mid, le, i, j);
    else if(mid < i) return query(mid + 1, e, ri, i, j);
    else
    {
        nodo ret1 = query(b, mid, le, i, j);
        nodo ret2 = query(mid + 1, e, ri, i, j);

        nodo ret;
        ret.zero = ret1.zero || ret2.zero;
        ret.one  = ret1.one  || ret2.one;
        return ret;
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	#endif

    int q, i, j, caseNo=1;

    while( gets(a) != NULL && strlen(a) > 0 )
    {
        printf("Case %d:\n", caseNo++);
        n = strlen(a);
        init(0, n-1, 0);

        scanf("%d", &q); getchar();
        while(q--)
        {
            scanf("%d %d", &i, &j); getchar();
            if( i > j ) swap(i,j);
            nodo qn = query(0, n-1, 0, i, j);
            if( qn.zero ^ qn.one )
                puts("Yes");
            else
                puts("No");
        }
    }

	return 0;
}

*/