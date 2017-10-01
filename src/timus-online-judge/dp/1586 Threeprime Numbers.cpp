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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

typedef vector<int> vi;
vi primes;
vector<vi> smult;
int dp[10005][105] = {0};
const int INF = int(1e9+9), SUMIDX = 101;

void sieve()
{
    bool prime[1000];
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i < 1000; i++)
    {
        if ( !prime[i] ) continue;
        for(int j = i*i; j < 1000; j += i)  prime[j] = false;
    }
    primes.clear();
    fup(i,100,1000) if ( prime[i] ) primes.PB(i);
}

int main()
{
    sieve();
    smult.assign(105, vi());
    fup(i,0,primes.size()) 
    {
        int pref = primes[i] / 10, suff = primes[i] % 100;
        smult[pref].PB(primes[i] % 10);
        ++dp[3][suff], ++dp[3][SUMIDX];
    }
    
    int n;
    cin >> n;
    fupi(i,4,n)
    {
        fupi(j,1,9) for(int k = 1; k <= 9; k += 2) if ( k != 5 )
        {
            int suff = j*10 + k;
            dp[i][SUMIDX] = (dp[i][SUMIDX] + 
                (((long long)dp[i-1][suff] * smult[suff].size())%INF))%INF;
            foreach(it,smult[suff]) 
            {
                int pref = k*10 + (*it);
                dp[i][pref] = (dp[i][pref] + dp[i-1][suff])%INF;
            }
        }
    }
    cout << dp[n][SUMIDX] << endl;
	
    return 0;
}
