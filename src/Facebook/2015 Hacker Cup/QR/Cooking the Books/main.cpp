#include <bits\stdc++.h>
using namespace std;

int eval(const string &s)
{
  int res = 0, mult = 1;
  for(int i = (int)s.size() - 1; i >= 0; i--)
  {
    res += (s[i] - '0') * mult;
    mult *= 10;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  for(int tc = 1;  tc <= t; tc++)
  {
    string s;
    cin >> s;

    int mx = eval(s), mn = mx, len = s.size();
    for(int i = 0; i < len; i++)
      for(int j = i + 1; j < len; j++)
      {
        if (i == 0 && s[j] == '0')
          continue;

        string cand = s;
        swap(cand[i], cand[j]);

        int res = eval(cand);
        mx = max(mx, res);
        mn = min(mn, res);
      }
      
    cout << "Case #" << tc << ": " << mn << " " << mx << endl;
  }
  
  return 0;
}
