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
#include <fstream>
#define PB 				        push_back
#define MP 				        make_pair
#define fup(i,a,b) 		        for(int i = (a); (i) < (b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > (b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= (b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= (b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define container(a) 	        (a).begin(), (a).end()
#define set(a,v) 		        memset(a, v, sizeof(a))
#define clear(a)                memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, std::greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = 1E9+7;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif


	const char veck[] = "MARGARITA";
	int lenk = strlen(veck);
	int tc, len, nPizzas, nLetter[30];
	char input[601];
	bool can_make;

	scanf("%d", &tc); getchar();
	while ( tc-- )
	{
	    // Input
        gets(input);
        len = strlen(input);

        // Process
        set(nLetter, 0);
        fup(i,0,len)
        {
            nLetter[ input[i]-'A' ]++;
        }

        can_make = true;
        nPizzas = 0;
        while( can_make )
        {
            fup(i, 0, lenk)
            {
                int l = int(veck[i]-'A');
                if( nLetter[l] > 0 )
                {
                    nLetter[l]--;
                }
                else
                {
                    can_make = false;
                }
            }
            if( can_make ) nPizzas++;
        }

        // Result
        printf("%d\n", nPizzas);
	}

    fclose(stdout);
    return 0;
}
