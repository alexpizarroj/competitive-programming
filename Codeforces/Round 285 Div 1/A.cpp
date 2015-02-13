#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  typedef pair<int, int> ii;

  int n;
  while (cin >> n)
  {
    int m = 0;
    set<pair<ii, int>> st;
    vector<ii> data(n);
    for(int i = 0; i < n; i++)
    {
      cin >> data[i].first >> data[i].second;
      st.insert(make_pair(data[i], i));
      m += data[i].first;
    }
    m /= 2;

    cout << m << endl;
    while (!st.empty())
    {
      int degree = st.begin()->first.first;
      int parent = st.begin()->first.second;
      int node = st.begin()->second;
      st.erase(st.begin());
      if (degree == 0)
        continue;
      
      assert(degree == 1);
      data[node] = {0, 0};
      st.erase(make_pair(data[parent], parent));
      if (data[parent].first == 1)
      {
        data[parent] = {0, 0};
      }
      else
      {
        assert(data[parent].first > 1);
        data[parent].first -= 1;
        data[parent].second ^= node;
        st.insert(make_pair(data[parent], parent));
      }

      cout << node << " " << parent << "\n";
    }
  }
  
  return 0;
}
