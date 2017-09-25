#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

// UNION-FIND START
vector<int> pset, set_size; int disjointSetsSize;
void initSet(int N) {
  pset.assign(N,0); set_size.assign(N,1); disjointSetsSize=N;
  for(int i=0; i<N; i++) pset[i]=i;
}
int findSet(int i)  { return (pset[i]==i) ? i : (pset[i]=findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j)  {
  if( !isSameSet(i,j) )
  { set_size[findSet(j)] += set_size[findSet(i)]; pset[findSet(i)] = findSet(j); disjointSetsSize--; }
}
int numDisjointsSets() { return disjointSetsSize; }
int sizeOfSet(int i)   { return set_size[findSet(i)]; }
// UNION-FIND END

struct Edge
{
  int src, dst, temp, dist;
};

bool byTempByDist(const Edge &e1, const Edge &e2)
{
  if (e1.temp != e2.temp)
    return e1.temp < e2.temp;
  return e1.dist < e2.dist;
}

bool operator<(const Edge &e1, const Edge &e2)
{
  return e1.dist < e2.dist;
}

pair< vector<int>, pair<int, int> > getAnswer(
  const vector< vector<int> > &adj,
  const vector< vector<int> > &adj_temp,
  const vector< vector<int> > &adj_dist,
  const int my_start, const int my_end)
{
  const int inf = 1000000007;
  const int n = adj.size();
  vector<int> parent(n, -1), dist(n, inf);
  vector<int> parent_temp(n), parent_dist(n);

  set< pair<int, int> > q;
  dist[my_start] = 0;
  q.insert(make_pair(dist[my_start], my_start));
  while (!q.empty())
  {
    const int qdist = q.begin()->first;
    const int u = q.begin()->second;
    q.erase(q.begin());

    if (qdist > dist[u])
      continue;
    if (u == my_end)
      break;

    for(int i = 0; i < (int)adj[u].size(); i++)
    {
      int v = adj[u][i];
      int candidate = dist[u] + adj_dist[u][i];
      if (candidate < dist[v])
      {
        dist[v] = candidate;
        parent[v] = u;
        parent_temp[v] = adj_temp[u][i];
        parent_dist[v] = adj_dist[u][i];
        q.insert(make_pair(candidate, v));
      }
    }
  }

  vector<int> ans;
  int total_len = 0, max_temp = 0;
  for(int u = my_end; u != my_start; u = parent[u])
  {
    ans.push_back(u);
    total_len += parent_dist[u];
    max_temp = max(max_temp, parent_temp[u]);
  }
  ans.push_back(my_start);

  return make_pair(ans, make_pair(total_len, max_temp));
}

int main()
{
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF)
  {
    int my_start, my_end;
    scanf("%d %d", &my_start, &my_end);
    my_start -= 1;
    my_end -= 1;

    vector<Edge> edges;
    for(int i = 0; i < m; i++)
    {
      Edge e;
      scanf("%d %d", &e.src, &e.dst);
      e.src -= 1;
      e.dst -= 1;

      int x, y;
      scanf("%d.%d", &x, &y);
      e.temp = x*10 + y;
      scanf("%d.%d", &x, &y);
      e.dist = x*10 + y;

      edges.push_back(e);
    }
    sort(begin(edges), end(edges), byTempByDist);

    // MST
    vector< vector<int> > adj(n, vector<int>());
    vector< vector<int> > adj_temp(n, vector<int>());;
    vector< vector<int> > adj_dist(n, vector<int>());;
    initSet(n);
    for(int i = 0; i < m; i++)
    {
      const Edge &e = edges[i];
      if (!isSameSet(e.src, e.dst))
      {
        unionSet(e.src, e.dst);
        adj[e.src].push_back(e.dst);
        adj_temp[e.src].push_back(e.temp);
        adj_dist[e.src].push_back(e.dist);
        adj[e.dst].push_back(e.src);
        adj_temp[e.dst].push_back(e.temp);
        adj_dist[e.dst].push_back(e.dist);
      }
    }

    // Determine the highest usable temperature
    pair< vector<int>, pair<int, int> > ret;
    ret = getAnswer(adj, adj_temp, adj_dist, my_start, my_end);
    const int max_temp = ret.second.second;
    
    // Get the final graph
    adj.assign(n, vector<int>());
    adj_temp.assign(n, vector<int>());
    adj_dist.assign(n, vector<int>());
    for(int i = 0; i < m; i++)
    {
      const Edge &e = edges[i];
      if (e.temp > max_temp)
        continue;
      adj[e.src].push_back(e.dst);
      adj_temp[e.src].push_back(e.temp);
      adj_dist[e.src].push_back(e.dist);
      adj[e.dst].push_back(e.src);
      adj_temp[e.dst].push_back(e.temp);
      adj_dist[e.dst].push_back(e.dist);
    }

    // Output the answer
    ret = getAnswer(adj, adj_temp, adj_dist, my_start, my_end);
    const vector<int> &ans = ret.first;
    const int total_len = ret.second.first;
    assert(ret.second.second == max_temp);
    for(int i = (int)ans.size() - 1; i >= 0; i--)
      printf(i == 0 ? "%d" : "%d ", ans[i] + 1);
    printf("\n%d.%d %d.%d\n", total_len / 10, total_len % 10,
      max_temp / 10, max_temp % 10);
  }

  return 0;
}
