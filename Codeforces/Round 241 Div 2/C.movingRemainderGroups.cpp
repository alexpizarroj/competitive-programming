#include <bits\stdc++.h>
using namespace std;

void solve(int n, int d, int k)
{
  // Trivial corner case
  if (k >= n)
  {
    for(int i = 0; i < d; i++)
    {
      for(int j = 1; j <= n; j++)
        cout << j << " ";
      cout << endl;
    }
    return;
  }
  // Single day/bus corner case
  if (d == 1 || k == 1)
  {
    cout << "-1" << endl;
    return;
  }

  // ----------------
  // GENERAL SOLUTION
  // ----------------
  // Is this possible?
  int levels = (n / k) + (n % k == 0 ? 0 : 1);
  int daysNeeded;
  long long g = 1;
  for(daysNeeded = 1; daysNeeded <= d; daysNeeded++)
  {
    if (g >= levels)
      break;
    g = g * k;
  }
  if (daysNeeded > d)
  {
    cout << "-1" << endl;
    return;
  }
  // If it is, then solve it!
  vector<int> bus(n);
  for(int i = 0; i < n; i++)
  {
    bus[i] = (i % k) + 1;
    cout << bus[i] << " ";
  }
  cout << endl;
  long long th = 1;
  for(int i = 1; i < d; i++)
  {
    for(int j = 0; j < n; j++)
    {
      const int current_level = j / k;
      int offset = current_level / th;
      bus[j] = (((bus[j] - 1) + offset) % k) + 1;
      cout << bus[j] << " ";
    }
    cout << endl;
    if (i < daysNeeded)
      th *= k;
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, d, k;
  while (cin >> n >> k >> d)
    solve(n, d, k);

  return 0;
}
