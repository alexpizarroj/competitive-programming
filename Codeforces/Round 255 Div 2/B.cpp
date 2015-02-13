#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  string s;
  while (cin >> s)
  {
    int k;
    cin >> k;

    int values[26], best = 0;
    for(int i = 'a'; i <= 'z'; i++)
    {
      cin >> values[int(i-'a')];
      best = max(best, values[int(i-'a')]);
    }

    long long ans = 0;
    for(int i = 0; i < (int)s.size(); i++)
    {
      int x = values[int(s[i]-'a')];
      ans += (i + 1) * x;
    }
    for(int i = 0; i < k; i++)
    {
      ans += (s.size() + i + 1) * best;
    }
    cout << ans << endl;
  }
  
  return 0;
}
