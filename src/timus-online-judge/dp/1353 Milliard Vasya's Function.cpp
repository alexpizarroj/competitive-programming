#include <cstdio>
#include <iostream>
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
using namespace std;

const int cstMaxSum = 81;
const int cstMaxDigits = 9;
int memo[cstMaxDigits+1][cstMaxSum+1];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

    fupi(digits, 0, cstMaxDigits) memo[digits][0] = 1;
    fupi(sum, 1, cstMaxSum) memo[0][sum] = 0;

    fupi(digits, 1, cstMaxDigits)
    {
        fupi(sum,1,cstMaxSum)
        {
            memo[digits][sum] = 0;
            for(int limit = min(sum,9), i = 0; i <= limit; i++)
            {
                memo[digits][sum] += memo[digits-1][sum-i];
            }
        }
    }

    int S;
    while ( scanf("%d", &S) != EOF )
    {
        printf("%d\n", memo[9][S] + (S == 1 ? 1 : 0) );
    }

    return 0;
}
