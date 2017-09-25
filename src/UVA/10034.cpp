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

// UNION-FIND
vector<int> pset, set_size; int disjointSetsSize;
void initSet(int N) {
	pset.assign(N,0); set_size.assign(N,1); disjointSetsSize=N;
	for(int i=0; i<N; i++) pset[i]=i;
}
int findSet(int i) 	{ return (pset[i]==i) ? i : (pset[i]=findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j)	 {
	if( !isSameSet(i,j) )
	{ set_size[findSet(j)] += set_size[findSet(i)]; pset[findSet(i)] = findSet(j); disjointSetsSize--; }
}
int numDisjointsSets() { return disjointSetsSize; }
int sizeOfSet(int i)   { return set_size[findSet(i)]; }


typedef pair<double,double> pdd;
typedef pair<int,int> pii;
typedef pair<double,pii> edge_t;
bool cmp_edge(edge_t a, edge_t b) { return (a.first < b.first); }

int n;
pdd points[100];
vector<edge_t> edges;

inline double dist(const pdd a, const pdd b) { return hypot(a.first-b.first, a.second-b.second); }

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t,i,j;
    double ans;
    bool firstcase=true;

    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d", &n);
        FOR(i,n) scanf("%lf %lf", &points[i].first, &points[i].second);
        ans=0;

        // KRUSKAL
        initSet(n);
        edges.clear();
        for(i=0;i<n;i++) for(j=i+1;j<n;j++)
            edges.push_back( make_pair( dist(points[i],points[j]), make_pair(i,j) ) );
        sort(edges.begin(), edges.end(), cmp_edge);
        for(i=0;i<(int)edges.size();i++)
        {
            edge_t &e = edges[i];
            if( !isSameSet(e.second.first, e.second.second) )
            {
                unionSet(e.second.first, e.second.second);
                ans += e.first;
            }
        }

        if(!firstcase) puts("");
        printf("%.2lf\n", ans);
        firstcase=false;
    }

    return 0;
}
