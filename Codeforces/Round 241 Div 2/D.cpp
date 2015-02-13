#include <bits\stdc++.h>
using namespace std;

long long BitSum(const vector<long long> &t, int x)
{
  long long result = 0;
  for(int i = x; i >= 0; i = (i & (i+1)) - 1)
    result += t[i];
  return result;
}

long long BitSum(const vector<long long> &t, int i, int j)
{
  if (i > j)
    return 0;
  return BitSum(t, j) - (i > 0 ? BitSum(t, i-1) : 0);
}

void BitInc(vector<long long> &t, int x, int delta)
{
  const int n = t.size();
  for(int i = x; i < n; i = (i | (i+1)))
    t[i] += delta;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  while (cin >> n)
  {
    vector<int> values(n);
    for(int i = 0; i < n; i++)
      cin >> values[i];

    vector<int> values_set = values;
    sort(begin(values_set), end(values_set));
    values_set.resize(distance(values_set.begin(),
      unique(begin(values_set), end(values_set))
    ));

    map<int, int> val_to_idx;
    for(int i = 0; i < (int)values_set.size(); i++)
      val_to_idx[values_set[i]] = i;

    vector<int> le_f(n), ri_f(n);
    vector<int> freq(values_set.size(), 0);
    for(int i = 0; i < n; i++)
    {
      int pos = val_to_idx[values[i]];
      freq[pos] += 1;
      le_f[i] = freq[pos];
    }
    freq.assign(values_set.size(), 0);
    for(int i = n-1; i >= 0; i--)
    {
      int pos = val_to_idx[values[i]];
      freq[pos] += 1;
      ri_f[i] = freq[pos];
    }

    vector<long long> t(n+1, 0);
    for(int i = 0; i < n; i++)
      BitInc(t, ri_f[i], 1);

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
      BitInc(t, ri_f[i], -1);
      ans += BitSum(t, 1, le_f[i]-1);
    }
    cout << ans << endl;
  }

  return 0;
}
