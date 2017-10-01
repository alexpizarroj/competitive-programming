#include <bits/stdc++.h>
using namespace std;

int from_binary(int x)
{
  int m = 1, result = 0;
  while (x > 0)
  {
    result += (x % 2) * m;
    x /= 2;
    m *= 10;
  }
  return result;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  const int kMax = 1000007;

  vector<int> quasi;
  for(int i = 1, x; (x = from_binary(i)) < kMax; i++)
  {
    quasi.push_back(x);
    //cout << x << endl;
  }
  //cout << (int)quasi.size() << '\n';

  vector<int> dp_choice(kMax, 0);
  vector<int> dp_size(kMax, 0);
  dp_choice[0] = 0;
  dp_size[0] = 0;
  dp_choice[1] = 1;
  dp_size[1] = 1;
  for(int i = 2; i < kMax; i++)
  {
    dp_size[i] = kMax;
    for(int j = 0; j < (int)quasi.size(); j++)
    {
      if (quasi[j] > i)
      {
        break;
      }

      int prev = i - quasi[j];
      int cand = 1 + dp_size[prev];
      if (cand < dp_size[i])
      {
        dp_choice[i] = quasi[j];
        dp_size[i] = cand;
      }
    }
    //cout << i << " -> " << dp_size[i] << endl;
  }

  int q;
  while (cin >> q)
  {
    cout << dp_size[q] << '\n';
    for(int cur = q; cur > 0; cur -= dp_choice[cur])
    {
      cout << dp_choice[cur] << " ";
    }
    cout << '\n';
  }

  return 0;
}