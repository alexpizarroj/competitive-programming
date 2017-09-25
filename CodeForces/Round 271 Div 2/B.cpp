#include <ctime>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>

#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define forn(i, n)      for(int i = 0; i < int(n); ++i)
#define fore(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define foreach(it, a)  for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)

using namespace std;

const int inf = int(1e9+7);
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

int main()
{
	int n;
    cin >> n;
    vector<int> vec;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        sum += value;
        vec.push_back(sum);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int pos;
        scanf("%d", &pos);
        int bin = distance(vec.begin(), lower_bound(all(vec), pos)) + 1;
        printf("%d\n", bin);
    }
    return 0;
}