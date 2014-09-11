#include <cstdio>
#include <iostream>
#include <cstring>
#define fup(i,s,e) for(int i = (s); i < int(e); i++)
using namespace std;

const int cstNMax = 100;
const int cstMin = -1280000;
int t[cstNMax+5][cstNMax+5];
int n, v[cstNMax+5];

int getMaxSum(const int v[])
{
    int sum = 0, ans = cstMin;
    fup(i, 0, n)
    {
        sum += v[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

    int ans;

    while ( scanf("%d", &n) != EOF )
    {
        fup(i, 0, n) fup(j, 0, n) scanf("%d", &t[i][j]);

        ans = cstMin;
        fup(i, 0, n)
        {
            memset(v, 0, sizeof v);
            fup(j, i, n)
            {
                fup(k, 0, n) v[k] += t[j][k];
                ans = max(ans, getMaxSum(v));
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
