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
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> Interval; // (Time Interval, Monkey Id)
typedef vector<int> vi;
const int INF = int(1e9);
const int MAX = 350;
// Graph Structure
// 0:                                   source
// 1 -> nMonkeys:                       monkeys
// nMonkeys+1 -> nMonkeys+nIntervals:   time intervals / periods
// nMonkeys+nIntervals+1:               sink
vector<vi> adjlist;
int res[MAX][MAX];
int s, t, n;
// Interval Contraction
set<Interval> group;
int nIntervals, periodCap;
vector<ii> ranges;

int find_path()
{
    vi from(n, -1), visited(n, 0);
    queue<int> q; int u, v, f;

    q.push(s); visited[s] = true;
    while ( !visited[t] && !q.empty() )
    {
        u = q.front(); q.pop();
        fup(i,0,adjlist[u].size())
        {
            v = adjlist[u][i];
            if ( res[u][v] > 0 && !visited[v] )
            {
                from[v] = u;
                q.push(v); visited[v] = true;
                if ( v == t ) break;
            }
        }
    }

    f = INF;
    if ( visited[t] )
    {
        for(u = t; from[u] > -1; u = from[u])
            f = min( res[from[u]][u], f );
        for(u = t; from[u] > -1; u = from[u])
            v = from[u], res[v][u] -= f, res[u][v] += f;
    }

    return ( f == INF ? 0 : f );
}

int maxflow()
{
    int mf = 0, d;
    while ( ( d = find_path() ) ) mf += d;
    return mf;
}

void add_interval(int start, int end)
{
    //if ( group.size() == 0 ) return;
    //printf("Interval [%d..%d] with %d monkey(s)\n", start, end, group.size());
    //cout << "  -Monkeys:"; foreach(it, group) cout << " " << it->second; cout << endl;

    int inter, mon, cap;

    inter = adjlist.size();
    cap = end - start + 1;
    adjlist.PB(vi());
    ranges.PB( ii(start,end) );
    ++nIntervals;

    foreach(it, group)
    {
        mon = it->second;
        adjlist[mon].PB(inter); adjlist[inter].PB(mon);
        res[mon][inter] = cap;
    }

    //cout << "  -"; cout << "Hours span: " << cap << ", cap/hr: " << (periodCap) << endl;
}

void add_task(vector<ii> &tasks, ii timeint)
{
    if ( tasks.size() > 0 && tasks.back().second == timeint.first )
    {
        timeint.first = tasks.back().first;
        tasks.pop_back();
    }
    tasks.PB(timeint);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int nMonkeys, v, a, b, mf, reqflow;
	int caseNo = 1, start, ending;
	vector<Interval> inter;
	vector< vector<ii> > schedule;

	while ( scanf("%d %d", &nMonkeys, &periodCap), nMonkeys > 0 )
	{
	    s = 0;
	    adjlist.assign(nMonkeys+1, vi());
	    memset(res, 0, sizeof res);

        // Source -> Monkeys
        inter.clear(); reqflow = 0;
        fupi(i, 1, nMonkeys)
        {
            scanf("%d %d %d", &v, &a, &b);
            inter.PB( Interval(ii(a,b-1),i) );
            reqflow += v;

            adjlist[s].PB(i); adjlist[i].PB(s);
            res[s][i] = v;
        }

        // Monkeys -> Time Intervals
        start = INF; nIntervals = 0;
        sort(ALL(inter));
        group.clear(); ranges.clear();
        fup(i,0,inter.size())
        {
            int id = inter[i].second;
            const ii &R = inter[i].first;

            while ( !group.empty() && R.first > (group.begin()->first).first )
            {
                ending = group.begin()->first.first;
                if ( start <= ending )
                {
                    add_interval(start, ending);
                    start = ending + 1;
                }

                group.erase(group.begin());
            }

            ending = R.first;
            if ( start < ending ) add_interval(start, ending-1);
            start = ending;

            group.insert( Interval(ii(R.second, R.first),id) );
        }
        while ( !group.empty() )
        {
            ending = group.begin()->first.first;
            if ( start <= ending )
            {
                add_interval(start, ending);
                start = ending + 1;
            }
            group.erase(group.begin());
        }

        // Time Intervals -> Sink
        adjlist.PB(vi());
        t = nMonkeys + nIntervals + 1;
        fup(i,0,nIntervals)
        {
            int timeint = nMonkeys + 1 + i;
            int len = ranges[i].second - ranges[i].first + 1;

            adjlist[timeint].PB(t); adjlist[t].PB(timeint);
            res[timeint][t] = periodCap * len;
        }

        // Maximun Flow
        n = t + 1;
        mf = maxflow();

        printf("Case %d: %s\n", caseNo++, (reqflow == mf ? "Yes" : "No"));
        if ( reqflow == mf )
        {
            schedule.assign(nMonkeys+1, vector<ii>() );
            fup(u, nMonkeys+1, t)
            {
                int id = u - nMonkeys - 1;
                start = ranges[id].first, ending = ranges[id].second;
                int timespan = ending - start + 1, nextaval = 0, used;

                fup(i,0,adjlist[u].size())
                {
                    int v = adjlist[u][i];
                    if ( v == t ) continue;
                    if ( (used = res[u][v]) > 0 )
                    {
                        if ( nextaval+used > timespan ) // we'll need two intervals
                        {
                            used = (nextaval+used)%timespan;

                            ii span1(start+nextaval, ending+1);
                            ii span2(start, start+used);
                            add_task(schedule[v], span2);
                            add_task(schedule[v], span1);

                            nextaval = used;
                        }
                        else // we'll only need one
                        {
                            ii span1(nextaval+start, nextaval+start+used);
                            add_task(schedule[v], span1);

                            nextaval = (nextaval+used)%timespan;
                        }
                    }
                }
            }
            fupi(i, 1, nMonkeys)
            {
                sort(ALL(schedule[i]));
                printf("%d", schedule[i].size());
                fup(j, 0, schedule[i].size())
                {
                    printf(" (%d,%d)", schedule[i][j].first, schedule[i][j].second);
                }
                puts("");
            }
        }
	}

    return 0;
}
