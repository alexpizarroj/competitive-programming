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


int m;
bool cmp(int a, int b){
    if( a%m != b%m )
        return a%m < b%m;
    if( abs(a%2) != abs(b%2) )
        return abs(a%2)==1;
    if( a%2 == 0 )
        return a < b;
    return a > b;
}

int a[10000];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int n,i;

    while( scanf("%d %d", &n, &m), (n!=0 || m!=0) )
    {
        printf("%d %d\n", n, m);
        FOR(i,n) scanf("%d", a+i);
        sort(a,a+n,cmp);
        FOR(i,n) printf("%d\n", a[i]);
    }
    puts("0 0");

    return 0;
}
