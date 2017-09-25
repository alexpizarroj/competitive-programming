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
#define fup(i,a,b) for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); i++)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
using namespace std;

char bufa[100], bufb[100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    typedef vector<int> vi;
    typedef vector<vi> AdjList;
    typedef priority_queue< int, vector<int>, greater<int> > MinQueue;

	int n, m, caseNo = 0;
	vector<string> drinkById;
	map<string,int> idByDrink;
	AdjList graph; vi inDeg;
	MinQueue q; vi ans;

	while ( scanf("%d", &n) != EOF )
	{
	    drinkById.clear();
	    drinkById.reserve(n);
	    idByDrink.clear();
	    fup(i,0,n)
	    {
	        scanf("%s", bufa);
	        drinkById.PB( string(bufa) );
	        idByDrink[ string(bufa) ] = i;
	    }

	    graph.assign( n, vi() );
	    inDeg.assign( n, 0 );
	    scanf("%d", &m);
	    fup(i,0,m)
	    {
	        scanf("%s %s", bufa, bufb);
	        int u = idByDrink[bufa], v = idByDrink[bufb];
	        graph[u].PB(v);
	        ++inDeg[v];
	    }

        ans.clear();
        fup(i,0,n) if ( inDeg[i] == 0 ) q.push(i);
        while ( !q.empty() )
        {
            int u = q.top(); q.pop();
            fup(i,0,graph[u].size())
            {
                int v = graph[u][i];
                if ( 0 == --inDeg[v] ) q.push(v);
            }
            ans.PB(u);
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", ++caseNo);
        foreach(it, ans) printf(" %s", drinkById[*it].c_str() );
        puts(".\n");
	}

    return 0;
}
