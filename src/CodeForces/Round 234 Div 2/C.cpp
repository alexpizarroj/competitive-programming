#include <bits\stdc++.h>
using namespace std;

/*
A -> (n x m)
B is the matrix after the transformation
B -> (m x n)

90 clockwise rotation
---------------------
for all: A(i, j) = B(j, n - i + 1)
swap(n, m)

horizontal rotation
===================
for all: A(i, j) = B(i, m - j + 1)

90 counter clockwise rotation
-----------------------------
A(i, j) = B(m - j + 1, i)
swap(n, m)
*/

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m, x, y, z, p;
  while (cin >> n >> m >> x >> y >> z >> p)
  {
    vector< pair<int, int> > candies(p);
    for(int i = 0; i < p; i++)
      cin >> candies[i].first >> candies[i].second;

    x %= 4;
    y %= 2;
    z %= 4;
    // CW
    while (x--)
    {
      for(int i = 0; i < p; i++)
      {
        int x, y;
        x = candies[i].second;
        y = n - candies[i].first + 1;
        candies[i] = make_pair(x, y);
      }
      swap(n, m);
    }
    // Horizontal
    while (y--)
    {
      for(int i = 0; i < p; i++)
      {
        candies[i].second = m - candies[i].second + 1;
      }
    }
    // CCW
    while (z--)
    {
      for(int i = 0; i < p; i++)
      {
        int x, y;
        x = m - candies[i].second + 1;
        y = candies[i].first;
        candies[i] = make_pair(x, y);
      }
      swap(n, m);
    }

    // Output
    for(int i = 0; i < p; i++)
      cout << candies[i].first << " " << candies[i].second << endl;
  }
  
  return 0;
}
