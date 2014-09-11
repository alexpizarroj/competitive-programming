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
const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

struct Player { int id, time; };

struct cmpLoTimeLoId
{
    bool operator()(const Player &a, const Player &b)
    {
        if( a.time != b.time ) return a.time < b.time;
        return a.id < b.id;
    }
};

class Team
{
private:
    vector<Player> players;
    set<Player, cmpLoTimeLoId> backup;
    size_t playingFieldCap;
public:
    void init(size_t fieldCap)
    {
        players.clear();
        backup.clear();
        playingFieldCap = fieldCap;
    }

    void addPlayer(int id)
    {
        Player p = {id, 0};
        if ( players.size() < playingFieldCap ) players.PB(p);
        else                                    backup.insert(p);
    }

    void getPlayingTeam(vi &out)
    {
        fup(i,0,players.size()) out.PB( players[i].id );
    }

    void rotateTeam()
    {
        if ( backup.size() == 0 ) return;

        // Increase playing time
        fup(i,0,players.size()) players[i].time += 1;

        // Entering/leaving player
        Player entering = (*backup.begin());
        Player leaving = players.back();

        // Update
        backup.erase(backup.begin());
        backup.insert(leaving);
        players.back() = entering;
        sort(players.begin(), players.end(), cmpLoTimeLoId());
    }
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    typedef pair<ii, string> UnsortedPlayer; // ii = { short-perc., height }

    vector<UnsortedPlayer> lst;
    int t, n, m, p, s, h, caseNo = 1;
    vector<string> out;
    Team one, two;
    char name[30];
    vi vec;

    scanf("%d", &t);
    while ( t-- )
    {
        lst.clear();
        scanf("%d %d %d", &n, &m, &p);
        fup(i,0,n)
        {
            scanf("%s %d %d", name, &s, &h);
            lst.PB( UnsortedPlayer(ii(s,h), name) );
        }
        sort(ALL(lst), greater<UnsortedPlayer>());

        // Game Simulation
        one.init(p), two.init(p);
        fup(i,0,n) (i&1 ? two : one).addPlayer(i);
        fup(i,0,m) one.rotateTeam(), two.rotateTeam();

        // Results Processing
        vec.clear();
        one.getPlayingTeam(vec), two.getPlayingTeam(vec);
        out.clear();
        fup(i,0,vec.size()) out.PB( lst[vec[i]].second );
        sort(ALL(out));

        // Output
        printf("Case #%d:", caseNo++);
        foreach(it, out) printf(" %s", it->c_str());
        puts("");
    }

    return 0;
}
