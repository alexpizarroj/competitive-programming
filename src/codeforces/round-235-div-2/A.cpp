#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, x;
  while (cin >> n >> x)
  {
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
      int value;
      cin >> value;
      sum += value;
    }
    if (sum < 0)
      sum *= -1;
    int ans = (sum / x) + (sum % x == 0 ? 0 : 1);
    cout << ans << endl;
  }

  return 0;
}
