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
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()
#define SET(a,v) memset(a, v, sizeof(a))


#define CLEAR ' '
char input[10001];
int m[200];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int i, len;

    for(i=0; i<200; i++) m[i] = CLEAR;
    m['B'] = m['F'] = m['P'] = m['V'] = '1';
    m['C'] = m['G'] = m['J'] = m['K'] = m['Q'] = m['S'] = m['X'] = m['Z'] = '2';
    m['D'] = m['T'] = '3';
    m['L'] = '4';
    m['M'] = m['N'] = '5';
    m['R'] = '6';

    while( gets(input) != NULL )
    {
        len = strlen(input);

        for(i=0; i<len; i++)
            input[i] = m[ input[i] ];
        for(i=0; i<len-1; i++)
            if( input[i] == input[i+1] ) input[i] = CLEAR;

        for(i=0; i<len; i++)
            if( input[i] != CLEAR )
                printf("%c", input[i]);
        puts("");
    }

    return 0;
}
