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


map<string,int> counting;
map<string,int>::iterator it;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    char buffer[31];
    bool firstcase=true;
    int t,n;

    scanf("%d", &t); getchar();
    getchar();
    while(t--)
    {
        n=0;
        counting.clear();
        while( gets(buffer) != NULL && strlen(buffer) > 0 )
        {
            counting[ string(buffer) ]++;
            n++;
        }

        if(!firstcase) puts("");
        for(it=counting.begin(); it!=counting.end(); it++)
        {
            printf("%s %.4lf\n", it->first.c_str(), 100 * (double)(it->second)/(double)n);
        }
        firstcase=false;
    }


    return 0;
}
