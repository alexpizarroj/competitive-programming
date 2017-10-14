#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int kInf = 1000000007;

struct Answer {
  int payed_amount, num_bills_used;
  Answer() : payed_amount(0), num_bills_used(0) {}
  Answer(int payed_amount, int num_bills_used)
      : payed_amount(payed_amount), num_bills_used(num_bills_used) {}
};

Answer Solve(int price, const vector<int>& bills) {
  const int kTotalMoney = accumulate(begin(bills), end(bills), 0);

  vector<int> min_num_bills(kTotalMoney + 1, kInf);
  min_num_bills[0] = 0;

  for (int bill : bills)
    for (int amount = kTotalMoney; amount >= bill; --amount)
      min_num_bills[amount] =
          min(min_num_bills[amount], min_num_bills[amount - bill] + 1);

  for (int amount = price; amount <= kTotalMoney; ++amount)
    if (min_num_bills[amount] != kInf)
      return Answer(amount, min_num_bills[amount]);

  return Answer(-1, -1);  // Should never happen
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int price;
    cin >> price;

    int n;
    cin >> n;

    vector<int> bills(n);
    for (int i = 0; i < n; ++i) cin >> bills[i];

    auto ans = Solve(price, bills);
    cout << ans.payed_amount << " " << ans.num_bills_used << '\n';
  }

  return 0;
}
