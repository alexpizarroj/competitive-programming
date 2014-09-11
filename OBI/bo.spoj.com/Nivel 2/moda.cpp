#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
    Data() { }
    Data(int v, int f) : value(v), freq(v) { }
    int value, freq;
};
bool operator <(const Data& a, const Data& b)
{
    if( a.freq != b.freq ) return (a.freq > b.freq);
    return (a.value < b.value);
}
bool operator ==(const Data& a, const Data& b)
{
    return ( a.value == b.value ) && (a.freq == b.freq);
}

vector<Data> ft;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, x, mx;
    while ( scanf("%d", &n), n > 0 )
    {
        ft.assign(10001, Data(0,0));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            ft[x].value = x, ft[x].freq++;
        }
		
        sort(ft.begin(), ft.end());
        mx = distance(ft.begin(), unique(ft.begin(), ft.end())) - 1;
        if( ft[0].freq != ft[mx-1].freq )
			for(x = 0; ft[x].freq == ft[0].freq; x++)
                printf("%d\n", ft[x].value);
        else
            puts("-1");
    }

    return 0;
}
