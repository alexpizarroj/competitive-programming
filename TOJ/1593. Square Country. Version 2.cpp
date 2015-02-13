#include <bits\stdc++.h>
using namespace std;

class Solver
{
public:
  Solver()
  {
    const int kMax = 31622776;
    is_prime.assign(kMax + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i*i <= kMax; i++)
    {
      if (!is_prime[i])
        continue;
      for(int j = i*i; j <= kMax; j += i)
        is_prime[j] = false;
    }
  }

  vector<pair<long long, int>> Factorize(long long x)
  {
    vector<pair<long long, int>> res;

    for(int i = 0; i < (int)is_prime.size(); i++)
    {
      if (!is_prime[i])
        continue;
      if ((long long)i * i > x)
        break;

      if (x % i == 0)
      {
        pair<long long, int> p = {i, 0};
        while (x % i == 0)
        {
          p.second += 1;
          x /= i;
        }
        res.push_back(p);
      }
    }
    if (x > 1)
    {
      res.push_back(make_pair(x, 1));
    }

    return move(res);
  }

  bool IsSquare(long long x)
  {
    long long lo = 1, hi = 1000000000;
    while (lo < hi)
    {
      long long mid = (lo + hi) / 2;
      if (mid * mid >= x)
        hi = mid;
      else
        lo = mid + 1;
    }
    return (lo * lo == x);
  }

  int GetMinSquares(long long x)
  {
    if (IsSquare(x))
      return 1;

    bool good = true;
    vector<pair<long long, int>> f = Factorize(x);
    for(int i = 0; i < (int)f.size(); i++)
      if (f[i].first % 4 == 3 && f[i].second % 2 != 0)
      {
        good = false;
        break;
      }
    if (good)
      return 2;

    while (!(x & 3))
      x >>= 2;
    if (x % 8 != 7)
      return 3;

    return 4;
  }

private:
  vector<bool> is_prime;
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  Solver s;
  long long x;
  while (cin >> x)
    cout << s.GetMinSquares(x) << "\n";

  return 0;
}
