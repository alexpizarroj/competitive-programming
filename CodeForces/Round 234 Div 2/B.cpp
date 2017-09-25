#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m;
  while (cin >> n >> m)
  {
    bool possible = true;

    vector<int> dist_target(n);
    for(int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      if (!possible)
        continue;

      int pos1 = -1, pos2 = -1;
      for(int j = 0; j < m; j++)
      {
        if (s[j] == 'G')
          pos1 = j;
        else if (s[j] == 'S')
          pos2 = j;
      }

      if (pos1 > pos2)
        possible = false;
      else
        dist_target[i] = pos2 - pos1;
    }

    // Output
    int ans = -1;
    if (possible)
      ans = set<int>(begin(dist_target), end(dist_target)).size();
    cout << ans << endl;
  }
  
  return 0;
}
