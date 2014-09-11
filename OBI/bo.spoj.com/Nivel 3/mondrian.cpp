#include <cstdio>
#include <cstring>
int mat[100][100];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, b, h, r, br, hr, cnt, caseNo = 0;

    scanf("%d", &n);
    while ( n-- )
    {
        scanf("%d %d %d", &b, &h, &r);
        memset(mat, 0, sizeof mat); cnt = 1;
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < b; j++)
            {
                if( mat[i][j] == 0 )
                {
                    scanf("%d %d", &br, &hr);
                    for(int k = i; k < i+hr; k++)
                    {
                        for(int m = j; m < j+br; m++)
                        {
                            mat[k][m] = cnt;
                        }
                    }
                    cnt++;
                }
            }
        }
        if( ++caseNo > 1 ) puts("");
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < b; j++)
            {
                if ( j > 0 ) printf(" ");
                printf("%d", mat[i][j]);
            }
            puts("");
        }
    }

    return 0;
}
