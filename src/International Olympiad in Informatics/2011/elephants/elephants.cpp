#include <bits/stdc++.h>
using namespace std;

struct Elephant {
  Elephant(int pos) : x(pos) {}
  Elephant(int pos, int ident) : x(pos), id(ident) {}
  int x, id, be, en;
  int cneeded, ccover;
};

bool operator<(const Elephant& lhs, const Elephant& rhs) {
  return lhs.x < rhs.x;
}

static const int inf = 1000000007;
static vector<int> epos;
static int global_N, global_L, n_buckets, buckets_span, update_cnt;
static vector<vector<Elephant> > buckets;
static vector<pair<int, int> > buckets_int;

static void fill_bucket_data(vector<Elephant>& v) {
  const int N = v.size();
  int next = N;
  for (int cur = N - 1; cur >= 0; cur--) {
    int next_pos = (next == N ? v.back().x : v[next].x);
    int single_camera_cover = v[cur].x + global_L;
    if (single_camera_cover < next_pos) {
      for (next -= 1; single_camera_cover < v[next].x; next -= 1)
        ;
      next += 1;
    }
    v[cur].cneeded = 1 + (next == N ? 0 : v[next].cneeded);
    v[cur].ccover = (next == N ? v[cur].x + global_L : v[next].ccover);
  }
}

static void build_buckets(const vector<pair<int, int> >& X) {
  int covered = 0;
  buckets.assign(n_buckets, vector<Elephant>());
  buckets_int.resize(n_buckets);
  for (int i = 0; i < n_buckets; i++) {
    const int lb = i * buckets_span;
    const int ub = min(lb + buckets_span, global_N);
    for (int j = lb; j < ub; j++) {
      buckets[i].push_back(Elephant(X[j].first, X[j].second));
      epos[X[j].second] = i;
    }

    buckets_int[i].first = covered;
    buckets_int[i].second = covered;
    if (i == n_buckets - 1) {
      buckets_int[i].second = inf;
    } else if (buckets[i].size() > 0) {
      buckets_int[i].second = buckets[i].back().x;
    }
    covered = buckets_int[i].second;

    fill_bucket_data(buckets[i]);
  }
}

static void rebuild_buckets() {
  vector<pair<int, int> > X;
  for (int i = 0; i < n_buckets; i++) {
    for (int j = 0; j < (int)buckets[i].size(); j++) {
      X.push_back(make_pair(buckets[i][j].x, buckets[i][j].id));
    }
  }
  assert((int)X.size() == global_N);
  build_buckets(X);
}

static int get_min_cameras() {
  int ans = 0, covered = -1;
  for (int i = 0; i < (int)buckets.size(); i++) {
    const vector<Elephant>& b = buckets[i];
    vector<Elephant>::const_iterator it =
        upper_bound(b.begin(), b.end(), Elephant(covered));
    if (it == b.end()) {
      continue;
    }

    ans += it->cneeded;
    covered = it->ccover;
  }
  return ans;
}

void init(int N, int L, int X[]) {
  global_N = N;
  global_L = L;
  n_buckets = 1;

  while (n_buckets * n_buckets < N) {
    n_buckets += 1;
  }

  buckets_span = n_buckets;
  update_cnt = 0;
  epos.resize(N);

  vector<pair<int, int> > XX(N);
  for (int i = 0; i < N; i++) {
    XX[i] = make_pair(X[i], i);
  }
  build_buckets(XX);
}

int update(int id, int y) {
  int prev_bucket = epos[id], new_bucket = -1;

  // Locate the corresponding buckets (affected by the change)
  for (int i = 0; i < n_buckets; i++) {
    const int be = buckets_int[i].first, en = buckets_int[i].second;
    if (be <= y && y <= en) new_bucket = i;
  }
  epos[id] = new_bucket;
  assert(new_bucket != -1);

  // Remove the previous elephant
  bool removed = false;
  for (int i = 0; i < (int)buckets[prev_bucket].size(); i++) {
    if (buckets[prev_bucket][i].id == id) {
      buckets[prev_bucket].erase(buckets[prev_bucket].begin() + i);
      removed = true;
      break;
    }
  }
  assert(removed);

  // Insert the new elephant
  vector<Elephant>::iterator insert_it = upper_bound(
      buckets[new_bucket].begin(), buckets[new_bucket].end(), Elephant(y));
  buckets[new_bucket].insert(insert_it, Elephant(y, id));

  // Update the buckets
  fill_bucket_data(buckets[prev_bucket]);
  if (prev_bucket != new_bucket) fill_bucket_data(buckets[new_bucket]);

  // Calculate answer + Optimize structure
  int ans = get_min_cameras();
  update_cnt += 1;
  if (update_cnt == n_buckets) {
    update_cnt = 0;
    rebuild_buckets();
  }

  return ans;
}

/*
** Try it at:
** http://www.codechef.com/problems/ELPHANT
** http://bo.spoj.com/problems/TH_ELEPH/
*/
int main() {
  const int MAX_N = 1000000;
  const int MAX_M = 1000000;

  int i, ans;
  int N, L, M;
  int* X = new int[MAX_N];
  int* ii = new int[MAX_M];
  int* yy = new int[MAX_M];

  scanf("%d %d %d", &N, &L, &M);
  for (i = 0; i < N; i++) scanf("%d", &X[i]);
  for (i = 0; i < M; i++) scanf("%d %d", &ii[i], &yy[i]);

  init(N, L, X);
  for (i = 0; i < M; i++) {
    ans = update(ii[i], yy[i]);
    printf("%d\n", ans);
  }

  delete[] X;
  delete[] ii;
  delete[] yy;
  return 0;
}
