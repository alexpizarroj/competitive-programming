#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &plates)
{
  const int inf = 1000000007;
  const int max_elem = *max_element(begin(plates), end(plates));
  
  int ans = inf;
  
  for(int top = 1; top <= max_elem; top++)
  {
    int cand = 0;
    
    for(int i = 0; i < (int)plates.size(); i++)
    {
      int value = (plates[i] / top);
      value += (plates[i] % top != 0 ? 1 : 0);
      if (value > 1)
      {
        cand += value - 1;
      }
    }
    cand += min(max_elem, top);
      
    ans = min(ans, cand);
  }
  
  return ans;
}

int main()
{
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    int D;
    cin >> D;
    
    vector<int> plates;
    for(int i = 0; i < D; i++)
    {
      int x;
      cin >> x;
      plates.push_back(x);
    }
    
    int ans = solve(plates);
    cout << "Case #" << test << ": " << ans << '\n';
  }

  return 0;
}