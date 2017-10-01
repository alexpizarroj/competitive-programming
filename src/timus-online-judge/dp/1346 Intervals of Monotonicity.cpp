#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, n, last, current, ls, s;
    
    while ( ~scanf("%d %d", &a, &b) )
    {
        n = 1, ls = 0;
        scanf("%d", &last);
        for(int i=a+1; i<=b; ++i)
        {
            scanf("%d", &current);
            if ( current == last ) continue;
            
            s = min(max(last-current,-1),1);
            if ( ls == 0 )      ls = s;
            else if ( s != ls ) ls = 0, ++n;
            last = current;
        }
        printf("%d\n", n);
    }
	
    return 0;
}
