#include <bits\stdc++.h>
using namespace std;

int mat[1005][1005];

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  typedef long long i64;
  typedef priority_queue<i64, vector<int>, less<int> > PriorityQueue_i64;

  int n, m, k, p;
  while (cin >> n >> m >> k >> p)
  {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> mat[i][j];

    vector<i64> a(k + 1);
    {
      PriorityQueue_i64 pq;
      a[0] = 0;
      for(int i = 0; i < n; i++)
      {
        i64 sum = 0;
        for(int j = 0; j < m; j++)
          sum += mat[i][j];
        pq.push(sum);
      }
      for(int i = 1; i <= k; i++)
      {
        i64 sum = pq.top();
        pq.pop();
        a[i] = a[i-1] + sum;
        pq.push(sum - m*p);
      }
    }
    
    vector<i64> b(k + 1);
    {
      PriorityQueue_i64 pq;
      b[0] = 0;
      for(int j = 0; j < m; j++)
      {
        i64 sum = 0;
        for(int i = 0; i < n; i++)
          sum += mat[i][j];
        pq.push(sum);
      }
      for(int i = 1; i <= k; i++)
      {
        i64 sum = pq.top();
        pq.pop();
        b[i] = b[i-1] + sum;
        pq.push(sum - n*p);
      }
    }

    i64 ans = a[0] + b[k];
    for(int rows = 1; rows <= k; rows++)
    {
      i64 candidate = a[rows] + b[k - rows];
      candidate -= (i64)rows * (k - rows) * p;
      ans = max(ans, candidate);
    }
    cout << ans << endl;
  }
  
  return 0;
}