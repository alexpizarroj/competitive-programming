#include <bits\stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  while (cin >> n)
  {
    vector<int> b(n);
    for(int i = 0; i < n; i++)
      cin >> b[i];
    sort(begin(b), end(b));

    int diff = b[n-1] - b[0];
    long long ways = 0;
    if (diff == 0)
    {
      ways = ((long long)n * (n-1)) / 2;
    }
    else
    {
      int min_count = 0, max_count = 0;
      for(int i = 0; i < n; i++)
      {
        if (b[i] == b[0])
          min_count += 1;
        else if (b[i] == b[n-1])
          max_count += 1;
        ways = (long long)min_count * max_count;
      }
    }
    cout << diff << " " << ways << endl;
  }

  return 0;
}
