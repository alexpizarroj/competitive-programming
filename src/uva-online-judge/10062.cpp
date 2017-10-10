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
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define PB push_back
#define MP make_pair
#define PI acos(-1)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define range(v) (v).begin(), (v).end()
#define len(a) (int)(a).length()
#define sz(a) (int)(a).size()
#define sqr(a) (a)*(a)
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<double> vd;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


inline bool cmp(ii a, ii b)
{
    if( a.second != b.second )
        return a.second < b.second;
    return a.first > b.first;
}

char line[1001];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int i,len; vii v;
    map<int, int> mp;
    bool firstcase=true;

    while( gets(line) )
    {
        mp.clear(); v.clear();
        len=strlen(line);
        FOR(i,len) mp[ (int)line[i] ]++;
        foreach(it, mp)
            v.push_back( make_pair(it->first, it->second) );
        sort(range(v), cmp);

        if(!firstcase) puts("");
        foreach(it,v)
            printf("%d %d\n", it->first, it->second);
        firstcase=false;
    }

    return 0;
}
