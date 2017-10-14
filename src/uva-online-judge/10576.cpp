#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int kInf = 1000000007;
const unsigned int kNumMonthsPerReport = 5;
const unsigned int kNumMonthsPerYear = 12;

class Solver {
 public:
  Solver(int s, int d) : s_(s), d_(d) {}

  int solve() {
    ans_ = -kInf;

    vector<int> year;
    year.reserve(kNumMonthsPerYear);
    rec(year);

    return ans_;
  }

 private:
  int s_, d_, ans_;

  void rec(vector<int>& year) {
    if (!showsDeficitOnLastReport(year)) return;

    if (year.size() == kNumMonthsPerYear) {
      ans_ = max(ans_, accumulate(begin(year), end(year), 0));
      return;
    }

    year.push_back(s_);
    rec(year);
    year.pop_back();

    year.push_back(-d_);
    rec(year);
    year.pop_back();
  }

  bool showsDeficitOnLastReport(const vector<int>& year) {
    if (year.size() < kNumMonthsPerReport) return true;

    int sum = 0;
    for (auto i = year.size() - kNumMonthsPerReport; i < year.size(); ++i)
      sum += year[i];

    return (sum < 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int s, d;
  while (cin >> s >> d) {
    auto ans = Solver(s, d).solve();

    if (ans <= 0)
      cout << "Deficit\n";
    else
      cout << ans << '\n';
  }

  return 0;
}
