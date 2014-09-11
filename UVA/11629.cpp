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


#define EPS 10E-2
char buffer[21], line[1001];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int p, g, i;
    string scomp; char *pc;

    map<string, double> party;
    double fval1, fval2;
    int val1, val2;
    bool isOperator, gotComparison, wasRight;

    scanf("%d %d", &p, &g); getchar();
    while(p--)
    {
        scanf("%s %lf", buffer, &fval1); getchar();
        party[ string(buffer) ] = fval1;
    }

    REP(i,g)
    {
        gets(line); fval1=0;
        isOperator = gotComparison = false;
        pc=strtok(line," ");
        while( pc != NULL )
        {
            if( isOperator )
            {
                if( pc[0] != '+' )
                {
                    gotComparison = true;
                    scomp = string(pc);
                }
            }
            else
            {
                if( !gotComparison )
                    fval1 += party[ string(pc) ];
                else
                {
                    sscanf(pc, "%lf", &fval2);

                    val1 = int(fval1*10+0.5);
                    val2 = int(fval2*10+0.5);

                    if( scomp == "<" )
                        wasRight = val1 < val2;
                    else if( scomp == ">" )
                        wasRight = val1 > val2;
                    else if( scomp == "<=" )
                        wasRight = val1 <= val2;
                    else if( scomp == ">=" )
                        wasRight = val1 >= val2;
                    else
                        wasRight = val1==val2;
                }
            }

            isOperator=!isOperator;
            pc=strtok(NULL," ");
        }

        if( wasRight )
            printf("Guess #%d was correct.\n", i);
        else
            printf("Guess #%d was incorrect.\n", i);
    }

    return 0;
}
