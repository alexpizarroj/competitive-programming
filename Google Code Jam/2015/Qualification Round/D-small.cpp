#include <bits/stdc++.h>
using namespace std;

// 0 = Richard, 1 = Gabriel
int solve(int x, int r, int c)
{
  if ((r * c) % x != 0)
    return 0;
  
  if (x <= 2)
    return 1;
  
  bool t[5] = {0};
  t[r] = t[c] = true;
  
  if (x == 3)
  {
    if (t[1]) return 0;
    if (t[2]) return 1;
    if (t[3]) return 1;
    if (t[4]) return 0;
  }
  
  // if (x == 4)
  if (t[1] || t[2]) return 0;
  return 1;
}

int main()
{
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    int x, r, c;
    cin >> x >> r >> c;
    
    string ans = (solve(x, r, c) ? "GABRIEL" : "RICHARD");
    cout << "Case #" << test << ": " << ans << "\n";
  }

  return 0;
}