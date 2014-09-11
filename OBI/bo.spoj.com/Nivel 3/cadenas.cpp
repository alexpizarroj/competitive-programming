#include <cstdio>
#include <cstring>
int sl, tl;
char s[1005], t[1005];

bool valid(int lend)
{
    int rstart = lend + sl;
    for(int i = 0; i < lend; i++)
        if ( s[i] != t[i] ) return false;
    for(int i = lend; i < rstart; i++)
        if ( s[i-lend] != t[i] ) return false;
    for(int i = rstart; i < tl; i++)
        if ( s[i-sl] != t[i] ) return false;
    return true;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while ( tc-- )
    {
        bool ans = false;
        scanf("%s %s", s, t);
        sl = strlen(s), tl = strlen(t);
        if ( 2*sl == tl )
            for(int i = 0; i <= sl; i++)
                if ( valid(i) )
                {
                    ans = true;
                    break;
                }
        puts(ans ? "Yes" : "No");
    }
    return 0;
}

