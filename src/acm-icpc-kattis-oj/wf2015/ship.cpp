/*
** @author Alex Erick Pizarro Jimenez
*/
#include <bits/stdc++.h>
using namespace std;

using Interval = pair<double, double>;

double get_crossing_time(string dir, int po, int u) {
  double result = 0.0;
  if (dir == "E") {
    if (po < 0) {
      result = double(-po) / u;
    }
  } else {
    if (po > 0) {
      result = double(po) / u;
    }
  }
  return result;
}

void intervalify(vector<Interval> &vec) {
  if (vec.size() == 0) {
    return;
  }

  vector<Interval> result;
  sort(begin(vec), end(vec));

  Interval cur = vec[0];
  for (int i = 1; i < (int)vec.size(); i++) {
    const Interval &next = vec[i];
    if (cur.second + 0.1 >= next.first) {
      cur.second = max(cur.second, next.second);
    } else {
      result.push_back(cur);
      cur = next;
    }
  }
  result.push_back(cur);

  vec = result;
}

double solve(const vector<Interval> &vec, int t1, int t2, double ct) {
  assert(vec.size() > 0);

  const double max_time = 1e9;

  vector<Interval> cand;
  if (0 < vec.front().first) {
    cand.emplace_back(0, vec.front().first);
  }
  for (int i = 1; i < (int)vec.size(); i++) {
    cand.emplace_back(vec[i - 1].second, vec[i].first);
  }
  cand.emplace_back(vec.back().second, max_time);

  double result = 0.0;

  for (Interval inter : cand) {
    inter.second -= ct;
    if (inter.first > inter.second) {
      continue;
    }

    inter.first = max(inter.first, (double)t1);
    inter.second = min(inter.second, (double)t2);
    if (inter.first > inter.second) {
      continue;
    }

    double len = inter.second - inter.first;
    result = max(result, len);
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, w, u, v, t1, t2;
  cin >> n >> w >> u >> v >> t1 >> t2;

  vector<Interval> vec;
  for (int i = 0; i < n; i++) {
    const double offset = i * (double(w) / v);

    string dir;
    cin >> dir;

    int mi;
    cin >> mi;
    for (int j = 0; j < mi; j++) {
      int len, po;
      cin >> len >> po;

      double bb, ee;
      bb = get_crossing_time(dir, po, u);
      ee = get_crossing_time(dir, po + (dir == "E" ? -1 : 1) * len, u);
      if (bb > ee) {
        swap(bb, ee);
      }

      vec.push_back(Interval(bb - offset, ee - offset));
    }
  }

  const double lane_crossing_time = double(w) / v;
  intervalify(vec);

  double ans = solve(vec, t1, t2, lane_crossing_time);
  cout << fixed << setprecision(8) << ans << endl;

  return 0;
}
