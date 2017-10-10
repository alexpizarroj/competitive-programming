#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solve(int n, vector<int>& C) {
  int ans = 0;

  stack<int> st;
  long long sum = 0;

  for (int i = 0; i < n; ++i) {
    while (sum >= C[i]) {
      sum -= st.top();
      st.pop();
    }

    sum += C[i];
    st.push(C[i]);

    if (i+1 < n && sum >= C[i+1]) continue;

    ans = max(ans, (int)st.size());
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int n;
    cin >> n;

    vector<int> C(n);
    for (int i = 0; i < n; ++i) cin >> C[i];

    cout << solve(n, C) << endl;
  }
}