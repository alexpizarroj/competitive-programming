#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int x, k;
  while (cin >> x >> k)
  {
    const int kNotUsed = -1;
    const int kDiv2 = 2;
    const int kDiv1 = 1;
    
    vector<int> s(x, kNotUsed);
    int ans1 = 0, ans2 = x - 1;
    for(int i = 0; i < k; i++)
    {
      int t;
      cin >> t;
      if (t == 1)
      {
        int num1, num2;
        cin >> num2 >> num1;
        s[num2] = kDiv2;
        s[num1] = kDiv1;
        ans2 -= 2;
      }
      else
      {
        int num;
        cin >> num;
        s[num] = kDiv2;
        ans2 -= 1;
      }
    }

    int len = 0;
    for(int i = 1; i <= x; i++)
    {
      if (i < x && s[i] == kNotUsed)
        len += 1;
      else
      {
        ans1 += (len / 2) + (len & 1);
        len = 0;
      }
    }

    // Output
    cout << ans1 << " " <<  ans2 << endl;
  }

  return 0;
}
