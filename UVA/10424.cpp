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


inline int SumDigits(int n)
{
    int sum=0;
    while(n > 0)
        sum += n%10, n /= 10;
    return sum;
}

int GetLoveValue(const char* s)
{
    int sum=0,len=strlen(s);

    for(int i=0; i<len; i++)
        if( isalpha(s[i]) )
            sum += tolower(s[i])-'a'+1;
    while(sum>9) sum=SumDigits(sum);

    return sum;
}

char name1[30], name2[30];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int a,b;

    while( gets(name1) && gets(name2) )
    {
        a=GetLoveValue(name1);
        b=GetLoveValue(name2);
        if( a > b ) swap(a,b);
        printf("%.2f %%\n", ((float)a/b)*100);
    }

    return 0;
}
