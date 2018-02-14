#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

struct Point {
 public:
  Point() : _x(0), _y(0) {}

  Point(int x, int y) : _x(x), _y(y) {}

  bool operator==(const Point& rhs) const {
    return x() == rhs.x() && y() == rhs.y();
  }

  bool operator!=(const Point& rhs) const { return !this->operator==(rhs); }

  bool operator<(const Point& rhs) const {
    if (x() != rhs.x()) return x() < rhs.x();
    return y() < rhs.y();
  }

  int x() const { return _x; }

  int y() const { return _y; }

  int cuadrant() const { return int(x() >= 0) * 2 + int(y() >= 0); }

  long long sqr_dst_to(const Point& rhs) const {
    long long xx = rhs.x() - x();
    long long yy = rhs.y() - y();
    return xx * xx + yy * yy;
  }

 private:
  int _x, _y;
};

struct Lizard {
  Point location;
  int height;
  // sort data
  int cuadrant;
  Point slope_to_tv;
  long long sqr_dist_to_tv;

  bool is_grouped_with(const Lizard& rhs) const {
    return cuadrant == rhs.cuadrant && slope_to_tv == rhs.slope_to_tv;
  }
};

bool operator<(const Lizard& lhs, const Lizard& rhs) {
  if (lhs.cuadrant != rhs.cuadrant) {
    return lhs.cuadrant < rhs.cuadrant;
  }

  if (lhs.slope_to_tv != rhs.slope_to_tv) {
    return lhs.slope_to_tv < rhs.slope_to_tv;
  }

  return lhs.sqr_dist_to_tv < rhs.sqr_dist_to_tv;
}

int lis_length(const vector<int>& sequence) {
  vector<int> tmp;

  for (int x : sequence) {
    vector<int>::iterator it = lower_bound(tmp.begin(), tmp.end(), x);
    if (it == tmp.end())
      tmp.push_back(x);
    else
      *it = x;
  }
  
  return (int)tmp.size();
}

int gcd(int a, int b) {
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return a;
}

Point make_slope(Point p1, Point p2) {
  int yy = p2.y() - p1.y();
  int xx = p2.x() - p1.x();

  int g = gcd(yy, xx);
  yy /= g;
  xx /= g;

  return Point(xx, yy);
}

int solve(const Point& tv, const vector<Lizard>& lizards) {
  const int n = (int)lizards.size();

  int result = 0;
  vector<int> group;

  auto process_group = [&]() {
    if (group.size() == 0) return;
    result += lis_length(group);
  };

  for (int i = 0; i < n; ++i) {
    const Lizard& current = lizards[i];

    bool grouped_with_last = (i > 0 && lizards[i - 1].is_grouped_with(current));
    if (!grouped_with_last) {
      process_group();
      group.clear();  
    }

    group.push_back(current.height);
  }

  process_group();

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;

  while (cin >> x >> y) {
    Point tv(x, y);

    int n;
    cin >> n;

    vector<Lizard> lizards(n);
    for (auto&& lizard : lizards) {
      cin >> x >> y >> lizard.height;
      lizard.location = Point(x, y);
      lizard.cuadrant = Point(tv.x() - x, tv.y() - y).cuadrant();
      lizard.slope_to_tv = make_slope(lizard.location, tv);
      lizard.sqr_dist_to_tv = tv.sqr_dst_to(lizard.location);
    }
    sort(begin(lizards), end(lizards));

    cout << solve(tv, lizards) << endl;
  }

  return 0;
}
