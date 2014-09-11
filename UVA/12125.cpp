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
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

// Graph Structure
// 0 -> (nFloes-1):         floes in vertices
// nFloes -> (2*nFloes-1):  floes out vertices
// 2*nFloes:                source
// 2*nFloes+1:              sink
const int MAX = 210;
vector<vi> adjlist;
int cap[MAX][MAX], flow[MAX][MAX];
int s, t, n, nFloes;

int find_path()
{
    vi from(n, -1), visited(n,0);
    queue<int> q; int u, v, f;

    q.push(s); visited[s] = true;
    while ( !visited[t] && !q.empty() )
    {
        u = q.front(); q.pop();
        fup(i,0,adjlist[u].size())
        {
            v = adjlist[u][i];
            if ( (cap[u][v]-flow[u][v]) > 0 && !visited[v] )
            {
                //cout << "Queuing: " << u << "->" << v << endl;
                from[v] = u;
                q.push(v); visited[v] = true;
                if ( v == t ) break;
            }
        }
    }
    //cout << "---" << endl;

    f = INF;
    if ( visited[t] )
    {
        for(v = t; from[v] > -1; v = from[v])
            u = from[v], f = min(f, cap[u][v]-flow[u][v]);
        for(v = t; from[v] > -1; v = from[v])
            u = from[v], flow[u][v] += f, flow[v][u] -= f;
    }

    return (f == INF ? 0 : f);
}

int maxflow()
{
    int mf = 0, d;
    while ((d = find_path())) mf += d;
    return mf;
}

int getout(int u) { return u + nFloes; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int nCases, x, y, pen, m;
	vector<ii> id_pos;
	vi id_npen, ans;
	double D; int totalpen;

	scanf("%d", &nCases);
	while ( nCases-- )
	{
	    scanf("%d %lf", &nFloes, &D);

        // Graph init
        n = 2*nFloes+2;
        adjlist.assign(n, vi());
	    memset(cap, 0, sizeof cap);
	    s = n-2, t = n-1;

	    // In/out vertices init
	    totalpen = 0;
        id_pos.clear(); id_npen.clear();
	    fup(i,0,nFloes)
	    {
	        scanf("%d %d %d %d", &x, &y, &pen, &m);
	        id_pos.PB(ii(x,y)); id_npen.PB(pen);

            int i_out = getout(i); // out vertex
            adjlist[i].PB(i_out); adjlist[i_out].PB(i);
            cap[i][i_out] = m;

            totalpen += pen;
	    }

	    // Graph interconnection
	    fup(i,0,nFloes) fup(j,i+1,nFloes)
	    {
	        double dist = hypot(id_pos[i].first - id_pos[j].first,
                             id_pos[i].second - id_pos[j].second);
            if ( dist < D || fabs(dist-D) < EPS )
            {
                int i_out = getout(i), j_out = getout(j);

                adjlist[i_out].PB(j); adjlist[j].PB(i_out);
                cap[i_out][j] = INF;

                adjlist[j_out].PB(i); adjlist[i].PB(j_out);
                cap[j_out][i] = INF;

                //cout << i << "<->" << j << endl;
            }
	    }

	    // Source -> All, All -> Sink (0 capacity connection)
	    fup(i,0,nFloes)
	    {
	        adjlist[s].PB(i); adjlist[i].PB(s);
	        adjlist[i].PB(t); adjlist[t].PB(i);
	    }

	    // Modeling & Max Flow
	    ans.clear();
	    fup(i,0,nFloes)
	    {
	        memset(flow, 0, sizeof flow);

	        cap[i][t] = INF;
	        fup(j,0,nFloes) cap[s][j] = ( i == j ? 0 : id_npen[j]);

            int mf = id_npen[i];
            //cout << "Testing " << i << " as meeting point." << endl;
            //cout << mf << " penguin(s) already on target location." << endl;
            mf += maxflow();
            //cout << mf << " penguin(s) after flow." << endl;
	        if ( mf == totalpen ) ans.PB(i);

	        cap[i][t] = 0;
	        fup(j,0,nFloes) cap[s][j] = 0;
	    }

	    // Output
	    if ( ans.size() == 0 ) puts("-1");
	    else
	    {
	        printf("%d", ans[0]);
	        fup(i,1,ans.size()) printf(" %d", ans[i]);
	        puts("");
	    }
	}

    return 0;
}
