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
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline bool isvowel(char c)
{ c = tolower(c); return( c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); }

inline string PigLatin(const string &s)
{
    if( isvowel(s[0]) )
        return s+"ay";
    else
        return s.substr(1,len(s)-1) + s[0] + "ay";
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int i, start, len;
    string s;

    while( getline(cin,s) )
    {
        len=0;
        start=-1;
        FOR(i,sz(s))
        {
            if( !isalpha(s[i]) )
            {
                if( len > 0 ) cout << PigLatin(s.substr(start,len));
                cout << s[i];
                start = -1;
                len = 0;
            }
            else
            {
                if( start==-1 ) start=i;
                len++;
            }
        }
        if( len > 0 ) cout << PigLatin(s.substr(start,len));
        puts("");
    }


    return 0;
}
