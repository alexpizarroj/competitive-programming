#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    vector< pair<int, int> > ans;
    for(int a = 1; a <= 12; a++)
      for(int b = 1; b <= 12; b++)
        if (a * b == 12)
        {
          vector<bool> valid(b, true);
          for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
              valid[j] = valid[j] && (s[i*b+j] == 'X');

          for(int j = 0; j < b; j++)
          {
            if (valid[j])
            {
              ans.push_back(make_pair(a, b));
              break;
            }
          }
        }

    cout << ans.size();
    for(int i = 0; i < (int)ans.size(); i++)
      cout << " " << ans[i].first << "x" << ans[i].second;
    cout << endl;
  }
  
  return 0;
}
