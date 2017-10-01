#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#define PB 				        push_back
#define F                       first
#define S                       second
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dinit(a) 		        memset(a, -1, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
#define dbet(lb,v,ub)			(lb <= v && v <= ub)
using namespace std; const int INF = int(1E9+7);
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> ii; typedef vector<int> vi;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	size_t t, n, answer, k, mask;
	vector<size_t> A;
	char oper[5];

	scanf("%u", &t);
	for(size_t caseNo = 0; caseNo < t; caseNo++)
	{
	    // Input
	    scanf("%u %u %u", &n, &k, &answer);
	    A.resize(n);
	    for(size_t i = 0; i < n; i++)
	    {
	        scanf("%u", &A[i]);
	    }
	    scanf("%s", oper);

	    // Array consumption
	    mask = A[0];
	    for(size_t i = 1; i < n; i++)
	    {
	        switch (oper[0])
	        {
	            case 'X':
	            {
	                mask ^= A[i];
	                break;
	            }
	            case 'O':
	            {
	                mask |= A[i];
	                break;
	            }
	            case 'A':
	            {
	                mask &= A[i];
	                break;
	            }
	        }
	    }

	    // Answer
	    switch (oper[0])
        {
            case 'X':
            {
                if ( (k&1) == 1 )
                {
                    answer ^= mask;
                }
                break;
            }
            case 'O':
            {
                if ( k > 0 )
                {
                    answer |= mask;
                }
                break;
            }
            case 'A':
            {
                if ( k > 0 )
                {
                    answer &= mask;
                }
                break;
            }
        }
        printf("%u\n", answer);
	}

    return 0;
}
