#include <bits\stdc++.h>
using namespace std;

int main()
{
  // Fast IO
  ios_base::sync_with_stdio(0); cin.tie(0);

  int m, n;
  int t[50005][10];
  while (cin >> m >> n)
  {
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        cin >> t[i][j];

    typedef pair<int, int> ii;
    int busy[5] = {-1, -1, -1, -1, -1};
    set<ii> events;
    vector<int> ans;

    events.insert(ii(t[0][0], 0));
    busy[0] = 0;

    while (events.size() > 0)
    {
      int tm = events.begin()->first;
      int pt = events.begin()->second;
      events.erase(events.begin());
      // cout << "picture_done=" << busy[pt] << ", time=" << tm << 
      //   ", painter=" << pt << "\n";

      // Is this picture done?
      if (pt == n-1)
      {
        ans.push_back(tm);
      }
      // Was someone waiting for me to finish painting?
      if (pt < n-1 && busy[pt+1] == -1)
      {
        int picture = busy[pt];
        busy[pt+1] = picture;
        events.insert(ii(tm + t[picture][pt+1], pt+1));
      }
      // Is the next picture available?
      int next_picture = busy[pt] + 1;
      bool next_picture_aval = (next_picture != m);
      for(int i = 0; i < pt; i++)
        if (busy[i] == next_picture)
          next_picture_aval = false;
      // If so, I'll start working on it right away
      if (next_picture_aval)
      {
        busy[pt] = next_picture;
        events.insert(ii(tm + t[next_picture][pt], pt));
      }
      // If not, let's sit back and relax
      else
      {
        busy[pt] = -1;
      }
    }
    
    // Answer
    //assert((int)ans.size() == m);
    for(int i = 0; i < (int)ans.size(); i++)
    {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }

  return 0;
}
