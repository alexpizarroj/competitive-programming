#include <bits\stdc++.h>
using namespace std;

int GCD(int a, int b)
{
  int c;
  while (b != 0)
  {
    c = a%b;
    a = b;
    b = c;
  }
  return a;
}

void FillRun(int x, vector<int> &v)
{
  int next = x + 1;
  v.push_back(x);
  while (v.size() < 4)
  {
    bool valid = true;
    for(int term : v)
      if (GCD(next, term) != 1)
      {
        valid = false;
        break;
      }
    if (valid)
    {
      v.push_back(next);
    }
    next += 1;
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  // Runs precalculations
  typedef vector<int> vi;
  const int kMaxValue = 1000000;
  vector<vi> run(kMaxValue+1, vi());
  for(int i = 1; i <= kMaxValue; i++)
  {
    FillRun(i, run[i]);
  }

  // Solutions computation
  const int kMaxN = 10000;
  vector< pair<int, int> > choice(kMaxN+1);
  choice[1] = make_pair(1, run[1].back());
  for(int i = 2; i <= kMaxN; i++)
  {
    pair<int, int> &ans = choice[i];
    int start = choice[i-1].second + 1;
    ans = make_pair(start, run[start].back());
    int ending = ans.second - 3;
    for(int j = start + 1; j <= ending; j++)
    {
      if (run[j].back() < ans.second)
      {
        ans.first = j;
        ans.second = run[j].back();
      }
    }
  }

  // Querries answering
  int n, k;
  while (cin >> n >> k)
  {
    cout << choice[n].second * k << '\n';
    for(int i = 1; i <= n; i++)
    {
      int x = choice[i].first;
      for(int v : run[x])
        cout << (v * k) << " ";
      cout << '\n';
    }
  }

  return 0;
}
