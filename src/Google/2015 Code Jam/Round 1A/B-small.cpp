#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
  int g = __gcd(a, b);
  return (a / g) * b;
}

int simulate(const vector<int> &tt, int n)
{
  typedef pair<int, int> ii;
  priority_queue<ii, vector<ii>, greater<ii>> pq;

  for(int i = 0; i < (int)tt.size(); i++)
  {
    pq.push(ii(0, i));
  }

  for(int i = 1; i < n; i++)
  {
    ii next = pq.top();
    pq.pop();
    pq.push(ii(next.first + tt[next.second], next.second));
  }

  int ret = pq.top().second + 1;
  return ret;
}

int main()
{
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    int b, n;
    cin >> b >> n;

    vector<int> tt(b);
    int cycle_time = 1;
    for(int i = 0; i < b; i++)
    {
      cin >> tt[i];
      cycle_time = lcm(cycle_time, tt[i]);
    }

    int cuts_per_cycle = 0;
    for(int i = 0; i < b; i++)
    {
      cuts_per_cycle += cycle_time / tt[i];
    }

    n = ((n - 1) % cuts_per_cycle) + 1;

    auto ans = simulate(tt, n);
    cout << "Case #" << test << ": " << ans << '\n';
  }

  return 0;
}