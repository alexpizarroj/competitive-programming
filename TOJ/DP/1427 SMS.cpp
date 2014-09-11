#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

char s[100005];

int main()
{
    int n, m, x, y, ans, len;
    
    while ( ~scanf("%d %d", &n, &m) )
    {
        getchar(), gets(s);
        len = strlen(s);
        ans = x = 0;
        while ( x < len )
        {
            y = 0;
            for(int i = x; i < len && i-x < m; ++i, ++y)
            {
                if ( s[i] != ' ' && !isalpha(s[i]) ) break;
            }
            y = min( max(n, y), len-x );
            ans += 1, x += y;
        }
        printf("%d\n", ans);
    }
	
    return 0;
}
