#include "elephants.h"
#include <bits/stdc++.h>
using namespace std;

struct Elephant
{
  Elephant(int pos) : x(pos) { }
  int id, x, cneeded, ccover;
  int be, en;
};

bool operator<(const Elephant &lhs, const Elephant &rhs)
{
  return lhs.x < rhs.x;
}

const int inf = 1000000007;
static vector<int> epos;
static int global_N, global_L, n_buckets, buckets_span, update_cnt;
static vector<vector<Elephant> > buckets;
static vector<pair<int,int> > buckets_int;

void FillBucketData(vector<Elephant> &v)
{
  const int N = v.size();
  int next = N;
  for(int cur = N - 1; cur >= 0; cur--)
  {
    int next_pos = (next == N ? v.back().x : v[next].x);
    int single_camera_cover = v[cur].x + global_L;
    if (single_camera_cover < next_pos)
    {
      for(next -= 1; single_camera_cover < v[next].x; next -= 1);
      next += 1;
    }
    v[cur].cneeded = 1 + (next == N ? 0 : v[next].cneeded);
    v[cur].ccover = (next == N ? v[cur].x + global_L : v[next].ccover);
  }
}

void BuildBuckets(const vector<pair<int, int> > &X)
{
  int covered = 0;
  buckets.assign(n_buckets, vector<Elephant>());
  buckets_int.resize(n_buckets);
  for(int i = 0; i < n_buckets; i++)
  {
    const int lb = i * buckets_span, ub = min(lb + buckets_span, global_N);
    for(int j = lb; j < ub; j++)
    {
      buckets[i].push_back(Elephant(X[j].first));
      buckets[i].back().id = X[j].second;
      epos[X[j].second] = i;
    }

    buckets_int[i].first = buckets_int[i].second = covered;
    if (i == n_buckets-1)
      buckets_int[i].second = inf;
    else if (buckets[i].size() > 0)
      buckets_int[i].second = buckets[i].back().x;
    covered = buckets_int[i].second;

    FillBucketData(buckets[i]);
  }
}

void RebuildBuckets()
{
  vector<pair<int, int> > X;
  for(int i = 0; i < n_buckets; i++)
    for(int j = 0; j < (int)buckets[i].size(); j++)
      X.push_back(make_pair(buckets[i][j].x, buckets[i][j].id));
  assert((int)X.size() == global_N);
  BuildBuckets(X);
}

int GetMinCameras()
{
  int ans = 0, covered = -1;
  for(int i = 0; i < (int)buckets.size(); i++)
  {
    const vector<Elephant> &b = buckets[i];
    auto it = upper_bound(begin(b), end(b), Elephant(covered));
    if (it == b.end())
      continue;
    ans += it->cneeded;
    covered = it->ccover;
    //cout << "Taken elephant = " << it->id <<
    //  ", covers up to " << covered << " using " << it->cneeded << 
    //  " cameras" << endl;
  }
  return ans;
}

void init(int N, int L, int X[])
{
  global_N = N, global_L = L;
  n_buckets = 1;
  while (n_buckets * n_buckets < N)
    n_buckets += 1;
  buckets_span = n_buckets;
  update_cnt = 0;
  epos.resize(N);

  vector<pair<int, int> > XX(N);
  for(int i = 0; i < N; i++)
    XX[i] = {X[i], i};
  BuildBuckets(XX);
}

int update(int id, int y)
{
  int prev_bucket = epos[id], new_bucket = -1;
  // Locate the corresponding buckets (affected by the change)
  for(int i = 0; i < n_buckets; i++)
  {
    const int be = buckets_int[i].first, en = buckets_int[i].second;
    if (be <= y && y <= en)
      new_bucket = i;
  }
  epos[id] = new_bucket;
  assert(new_bucket != -1);
  // Remove the previous elephant
  bool removed = false;
  for(int i = 0; i < (int)buckets[prev_bucket].size(); i++)
  {
    if (buckets[prev_bucket][i].id == id)
    {
      buckets[prev_bucket].erase(buckets[prev_bucket].begin() + i);
      removed = true;
      break;
    }
  }
  assert(removed);
  // Insert the new elephant
  auto insert_it = upper_bound(begin(buckets[new_bucket]),
    end(buckets[new_bucket]), Elephant(y));
  Elephant e(y);
  e.id = id;
  buckets[new_bucket].insert(insert_it, e);
  // Update the buckets
  FillBucketData(buckets[prev_bucket]);
  if (prev_bucket != new_bucket)
    FillBucketData(buckets[new_bucket]);
  // Calculate answer + Optimize structure
  int ans = GetMinCameras();
  update_cnt += 1;
  if (update_cnt == n_buckets)
  {
    update_cnt = 0;
    RebuildBuckets();
  }

  return ans;
}
