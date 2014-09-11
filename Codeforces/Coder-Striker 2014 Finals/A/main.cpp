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

char text[100005];
string validstr = "AHIMOTUVWXY";
bool valid[255];

int main()
{
    bool correct;
    int n;
    
    memset(valid, 0, sizeof valid);
    foreach(it,validstr) valid[(int)*it] = true;
    
    while ( gets(text) != NULL )
    {
        n = strlen(text);
        correct = true;
        
        for(int i = 0; i < n/2; i++)
        {
            if ( text[i] != text[n-i-1] )
            {
                correct = false;
                break;
            }
        }
        if ( correct )
        {
            fup(i,0,n) if ( !valid[(int)text[i]] ) 
            {
                correct = false;
                break;
            }
        }
        
        puts(correct ? "YES" : "NO");
    }
	
    return 0;
}
