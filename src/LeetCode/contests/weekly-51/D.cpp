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

  void Init(unsigned int n) { data.assign(n, 0); }

  vector<T> data;
};

class Solution {
public:
  int kEmptySlots(vector<int>& flowers, int k) {
    const int n = flowers.size();
    FenwickTree<int> ft(n+1);
    
    for (int day = 1; day <= n; ++day) {
      int x = flowers[day-1];
      ft.Update(x, 1);
      
      int left = x - k - 1;
      if (left >= 1 && ft.QueryInterval(left, x) == 2 && ft.QuerySingle(left) == 1) return day;
      
      int right = x + k + 1;
      if (right <= n && ft.QueryInterval(x, right) == 2 && ft.QuerySingle(right) == 1) return day;
    }
    return -1;
  }
};

int main() {
  vector<int> c1{6,5,8,9,7,1,10,2,3,4};
  
  Solution s;
  cout << s.kEmptySlots(c1, 2) << endl;
  
  return 0;
}
