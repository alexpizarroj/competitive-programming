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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

// O(n^2) complexity
int war(const vi &naomi, const vi &ken)
{
    vector<bool> kenUsed(ken.size(), false);
    int ans = 0, kenBest = ken.back(), kenBestPos = ken.size()-1, choice;
    
    fup(i,0,naomi.size())
    {
        if ( naomi[i] < kenBest ) // Ken can win, get the min box who beats us
        {
            choice = 0;
            while ( kenUsed[choice] || ken[choice] < naomi[i] ) ++choice;
        }
        else // Ken can't win, he will use his worse box
        {
            choice = 0;
            while ( kenUsed[choice] ) ++choice;
            ++ans;
        }
        
        // Update the best box for Ken
        kenUsed[choice] = true;
        if ( choice == kenBestPos )
        {
            while ( kenBestPos >= 0 && kenUsed[kenBestPos] ) --kenBestPos;
            kenBest = ken[kenBestPos];
        }
    }
    
    return ans;
}

// O(n) complexity
int dwar(const vi &naomi, const vi &ken)
{
    deque<int> n(ALL(naomi)), k(ALL(ken));
    int ans = 0;
    
    while ( n.size() > 0 )
    {
        // Make Ken use his best boxes
        while ( n.size() > 0 && k.back() > n.back() )
        {
            k.pop_back(), n.pop_front();
        }
        // Use our best box against Ken's best box (we will win ofc)
        if ( n.size() > 0 ) 
        {
            k.pop_back(), n.pop_back();
            ++ans;
        }
    }
    
    return ans;
}

int main()
{
    int tc, n, warScore, dwarScore;
    double value;
    vi naomi, ken;
    
    cin >> tc;
    fupi(caseno, 1, tc)
    {
        cin >> n;
        naomi.resize(n), ken.resize(n);
        fup(i,0,n) cin >> value, naomi[i] = (int)floor(value*1e5);
        fup(i,0,n) cin >> value, ken[i] = (int)floor(value*1e5);
        sort(ALL(naomi)), sort(ALL(ken));
        
        warScore = war(naomi, ken);
        dwarScore = dwar(naomi, ken);
        printf("Case #%d: %d %d\n", caseno, dwarScore, warScore);
        assert(dwarScore >= warScore);
    }
	
    return 0;
}
