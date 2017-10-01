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
  int daysNeeded = 1;
  long long g = k;
  while (daysNeeded <= d && n > g)
  {
     daysNeeded += 1;
     g *= k;
  }
  if (daysNeeded > d)
  {
    cout << "-1" << endl;
    return;
  }
  // If it is, then solve it!
  vector< vector<int> > bus(n);
  bus[0] = vector<int>(d, 0);
  for(int i = 1; i < n; i++)
  {
    int carry = 1;
    bus[i] = bus[i-1];
    for(int j = d-1; j >= 0; --j)
    {
      int value = bus[i][j] + carry;
      bus[i][j] = value;
      carry = 0;
      if (value >= k)
      {
        bus[i][j] = value % k;
        carry = value / k;
      }
    }
  }
  // Output
  for(int j = 0; j < d; j++)
  {
    for(int i = 0; i < n; i++)
      cout << (bus[i][j] + 1) << " ";
    cout << endl;
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
