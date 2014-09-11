// includes {
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
// }
using namespace std;
// defines {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define sqr(a) (a)*(a)
#define inrange(lb,i,ub) ((lb) <= (i) && (i) <= (ub))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};


string quitarCeros(const string& a)
{
    size_t idx=0;
    while( a[idx] == '0' && idx < a.size() ) idx++;
    if( idx == a.size() ) idx--;

    return a.substr(idx);
}

bool esMayor(const string& a, const string& b)
{
    size_t LA = a.size(), LB = b.size();
    if( LA > LB )		return true;
    else if( LA == LB )	return (a > b);
    else				return false;
}

string resta(const string& n1, const string& n2)
{
    string a = quitarCeros(n1);
    string b = quitarCeros(n2);

	bool minus=false;
    if( esMayor(b,a) )
    {
        swap(a,b);
        minus=true;
    }

    int i, j, d = ( a.length()-b.length() );
    for(i = b.length()-1; i >= 0; i--)
    {
        if( a[i+d] >= b[i] )
            a[i+d] -= b[i]-'0';
        else
        {
            j = -1;
            while( a[i+d+j]=='0' )
            {
                a[i+d+j] = '9';
                j--;
            }
            a[i+d+j]--;

            a[i+d] += 10-b[i]+'0';
        }
    }

    return (minus ? "-" : "") + quitarCeros(a);
}


char n1[10005], n2[10005];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	int t;

	scanf("%d", &t);
	while(t--)
	{
        scanf("%s %s", n1, n2);
        printf("%s\n", resta( string(n1), string(n2) ).c_str() );
	}

    return 0;
}
