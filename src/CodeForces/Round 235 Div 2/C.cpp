#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m;
  while (cin >> n >> m)
  {
    int loz, hiz;
    loz = (m - 1) / 2;
    hiz = m + 1;
    if (loz <= n && n <= hiz)
    {
      string tmp;
      while (m > 0)
      {
        int c = min(2, m);
        while (c > 0)
        {
          tmp.push_back('1');
          m -= 1;
          c -= 1;
        }
        if (m > 0)
        {
          tmp.push_back('0');
          n -= 1;
        }
      }
      for(int i = 0; i < (int)tmp.size(); i++)
      {
        if (n > 0 && (i == 0 || (tmp[i] == '1' && tmp[i-1] == '1')))
        {
          cout << 0;
          n -= 1;
        }
        cout << tmp[i];
      }
      if (n > 0)
      {
        cout << 0;
        n -= 1;
      }
      cout << endl;
      assert(n == 0);
    }
    else
      cout << -1 << endl;
  }

  return 0;
}
