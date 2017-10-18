#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

const int kInf = 1000000007;
const int long long kBigInf = (long long)kInf * kInf;
using ii = pair<int, int>;
using vi = vector<int>;

void Main() {
  // Your code goes here
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef MEASURE_RUNTIME
  using get_time = chrono::steady_clock;
  using ms = chrono::milliseconds;
  auto starting_time = get_time::now();
#endif

  Main();

#ifdef MEASURE_RUNTIME
  auto ending_time = get_time::now();
  auto diff = ending_time - starting_time;
  auto elapsed_time = chrono::duration_cast<ms>(diff).count();
  cerr << "Elapsed time: " << elapsed_time << " [ms]" << endl;
#endif

#ifdef VS_CODE_DEBUG
  system("pause");
#endif

  return 0;
}
