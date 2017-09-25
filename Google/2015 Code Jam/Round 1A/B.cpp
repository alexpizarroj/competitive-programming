#include <bits/stdc++.h>
using namespace std;

long long get_attended_count(long long t, const vector<int> &tt)
{
  long long ret = 0;
  for(int x : tt)
  {
    ret += (t / x);
  }
  ret += tt.size();

  return ret;
}

int solve(const int n, const vector<int> &tt)
{
  if (n <= (int)tt.size())
  {
    return n;
  }

  long long lo = 0, hi = 1000000000000000;
  while (lo < hi)
  {
    long long mid = (lo + hi + 1) / 2;
    long long cnt = get_attended_count(mid, tt);
    if (cnt >= n)
    {
      hi = mid - 1;
    }
    else
    {
      lo = mid;
    }
  }

  int ac = (int)get_attended_count(lo, tt);
  for(int i = 0; i < (int)tt.size(); i++)
  {
    if ((lo + 1) % tt[i] == 0)
    {
      ac += 1;
      if (ac == n)
      {
        return (i + 1);
      }
    }
  }

  return -1; // this should never be reached
}

int main()
{
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    int b, n;
    cin >> b >> n;

    vector<int> tt(b);
    for(int i = 0; i < b; i++)
    {
      cin >> tt[i];
    }

    auto ans = solve(n, tt);
    cout << "Case #" << test << ": " << ans << '\n';
  }

  return 0;
}