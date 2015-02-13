#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  for(int tc = 1;  tc <= t; tc++)
  {
    vector<int> wants(3);
    for(int i = 0; i < 3; i++)
      cin >> wants[i];

    int n;
    cin >> n;
    vector<int> P(n), C(n), F(n);
    for(int i = 0; i < n; i++)
    {
      cin >> P[i] >> C[i] >> F[i];
    }

    bool good = false;
    for(int mask = 1; mask < (1<<n); mask++)
    {
      vector<int> got(3, 0);
      for(int i = 0; i < n; i++)
      {
        if ((mask >> i) & 1)
        {
          got[0] += P[i];
          got[1] += C[i];
          got[2] += F[i];
        }
      }
      if (got == wants)
      {
        good = true;
        break;
      }
    }
      
    cout << "Case #" << tc << ": " << (good ? "yes" : "no") << endl;
  }
  
  return 0;
}
