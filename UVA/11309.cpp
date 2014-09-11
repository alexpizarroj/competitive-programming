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

bool palindromic(int hour, int minute)
{
    char cad[5];
    int len;

    if( hour > 0 )
    {
        sprintf(cad, "%d", hour);
        sprintf(cad+strlen(cad), "%02d", minute);
    }
    else
    {
        sprintf(cad, "%d", minute);
    }
    len = strlen(cad);

    for(int i=0, j=len-1; i<j; i++, j--)
    {
        if( cad[i] != cad[j] )
            return false;
    }

    return true;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif

	int tc, hh, mm;
	char time[10];

	cin >> tc; getchar();
	while(tc--)
	{
	    gets(time);
	    sscanf(time, "%d:%d", &hh, &mm );
	    do
	    {
	        mm++;
            if( mm >= 60 ) {
                hh = (hh+1)%24;
                mm = 0;
            }
	    } while( !palindromic(hh,mm) );
	    printf("%02d:%02d\n", hh, mm);
	}

    fclose(stdout);
    return 0;
}
