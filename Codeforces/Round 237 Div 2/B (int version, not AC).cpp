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
typedef long long ll;

bool getint(ll &out)
{
    string data;
    
    cin >> data;
    if ( cin )
    {
        if ( data.find('.') != string::npos )
        {
            int intpart, decpart;
            
            sscanf(data.c_str(), "%d.%d", &intpart, &decpart);
            if ( decpart > 0 )
            {
                while ( decpart <= 9999 ) decpart *= 10;
                decpart /= 10;
            }
            out = intpart * 10000 + decpart;
        }
        else
        {
            int intpart;
            
            sscanf(data.c_str(), "%d", &intpart);
            out = intpart * 10000;
        }
        
        return true;
    }
    return false;
}

int main()
{
    ll a, d, len, mov, x, y;
    int n;
    
    while ( getint(a) && getint(d) )
    {
        cin >> n;
        len = 4*a;
        mov = 0;
        while ( n-- )
        {
            mov = (mov + d) % len;
            if ( mov <= a )
            {
                x = mov;
                y = 0;
            }
            else if ( mov <= 2*a )
            {
                x = a;
                y = mov-a;
            }
            else if ( mov <= 3*a )
            {
                x = a - (mov-2*a);
                y = a;
            }
            else if ( mov <= 4*a )
            {
                x = 0;
                y = a - (mov-3*a);
            }
            printf("%d.%04d %d.%04d\n",
                int(x/10000), int(x%10000), int(y/10000), int(y%10000));
        }
    }
	
    return 0;
}
