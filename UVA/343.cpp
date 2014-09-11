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


inline int GetVal(char c)
{
    if( isdigit(c) )
        return c-'0';
    else
        return c-'A'+10;
}

int MinBase(const string& s)
{
    int m=0;
    for(size_t i=0; i<s.size(); i++)
        m = max( GetVal(s[i]), m );
    return max(m+1,2);
}

ull GetNumVal(const string& s, const int base)
{
    ull sum=0, mult=1;
    for(int i=s.size()-1; i>=0; i--, mult*=base)
        sum += GetVal(s[i]) * mult;
    return sum;
}


int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	string num1, num2;
	int x,y,i,j;
	bool found;

	while( cin >> num1 >> num2 )
	{
	    x = MinBase(num1), y = MinBase(num2);
	    found = false;
        for(i=x; i<=36 && !found; i++)
        {
            for(j=y; j<=36 && !found; j++)
            {
                if( GetNumVal(num1,i) == GetNumVal(num2,j) )
                {
                    found=true;
                    printf("%s (base %d) = %s (base %d)\n", num1.c_str(), i, num2.c_str(), j);
                }
            }
        }
        if( !found )
            printf("%s is not equal to %s in any base 2..36\n", num1.c_str(), num2.c_str());
	}

    return 0;
}
