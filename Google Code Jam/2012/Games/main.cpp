// {
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
using namespace std;
// } {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define tokenize(pc, searchString, tokenString) for(char* pc = strtok(searchString, tokenString); pc != NULL; pc = strtok(NULL,tokenString))
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define set(a,v) memset( (a), v, sizeof(a) )
// } {
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};
// } {
template<typename T>
bool inline between(const T& lbound, const T& value, const T& ubound)
{ return lbound <= value && value <= ubound; }
// }

#define MAX_N 101
set<int> outEdges[MAX_N]; // adjacency list
int nInEdges[MAX_N]; // number of incoming edges
typedef priority_queue<int, deque<int>, std::greater<int> > least_first_heap;

int main() {
	#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	int tc, n, m, x, k, gameId, cont, cont2;
	vector<int> solution;
	least_first_heap tasks;

    cin >> tc;
	while( tc-- )
	{
	    // Input
	    scanf("%d %d", &n, &m);
	    set(nInEdges, 0);
	    REP(cont,n)
	    {
	        outEdges[n].clear();
	    }
	    FOR(cont,m)
	    {
	        scanf("%d %d", &x, &k);
            FOR(cont2, k)
            {
                scanf("%d", &gameId);
                if( outEdges[gameId].count(x) == 0 )
                {
                    outEdges[gameId].insert(x);
                    nInEdges[x]++;
                }
            }
	    }

	    // Resolution
        REP(cont,n)
        {
            if( nInEdges[cont] == 0 )
            {
                tasks.push(cont);
            }
        }
        solution.clear();
        while( !tasks.empty() )
        {
            int task = tasks.top();
            tasks.pop();
            solution.push_back(task);

            foreach( it, outEdges[task] )
            {
                int endNode = *it;
                nInEdges[endNode]--;
                if( nInEdges[endNode] == 0 )
                {
                    tasks.push(endNode);
                }
            }

            outEdges[task].clear();
        }

	    // Output
	    foreach(it, solution)
	    {
	        if( it != solution.begin() )
	        {
	            printf(" ");
	        }
            printf("%d", *it);
	    }
        puts("");
	}

	fclose(stdout);
    return 0;
}
