#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int x1, y1, x2, y2;
  while (cin >> x1 >> y1 >> x2 >> y2)
  {
    int x3, y3, x4, y4;
    if (x1 == x2)
    {
      int s = abs(y1 - y2);
      y3 = y1;
      y4 = y2;
      x3 = x4 = x1 + s;
    }
    else if (y1 == y2)
    {
      int s = abs(x1 - x2);
      x3 = x1;
      x4 = x2;
      y3 = y4 = y1 + s;
    }
    else
    {
      if (x1 > x2)
      {
        swap(x1, x2);
        swap(y1, y2);
      }
      int s = x2 - x1;
      if (s != abs(y1 - y2))
      {
        puts("-1");
        continue;
      }
      // All good
      x3 = x1;
      x4 = x2;
      if (y1 > y2)
      {
        y3 = y1 - s;
        y4 = y2 + s;
      }
      else
      {
        y3 = y1 + s;
        y4 = y2 - s;
      }
    }
    // Output
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  }

  return 0;
}
