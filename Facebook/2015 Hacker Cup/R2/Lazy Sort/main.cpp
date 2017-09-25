#include <bits\stdc++.h>
using namespace std;

class Solver
{
public:
  bool SolveFor(int start, const vector<int> &v)
  {
    int head = start, tail = start;
    int n = v.size(), lo = 0, hi = n - 1;
    if (start == v[0])
      lo += 1;
    else
      hi -= 1;
    assert(lo <= hi);

    int rem = n - 1;
    while (rem > 0)
    {
      bool found = false;
      int alt[2] = {v[lo], v[hi]};
      for(int i = 0; i < 2; i++)
      {
        if (alt[i]+1 == head)
        {
          head = alt[i];
          if (i == 0)
            lo += 1;
          else
            hi -= 1;
          found = true;
          break;
        }
        else if (alt[i]-1 == tail)
        {
          tail = alt[i];
          if (i == 0)
            lo += 1;
          else
            hi -= 1;
          found = true;
          break;
        }
      }
      if (found)
        rem -= 1;
      else
        break;
    }

    return (rem == 0);
  }

  void Solve()
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      cin >> v[i];
    bool res = (SolveFor(v[0], v) || SolveFor(v[n-1], v));
    cout << (res ? "yes" : "no") << endl;
  }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  for(int tc = 1;  tc <= t; tc++)
  {
    cout << "Case #" << tc << ": ";
    Solver s;
    s.Solve();
  }
  return 0;
}
