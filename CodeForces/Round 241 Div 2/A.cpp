#include <bits\stdc++.h>
using namespace std;

int main()
{
  // Fast IO
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  while (cin >> n)
  {
    int hi = 2000000000;
    int lo = -hi;
    for(int i = 0; i < n; i++)
    {
      string sign, ans;
      int x;
      cin >> sign >> x >> ans;

      if (sign == ">=")
      {
        if (ans == "Y")
          lo = max(lo, x);
        else
          hi = min(hi, x-1);
      }
      else if (sign == "<=")
      {
        if (ans == "Y")
          hi = min(hi, x);
        else
          lo = max(lo, x+1);
      }
      else if (sign == ">")
      {
        if (ans == "Y")
          lo = max(lo, x+1);
        else
          hi = min(hi, x);
      }
      else // if (sign == "<")
      {
        if (ans == "Y")
          hi = min(hi, x-1);
        else
          lo = max(lo, x);
      }

      // Negative answer
      if (lo > hi)
      {
        puts("Impossible");
        break;
      }
    }

    // Positive answer
    if (lo <= hi)
    {
      printf("%d\n", hi);
    }
  }

  return 0;
}
