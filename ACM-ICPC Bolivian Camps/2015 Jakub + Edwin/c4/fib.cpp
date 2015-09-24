#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
vector<i64> fib;

void precalc_fib() {
  const i64 limit = 400000000000000000LL;
  i64 a = 1, b = 1, c;
  fib.push_back(1);
  while ((c = a + b) <= limit) {
    fib.push_back(c);
    a = b;
    b = c;
  }
  fib.push_back(a + b);
}

int bfs(i64 t) {
  i64 limit = *lower_bound(fib.begin(), fib.end(), t);
  
  map<i64, int> dist, from;
  dist[0] = 0, from[0] = 0;
  dist[t] = 0, from[t] = t;
  
  queue<i64> q;
  q.push(0), q.push(t);
  while (!q.empty()) {
    i64 u = q.front();
    q.pop();
    
    for (int i = 0; i < (int)fib.size(); i++) {
      i64 a[2] = {u + fib[i], u - fib[i]};
      for (int i = 0; i < 2; i++) {
        if (1 <= a[i] && a[i] <= limit) {
          if (dist.count(a[i]) == 0) {
            dist[a[i]] = dist[u] + 1;
            from[a[i]] = from[u];
            q.push(a[i]);
          } else if (from[a[i]] != from[u]) {
            return dist[a[i]] + dist[u] + 1;
          }
        }
      }
    }
  }
  
  return -1; // should not happen
}

vector<i64> greedy(i64 x) {
  deque<i64> preview;
  i64 y = 0;
  while (y != x) {
    i64 d = abs(y - x);
    i64 f = *lower_bound(fib.begin(), fib.end(), d);
    if (y > x) { f *= -1; }
    
    y += f;
    preview.push_back(f);
  }
  
  vector<i64> result;
  while (!preview.empty()) {
    i64 next = preview.front();
    preview.pop_front();
    
    if (result.size() == 0) {
      result.push_back(next);
    } else {
      i64 cand = next + result.back();
      if (binary_search(fib.begin(), fib.end(), abs(cand))) {
        result.pop_back();
        result.push_back(cand);
      } else {
        result.push_back(next);
      }
    }
  }
  
  return result;
}

void test() {
  for (int i = 10000; i <= 20000; i++) {
    int a = bfs(i);
    vector<i64> ret = greedy(i);
    int b = ret.size();
    if (a != b) {
      cout << "Mismatch for value " << i << endl;
      cout << "BFS said " << a << ", but Greedy said " << b << endl;
      cout << "Greedy proposal:\n";
      for (int i = 0; i < b; i++) {
        cout << ret[i] << " ";
      }
      cout << '\n';
      break;
    }
  }
  
  cout << "All work done\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  precalc_fib();
  
  int q;
  cin >> q;
    
  for (int caso = 1; caso <= q; caso++) {
    i64 x;
    cin >> x;
    int ret = greedy(x).size();
    cout << ret << endl;
  }
  
  return 0;
}