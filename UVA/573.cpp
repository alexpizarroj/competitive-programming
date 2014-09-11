#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int h, u, d, f, day;
	double climbs, factor, height;

	while ( scanf("%d", &h), h != 0 )
	{
	    scanf("%d %d %d", &u, &d, &f);
	    climbs = u;
	    factor = double(u) * (f/100.0);
	    height = 0, day = 1;
	    while ( true )
	    {
	        height += climbs, climbs = max(0.0, climbs-factor);
	        if( height > h ) break;
	        height -= d;
	        if ( height < 0 ) break;
	        day++;
	    }
        printf( ( height > h ? "success on day %d\n" : "failure on day %d\n"), day );
	}

    return 0;
}
