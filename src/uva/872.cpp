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
using namespace std; const int INF = int(1E9+7);
typedef pair<int,int> ii; typedef vector<int> vi;

typedef vector<vi> AdjList;
AdjList graph; int n;
vi incomingDegree;
char label[20];

vector<string> solutions;
char sol[200]; int nextSolPos;

void backtrack(int mask)
{
    if ( nextSolPos == 2*n )
    {
        solutions.PB( string(sol) );
    }
    else
    {
        fup(u, 0, n) if ( mask&(1<<u) )
        {
            // Update
            mask &= ~(1<<u);
            fup(i, 0, graph[u].size())
            {
                int v = graph[u][i];
                if ( 0 == --incomingDegree[v] ) mask |= (1<<v);
            }
            sol[nextSolPos] = label[u];
            nextSolPos += 2;

            backtrack(mask);

            // Restore
            mask |= (1<<u);
            fup(i, 0, graph[u].size())
            {
                int v = graph[u][i];
                ++incomingDegree[v], mask &= ~(1<<v);
            }
            nextSolPos -= 2;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int TC, varId[256];
	char buffer[256];

	scanf("%d", &TC);
	getchar();
	fup(tc, 0, TC)
	{
        getchar();
        gets(buffer);
        n = 0;
        for(char *pch = strtok(buffer," "); pch != NULL; pch = strtok(NULL, " "))
        {
            varId[ (int)pch[0] ] = n;
            label[n] = pch[0];
            ++n;
        }

        gets(buffer);
        graph.assign(n, vi());
        incomingDegree.assign(n, 0);
        for(char *pch = strtok(buffer," "); pch != NULL; pch = strtok(NULL, " "))
        {
            int u = varId[(int)pch[0]];
            int v = varId[(int)pch[2]];
            graph[u].PB(v);
            ++incomingDegree[v];
        }

        int mask = 0;
        fup(i, 0, n) if ( incomingDegree[i] == 0 ) mask |= (1<<i);
        strcpy(sol, string(2*n-1, ' ').c_str()); nextSolPos = 0;
        solutions.clear();
        backtrack(mask);
        sort(solutions.begin(), solutions.end());

        if ( tc > 0 ) puts("");
        if ( solutions.size() > 0 )
            foreach(it, solutions) printf("%s\n", it->c_str());
        else
            puts("NO");
	}

    return 0;
}
