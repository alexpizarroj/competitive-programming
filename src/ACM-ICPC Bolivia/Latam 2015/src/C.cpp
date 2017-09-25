#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using int64 = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<ii>;

struct Po {
  int64 x, y;
  Po() : x(0), y(0) {}
  Po(int64 _x, int64 _y) : x(_x), y(_y) {}
};

Po operator-(const Po& lhs, const Po& rhs) {
  return Po(lhs.x - rhs.x, lhs.y - rhs.y);
}

int64 cross(const Po& a, const Po& b) {
  return a.x * b.y - a.y * b.x;
}

int64 triangle_darea(const Po& a, const Po& b, const Po& c) {
  return abs(cross(b - a, c - a));
}

pair<int, int64> get_couple(int n, int i, int start_j, int64 area, int64 poly_area, const vector<Po>& p) {
  int j = (start_j + 1) % n;
  int last_j = start_j;
  int64 area_diff = abs(poly_area - 2 * area);
  
  while (true) {
    int64 new_area = area + triangle_darea(p[i], p[last_j], p[j]);
    
    int64 cand = abs(poly_area - 2 * new_area);
    
    if (cand > area_diff) {
      return make_pair(last_j, area);
    }
    
    area_diff = cand;
    area = new_area;
    last_j = j;
    j = (j + 1) % n;
  }
  
  assert(false);
  return make_pair(0, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vector<Po> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i].x >> p[i].y;
    }
    
    int64 poly_area = 0;
    for (int i = 2; i < n; ++i) {
      poly_area += triangle_darea(p[0], p[i - 1], p[i]);
    }
    
    int last = 1;
    int64 carol = 0, last_area = 0;
    
    for (int i = 0; i < n; ++i) {
      auto res = get_couple(n, i, last, last_area, poly_area, p);
      int j = res.first;
      int64 area = res.second;
      
      int64 cand = max(area, poly_area - area);
      carol = max(cand, carol);
      
      if (i + 1 < n) {
        last = j;
        last_area = area - triangle_darea(p[i], p[i + 1], p[j]);
      }
    }
    
    cout << carol << " " << (poly_area - carol) << '\n';
  }
  
  return 0;
}
