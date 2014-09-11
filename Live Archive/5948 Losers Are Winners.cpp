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
#define fup(i,a,b) for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); i++)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef long long sint64;
typedef unsigned long long uint64;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef pair<int,int> ii; typedef vector<int> vi;

struct Team
{
    Team() : initw(0.0), endw(0.0) { }
    string name;
    double initw, endw, lostPerc;
};

bool operator<(const Team& a, const Team& b)
{
    if ( fabs(a.lostPerc - b.lostPerc) < EPS ) return (a.name < b.name);
    return ( a.lostPerc > b.lostPerc );
}

char buf[200];
void run(const int n)
{
    map<string, int> idByName;
    vector<Team> teams;
    int id;
    double initw, endw;
    string name;

    // Input
    teams.reserve(n);
    fup(i, 0, n<<1)
    {
        scanf("%*s %s %lf %lf", buf, &initw, &endw);
        name = string(buf);
        if ( idByName.count(name) == 0 )
        {
            id = (int)teams.size();

            // Team setup
            teams.push_back( Team() );
            idByName[name] = id;
            teams[id].name = name;
        }
        else
        {
            id = idByName[name];
        }

        teams[id].initw += initw;
        teams[id].endw  += endw;
    }

    // Lost Weight Calc and Sorting
    foreach(it, teams)
        it->lostPerc = ( (it->initw - it->endw)*100.0 ) / (it->initw);
    sort( teams.begin(), teams.end() );

    // Output
    printf("%s %.1lf%%\n", teams[0].name.c_str(), teams[0].lostPerc );
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;

	while ( scanf("%d", &n), n > 0 )
        run(n);

    return 0;
}
