#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int tc;
    char prog[10005];
    scanf("%d", &tc);
    while ( tc-- )
    {
        scanf("%s", prog);
        int ans, cul, cur, tam;
        ans = cul = cur = 0;
        tam = strlen(prog);
        for(int i = 0; i < tam; i++)
        {
            if ( prog[i] == 'L' )
                --cul, --cur;
            else if ( prog[i] == 'R' )
                ++cul, ++cur;
            else
                --cul, ++cur;
            ans = max(ans, max(abs(cul), abs(cur)));
        }
        printf("%d\n", ans);
    }
    return 0;
}

