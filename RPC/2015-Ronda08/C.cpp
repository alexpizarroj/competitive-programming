#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct Point {
  Point() {}
  Point(long long a, long long b) : x(a), y(b) { }
  long long x, y;
};

using CPointRef = const Point&;

// Returns the doubled area of the given triangle
long long getTriangleArea(CPointRef a, CPointRef b, CPointRef c) {
  long long x1 = b.x - a.x, y1 = b.y - a.y;
  long long x2 = c.x - a.x, y2 = c.y - a.y;
  return abs(x1 * y2 - y1 * x2);
}

Point getMiddlePoint(CPointRef a, CPointRef b) {
  return Point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

long long getMaxCuttableArea(const vector<Point> &vec) {
  const int n = vec.size();
  long long area = 0;
  for (int i = 0; i < n; ++i) {
    int prev = (i - 1 + n) % n, next = (i + 1) % n;
    Point b = getMiddlePoint(vec[i], vec[prev]);
    Point c = getMiddlePoint(vec[i], vec[next]);
    area += getTriangleArea(vec[i], b, c);
  }
  return area;
}

long long getConvexArea(const vector<Point> &vec) {
  const int n = vec.size();
  long long area = 0;
  for (int i = 2; i < n; ++i) {
    area += getTriangleArea(vec[0], vec[i-1], vec[i]);
  }
  return area;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  double a;
  int n;
  while (cin >> a >> n) {
    vector<Point> vec(n);
    for (int i = 0; i < n; ++i) {
      cin >> vec[i].x >> vec[i].y;
      vec[i].x *= 2, vec[i].y *= 2; // middle point of edges is now integer
    }
    
    long long convexArea = getConvexArea(vec);
    long long maxCuttableArea = getMaxCuttableArea(vec);
    
    double s = (double)maxCuttableArea / ((double)convexArea * (1 - a));
    s = 2 * sqrt(s);
    cout << fixed << setprecision(5) << s << endl;
  }
  
  return 0;
}
