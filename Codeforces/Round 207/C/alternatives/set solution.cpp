#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<set>
#include<iomanip>
#include<complex>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<bitset>
#include<memory.h>
#include<cassert>
#include<ctime>

using namespace std;

#define For(i,l,r) for (int i = l ;i <= r ;i ++ )
#define ForI(it , s , T) for (T :: iterator it = s.begin(); it != s.end() ;it ++ )
#define LL long long
#define READ(Tp,l,r,a) For(i,l,r) scanf(((Tp=="int")?"%d":"%I64d"),&a[i]);
#define iinf 2000000000
#define linf 2000000000000000000LL
#define MOD  1000000007
#define Pi 3.1415926535897932384
#define bit(mask,i) ((mask>>i)&1)
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define pause cin.get()
#define fir first
#define sec second
#define ln(x) log(x)

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

const int Nmax = 100300;

int main()
{
   //ios_base::sync_with_stdio(0);
   int n,m;
   cin >> n >> m;
   vector<int> ans(n+1);
   set<int> s;
   For(i,1,n)
    s.insert(i);
   For(i,1,m)
   {
             int l,r,x;
             cin >> l >> r >> x;
             set<int> ::iterator itl = s.lower_bound(l),itl_m = itl,
                                 itr = s.upper_bound(r);
             for (set<int> :: iterator it = itl ; it != itr; it ++ )
             {
              if (*it != x)
               ans[*it] = x;
             }
             s.erase(itl,itr);
             s.insert(x);
   }
   For(i,1,n)
    cout << ans[i]<<" " ;
   cout << endl;
   return 0;
}

