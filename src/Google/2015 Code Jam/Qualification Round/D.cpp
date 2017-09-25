#include <bits/stdc++.h>
using namespace std;

// 0 = Richard, 1 = Gabriel
int solve(int x, int r, int c)
{
  if ((r * c) % x != 0)
    return 0;
  
  if (x <= 2)
    return 1;
  
  const int mini = min(r, c);
  bool t[30] = {0};
  t[r] = t[c] = true;
  
  if (x == 3)
  {
    if (mini == 1) return 0;
    return 1;
  }
  else if (x == 4)
  {
    if (mini <= 2) return 0;
    return 1;
  }
  else if (x == 5)
  {
    if (t[1] || t[2]) return 0;
    if (t[3] && t[5]) return 0;
    return 1;
  }
  else if (x == 6)
  {
    if (mini <= 3) return 0;
    else if (mini <= 18) return 1;
    else return 0;
  }
  
  return 0;
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