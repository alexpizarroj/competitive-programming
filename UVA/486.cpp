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

map<string,int> m;
char line[1000];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int lastK, val, sum, k;
    bool negative;
    void InitMap(); InitMap();

    while( gets(line) )
    {
        val = sum = negative = 0;
        lastK = INT_MAX;
        TOK(pc, line, " ")
        {
            k = m[string(pc)];
            if( k == -1 )
                negative = true;
            else
            {
                if( lastK > k )
                {
                    val += k;
                }
                else
                {
                    val *= k;
                    if( k == 1000000 || k == 1000 )
                    {
                        sum += val;
                        val = 0;
                    }
                }
                lastK = k;
            }
        }
        sum += val;
        if( negative ) sum *= -1;

        printf("%d\n",sum);
    }

    return 0;
}

void InitMap()
{
    m["negative"]=-1;
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    m["ten"]=10;
    m["eleven"]=11;
    m["twelve"]=12;
    m["thirteen"]=13;
    m["fourteen"]=14;
    m["fifteen"]=15;
    m["sixteen"]=16;
    m["seventeen"]=17;
    m["eighteen"]=18;
    m["nineteen"]=19;
    m["twenty"]=20;
    m["thirty"]=30;
    m["forty"]=40;
    m["fifty"]=50;
    m["sixty"]=60;
    m["seventy"]=70;
    m["eighty"]=80;
    m["ninety"]=90;
    m["hundred"]=100;
    m["thousand"]=1000;
    m["million"]=1000000;
}
