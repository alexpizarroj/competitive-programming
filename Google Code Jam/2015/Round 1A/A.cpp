#include <bits/stdc++.h>
using namespace std;

int min_s1(const vector<int> &v)
{
  int ans = 0;
  for(int i = 1; i < (int)v.size(); i++)
  {
    if (v[i-1] > v[i])
    {
      ans += (v[i-1] - v[i]);
    }
  }
  return ans;
}

int min_s2(const vector<int> &v)
{
  int lo = 0, hi = 10000;
  while (lo < hi)
  {
    int mid = (lo + hi) / 2;

    bool ok = true;
    for(int i = 1; i < (int)v.size(); i++)
    {
      const int cur = v[i];
      const int last = v[i-1];

      if (last - mid > cur)
      {
        ok = false;
        break;
      }
    }

    if (ok)
    {
      hi = mid;
    }
    else
    {
      lo = mid + 1;
    }
  }

  int ans = 0;
  for(int i = 1; i < (int)v.size(); i++)
  {
    ans += min(v[i-1], lo);
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }

    auto ans1 = min_s1(v);
    auto ans2 = min_s2(v);
    cout << "Case #" << test << ": " <<
      ans1 << " " << ans2 << '\n';
  }

  return 0;
}