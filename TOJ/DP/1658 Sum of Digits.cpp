#include <cstdio>
#include <cstring>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)

int parent[905][8105];
char curChoice[905][8105], ansLen[905][8105];
inline int gets1(int x) { return x%1000; }
inline int gets2(int x) { return x/1000; }
inline int mkparent(int s1, int s2) { return s2*1000 + s1; }

void precalc()
{
    memset(parent, -1, sizeof parent);
    parent[0][0] = mkparent(0,0);
    ansLen[0][0] = curChoice[0][0] = 0;
    
    fupi(s1, 1, 900) fupi(s2, 1, 8100) fupi(x, 1, 9)
    {
        if ( s1 < x || s2 < x*x ) continue;
        
        int p = parent[s1][s2], ps1 = s1-x, ps2 = s2-x*x;
        if ( parent[ps1][ps2] != -1 && ansLen[ps1][ps2] < 100 &&
            (p == -1 || ansLen[ps1][ps2] < ansLen[gets1(p)][gets2(p)]) )
        {
            parent[s1][s2] = mkparent(ps1,ps2);
            ansLen[s1][s2] = (char)((int)ansLen[ps1][ps2] + 1);
            curChoice[s1][s2] = x + '0';
        }
    }
}

int main()
{
    int tc, s1, s2;
    char ans[105];
    
    precalc();
    scanf("%d", &tc);
    while ( tc-- )
    {
        scanf("%d %d", &s1, &s2);
        if ( s1 <= 900 && s2 <= 8100 && parent[s1][s2] != -1 )
        {
            int n = 0, p;
            while ( mkparent(s1,s2) != 0 )
            {
                ans[n++] = curChoice[s1][s2];
                p = parent[s1][s2];
                s1 = gets1(p), s2 = gets2(p);
            }
            ans[n] = 0;
            printf("%s\n", ans);
        }
        else puts("No solution");
    }
	
    return 0;
}
