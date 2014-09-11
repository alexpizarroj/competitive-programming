#include <cstdio>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
char mat[1405][1405], cls[2] = {'S', 's'};
int n, best[2];

void process(int r, int c, int dr, int dc)
{
    int len[2] = {0};
    while ( 0 <= r && r < n && 0 <= c && c < n )
    {
        fup(i,0,2)
        {
            if ( mat[r][c] == cls[i] ) ++len[i]; else len[i] = 0;
            if ( len[i] > best[i] ) best[i] = len[i];
        }
        r += dr, c += dc;
    }
}

int main()
{
    while ( ~scanf("%d", &n) )
    {
        getchar();
        fup(i,0,n) gets(mat[i]);
        
        best[0] = best[1] = 0;
        // Ver & hor
        fup(i,0,n) process(i, 0, 0, 1), process(0, i, 1, 0);
        // Main diag
        fup(i,0,n) process(i, 0, 1, 1);
        fup(i,1,n) process(0, i, 1, 1);
        // Second diag
        fup(i,0,n) process(0, i, 1, -1);
        fup(i,1,n) process(i, n-1, 1, -1);
        
        if ( best[0] != best[1] )
        {
            printf("%c\n", cls[best[0] > best[1] ? 0 : 1]);
        }
        else
        {
            puts("?");
        }
        printf("%d\n", best[0] > best[1] ? best[0] : best[1]);
    }
	
    return 0;
}
