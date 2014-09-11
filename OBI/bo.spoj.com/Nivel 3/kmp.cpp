#include <cstdio>
#include <cstring>

char pattern[205];
int F[205], len;

void build_failure_func()
{
    F[0] = F[1] = 0;
    for(int i = 2; i <= len; i++)
    {
        int j = F[i-1];
        while ( true )
        {
            if( pattern[j] == pattern[i-1] )
            {
                F[i] = j + 1; break;
            }
            if( j == 0 )
            {
                F[i] = 0; break;
            }
            j = F[j];
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int nc, caseNo = 1;
    scanf("%d", &nc); getchar();
	while ( nc-- )
    {
        gets(pattern);
        len = strlen(pattern);
        build_failure_func();
        printf("Caso %d:\n", caseNo++);
        for(int i = 2; i <= len; i++)
            if( F[i] > 0 ) printf("%d: %d\n", i, F[i]);
    }

    return 0;
}

