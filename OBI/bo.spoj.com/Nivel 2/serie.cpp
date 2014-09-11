#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, d;
    vector<int> vec;

    while ( scanf("%d %d", &n, &d) != EOF )
    {
        vec.resize(d), n--;
        for(int i = 0; i < d; i++) scanf("%d", &vec[i]);
        printf("%d\n", vec[n%d] + n/d );
    }

    return 0;
}
