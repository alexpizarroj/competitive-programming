#include <bits\stdc++.h>
using namespace std;

int C[25][25];

void Precalculate()
{
  C[0][0] = 1;
  C[1][0] = C[1][1] = 1;
  for(int i = 2; i <= 20; i++)
  {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++)
      C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}

class Solver
{
public:
  void solve()
  {
    vector<double> res(21);
    double p;
    cin >> p;

    res[0] = 0;
    res[1] = 1 / p;
    for(int cur = 2; cur <= 20; cur++)
    {
      double sum = 0;
      for(int j = 1; j <= cur; j++)
      {
        double prob = C[cur][j] * pow(p, (double)j);
        prob *= pow(1-p, double(cur-j));
        sum += prob * (1 + res[cur-j]);
      }

      double prob_0 = pow(1.0-p, (double)cur);
      res[cur] = (sum + prob_0) / (1 - prob_0);
    }

    cout << fixed << setprecision(5);
    cout << res[20] << endl;
  }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  Precalculate();

  int t;
  cin >> t;
  for(int tc = 1;  tc <= t; tc++)
  {
    cout << "Case #" << tc << ": ";
    Solver s;
    s.solve();
  }
  return 0;
}
