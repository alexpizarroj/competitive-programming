#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(int n, int x) {
  if (n == 1) return vector<int>{x};
  
  auto ret = vector<int>(n);
  int cur = 0;
  for (int i = 0; i < n-1; ++i)
  {
    ret[i] = i;
    cur ^= i;
  }
  
  const int kOffset = 0b1000000000000000000;
  ret[0] = 0 | kOffset;
  ret[n-1] = (cur ^ x) | kOffset;
  
  if (ret[0] == ret[n-1]) {
    if (n >= 3) {
      ret[0] = 0;
      ret[1] = 1 | kOffset;
    } else {
      ret.clear();
    }
  }
  
  return ret;
}

void printAnswer(const vector<int>& vec) {
  if (vec.size() == 0) {
    cout << "NO" << endl;
    return;
  }
  
  cout << "YES" << endl;
  for (int x: vec) cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int n, x;
  while (cin >> n >> x) {
    printAnswer(solve(n, x));
  }
  
  return 0;
}
