#include <iostream>
#include <cstdio>
#define PB 				        push_back
#define MP 				        make_pair
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > int(b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= int(b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dset(a,v) 		        memset(a, v, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
using namespace std;

const int px = '+'*'x', nx = '-'*'x';
const int py = '+'*'y', ny = '-'*'y';
const int pz = '+'*'z', nz = '-'*'z';

int step(int cur, int opt)
{
    int ret = cur;

    if ( cur == nx )
    {
        if ( opt == ny ) ret = py;
        else if ( opt == py ) ret = ny;
        else if ( opt == nz ) ret = pz;
        else if ( opt == pz ) ret = nz;
    }
    else if ( cur == px )
    {
        ret = opt;
    }
    else if ( cur == ny )
    {
        if ( opt == ny ) ret = nx;
        else if ( opt == py ) ret = px;
        else if ( opt == nz ) ret = ny;
        else if ( opt == pz ) ret = ny;
    }
    else if ( cur == py )
    {
        if ( opt == ny ) ret = px;
        else if ( opt == py ) ret = nx;
        else if ( opt == nz ) ret = py;
        else if ( opt == pz ) ret = py;
    }
    else if ( cur == nz )
    {
        if ( opt == ny ) ret = nz;
        else if ( opt == py ) ret = nz;
        else if ( opt == nz ) ret = nx;
        else if ( opt == pz ) ret = px;
    }
    else if ( cur == pz )
    {
        if ( opt == ny ) ret = pz;
        else if ( opt == py ) ret = pz;
        else if ( opt == nz ) ret = px;
        else if ( opt == pz ) ret = nx;
    }

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int l, cur, opt;
	char bf[3];

	while ( scanf("%d", &l), l != 0 )
	{
	    cur = px;
	    fup(i,1,l)
	    {
            scanf("%s", bf);
            if( bf[0] != 'N' )
            {
                opt = bf[0]*bf[1];
                cur = step(cur, opt);
            }
	    }
	    if( cur == px )         puts("+x");
	    else if ( cur == nx )   puts("-x");
	    else if ( cur == py )   puts("+y");
	    else if ( cur == ny )   puts("-y");
	    else if ( cur == pz )   puts("+z");
	    else if ( cur == nz )   puts("-z");
	}

    return 0;
}
