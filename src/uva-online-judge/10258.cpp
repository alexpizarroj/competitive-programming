// IO
#include <iostream>
#include <cstdio>
// STL
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
// STRINGS
#include <string>
#include <cstring>
// OTROS
#include <cstdlib>
#include <memory.h>
#include <cmath>
// MACROS
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()

struct Contestant
{
    Contestant(int _teamNumber)
    {
        memset(tries,0,sizeof tries);
        penalty = 0;
        teamNumber = _teamNumber;
    }
    set<int> solvedProblems;
    int tries[11];
    int penalty;
    int teamNumber;
};
bool operator <(Contestant a, Contestant b)
{
    bool lesser = true;
    if( b.solvedProblems.size() > a.solvedProblems.size() )
        lesser = false;
    else if( b.solvedProblems.size() == a.solvedProblems.size() )
    {
        if( b.penalty < a.penalty )
            lesser = false;
        else if( b.penalty == a.penalty )
        {
            if( b.teamNumber < a.teamNumber )
                lesser = false;
        }
    }
    return lesser;
}

int main() {
    //freopen("data.in", "r", stdin);

    int T, contestant, problem, time;
    map<int,Contestant> contest;
    map<int,Contestant>::iterator itContest;
    set<Contestant> results;
    set<Contestant>::iterator itResults;
    char verdict, buffer[101];
    bool firstCase = true;

    scanf("%d", &T);
    getchar(); getchar();
    while ( T-- )
    {
        contest.clear();
        while ( true )
        {
            if( gets(buffer) == NULL || strlen(buffer) == 0 ) break;
            sscanf(buffer ,"%d %d %d %c", &contestant, &problem, &time, &verdict);

            if( contest.count(contestant) == 0  )
                contest.insert( make_pair(contestant, Contestant(contestant) ) );

            Contestant &ct = contest.find(contestant)->second;
            if( verdict == 'C' && ct.solvedProblems.count(problem) == 0 )
            {
                ct.solvedProblems.insert(problem);
                ct.penalty += time + ( ct.tries[problem]*20 );

            } else if ( verdict == 'I' )
            {
                ct.tries[problem]++;
            }
        }

        if( !firstCase ) puts("");
        results.clear();
        for(itContest = contest.begin(); itContest != contest.end(); itContest++)
            results.insert( itContest->second );
        for(itResults = results.begin(); itResults != results.end(); itResults++)
            printf("%d %d %d\n", itResults->teamNumber,
                   itResults->solvedProblems.size(), itResults->penalty );

        firstCase = false;
    }

    return 0;
}
