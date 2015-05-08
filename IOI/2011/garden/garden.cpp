#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int inf = int(1e9) + 7;
vector<int> f;
vector<vector<int> > g;

int cycleSize(int x0) {
  int tortoise = f[x0], hare = f[f[x0]];
  while (tortoise != hare) {
    tortoise = f[tortoise];
    hare = f[f[hare]];
  }

  int mu = 0;
  tortoise = x0;
  while (tortoise != hare) {
    tortoise = f[tortoise];
    hare = f[hare];
    mu += 1;
  }

  int lam = 1;
  hare = f[tortoise];
  while (tortoise != hare) {
    hare = f[hare];
    lam += 1;
  }

  return (mu == 0 ? lam : inf);
}

void getDistVec(const int P, vector<int> &dist, vector<int> &freq,
                vector<vector<int> > &verMod) {
  const int csz = verMod.size();
  const int N = (int)g.size() / 2;
  queue<int> q;
  q.push(P);
  dist.assign(g.size(), inf);
  dist[P] = 0;
  freq.assign(g.size(), 0);
  if (P < N) {
    ++freq[0];
    if (csz) verMod[dist[P] % csz].push_back(dist[P]);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i];
      if (dist[v] == inf) {
        dist[v] = dist[u] + 1;
        if (v < N) {
          ++freq[dist[v]];
          if (csz) verMod[dist[v] % csz].push_back(dist[v]);
        }
        q.push(v);
      }
    }
  }
  for (int i = 0; i < (int)verMod.size(); i++)
    sort(verMod[i].begin(), verMod[i].end());
}

void count_routes(int N, int M, int P, int R[][2], int Q, int G[]) {
  // Fountain's neighbors
  vector<int> fmin1(N, inf), fmin2(N, inf);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < 2; j++) {
      int u = R[i][j], v = R[i][1 - j];
      if (fmin1[u] == inf)
        fmin1[u] = v;
      else if (fmin2[u] == inf)
        fmin2[u] = v;
    }
  for (int u = 0; u < N; u++)
    if (fmin2[u] == inf) fmin2[u] = fmin1[u];
  // f function + g inverse function (graph)
  f.resize(2 * N);
  g.assign(2 * N, vector<int>());
  for (int u = 0; u < 2 * N; u++) {
    int v = (u < N ? fmin1[u] : fmin2[u - N]);
    if (fmin1[v] == u % N) v += N;
    f[u] = v, g[v].push_back(u);
  }
  // Cycle size + Distance vectors + Freq + VerticesMod
  int target[] = {P, P + N};
  int csz[] = {cycleSize(target[0]), cycleSize(target[1])};
  vector<int> dist[2], freq[2];
  vector<vector<int> > verMod[2];
  for (int i = 0; i < 2; i++) {
    if (csz[i] != inf)
      verMod[i].assign(csz[i], vector<int>());
    else
      verMod[i].clear();
    getDistVec(target[i], dist[i], freq[i], verMod[i]);
  }
  // Output
  for (int q = 0, ans = 0; q < Q; q++, ans = 0) {
    for (int i = 0; i < 2; i++)
      if (csz[i] == inf)
        ans += (G[q] < (int)g.size() ? freq[i][G[q]] : 0);
      else {
        const vector<int> &vm = verMod[i][G[q] % csz[i]];
        ans += distance(vm.begin(), upper_bound(vm.begin(), vm.end(), G[q]));
      }
    answer(ans);
  }
}
