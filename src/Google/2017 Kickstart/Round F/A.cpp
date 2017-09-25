#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class FenwickTree {
 public:
  FenwickTree() {}

  FenwickTree(unsigned int n) { Init(n); }

  T Query(int x) const {
    T result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) result += data[i];
    return result;
  }

  T QueryInterval(int x, int y) const { return Query(y) - Query(x - 1); }

  T QuerySingle(int x) const {
    T result = data[x];
    if (x > 0) {
      int y = (x & (x + 1)) - 1;
      x -= 1;
      while (x != y) {
        result -= data[x];
        x = (x & (x + 1)) - 1;
      }
    }
    return result;
  }

  void Update(int x, T delta) {
    for (int i = x; i < (int)data.size(); i = (i | (i + 1))) data[i] += delta;
  }

  unsigned int size() const { return data.size(); }

  void Init(unsigned int n) { data.assign(n, 0); }

  vector<T> data;
};

int findPivotPosition(const int n, const FenwickTree<int>& ft, const int E) {
  int low = 0, high = n;
  while (high - low > 1) {
    int mid = (high + low) / 2;
    if (ft.Query(mid) < E) {
      low = mid;
    } else {
      high = mid;
    }
  }
  
  return high;
}

string solve() {
  int n;
  cin >> n;
  
  vector<int> p(n+1);
  FenwickTree<int> ft(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    ft.Update(i, 1);
  }
  
  int curmin = 1, curmax = n;
  for (int step = 0; step < n-1; ++step) {
    const int E = (n-step-1)/2 + 1;
    const int pivotPos = findPivotPosition(n, ft, E);
    const int pivot = p[pivotPos];
    
    if (pivot != curmin && pivot != curmax) return "NO";
    
    ft.Update(pivotPos, -1);
    if (pivot == curmin) curmin += 1;
    if (pivot == curmax) curmax -= 1;
  }
  
  return "YES";
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    cout << "Case #" << i << ": " << solve() << endl;
  }
  return 0;
}
