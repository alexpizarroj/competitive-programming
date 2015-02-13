#include <bits/stdc++.h>
using namespace std;

const int kMax = 10000000;
vector<int> p;

void Sieve()
{
  p.assign(kMax + 1, 0);
  p[0] = p[1] = -1;
  for(int i = 2; i <= kMax; i++)
    p[i] = i;
  
  for(int i = 2; i * i <= kMax; i++)
  {
    if (p[i] != i)
      continue;
    for(int j = i * i; j <= kMax; j += i)
      p[j] = i;
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  vector<int> primacity(kMax + 1, 0);
  Sieve();
  for(int i = 2; i <= kMax; i++)
  {
    if (p[i] == i)
    {
      primacity[i] = 1;
      continue;
    }

    int other = i / p[i];
    primacity[i] = primacity[other] + (other % p[i] == 0 ? 0 : 1);
  }

  for(int i = 2; i <= 10; i++)
    if (primacity[i] == 5)
      cout << i << " ";
  cout << endl;

  const int kPrecalcSize = 9;
  vector<int> sum[kPrecalcSize];
  for(int i = 1; i < kPrecalcSize; i++)
  {
    sum[i].assign(kMax + 1, 0);
    sum[i][0] = 0;
    for(int j = 1; j <= kMax; j++)
      sum[i][j] = sum[i][j-1] + (primacity[j] == i ? 1 : 0);
  }

  int t;
  cin >> t;
  for(int tc = 1;  tc <= t; tc++)
  {
    int a, b, k;
    cin >> a >> b >> k;

    int ans = 0;
    if (k < kPrecalcSize)
      ans = sum[k][b] - sum[k][a-1];

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  
  return 0;
}
