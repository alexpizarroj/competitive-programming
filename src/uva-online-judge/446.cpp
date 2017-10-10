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
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define SQR(a) (a)*(a)
#define PB push_back
#define MP make_pair
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


inline int GetHexCharVal(const char c)
{ return ( isalpha(c) ? tolower(c)-'a'+10 : c-'0' ); }

int GetHexVal(const char *s)
{
    int n=strlen(s),i,j,val=0;
    for(i=n-1,j=0; i>=0; i--,j++)
        val += GetHexCharVal(s[i])*pow(16,j);

    return val;
}

string HexToBin(const char *s)
{
    string r(13, '0');
    int n=strlen(s),i,j,k,val;

    for(i=n-1,j=LEN(r)-1; i>=0; i--)
    {
        val = GetHexCharVal(s[i]);
        REP(k,4)
            r[j--] = (val%2)+'0', val /= 2;
    }

    return r;
}

char input[101];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t;
    int i, val1, val2;
    char op;

    scanf("%d",&t);getchar();
    while(t--)
    {
        gets(input); i=0;
        TOK(pc,input," ")
        {
            if( i==0 )
            {
                val1=GetHexVal(pc);
                printf("%s", HexToBin(pc).c_str());
            }
            else if( i==1 )
            {
                op=pc[0];
                printf(" %c ", op);
            }
            else
            {
                val2=GetHexVal(pc);
                printf("%s", HexToBin(pc).c_str());
            }
            i++;
        }
        printf(" = %d\n", op=='+' ? val1+val2 : val1-val2);
    }

    return 0;
}
