#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
using vi = vector<int>;
using ii = pair<int, int>;

struct IntPoint {
  int id;
  int x, y, box;
};

bool byXAscending(const IntPoint& lhs, const IntPoint& rhs) {
  return lhs.x < rhs.x;
}

bool byBoxThenByY(const IntPoint& lhs, const IntPoint& rhs) {
  if (lhs.box != rhs.box) {
    return lhs.box < rhs.box;
  }
  if (lhs.box % 2 == 0) {
    return lhs.y < rhs.y;
  }
  return lhs.y > rhs.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  while (cin >> n) {
    vector<IntPoint> vec;
    for (int i = 0; i < n; ++i) {
      IntPoint ip;
      ip.id = i + 1;
      cin >> ip.x >> ip.y;
      vec.emplace_back(std::move(ip));
    }
    
    sort(begin(vec), end(vec), byXAscending);
    
    int last = 0, limit = 1000, box_seq = 0;
    for (int i = 0; i <= n; ++i) {
      if (i < n && vec[i].x <= limit) {
        continue;
      }
      
      // If we have a box with at least one point...
      if (last <= i - 1) {
        // Mark the range
        for (int j = last; j < i; ++j) {
          vec[j].box = box_seq;
        }
        box_seq += 1;
        
        // Update the start of the range for the next box
        last = i;
      }
      
      if (i != n) i -= 1; // retry this point with another box
      limit += 1000;
    }
    
    sort(begin(vec), end(vec), byBoxThenByY);
    
    for (int i = 0; i < n; ++i) {
      cout << vec[i].id << " ";
    }
    cout << endl;
  }
  
  return 0;
}
