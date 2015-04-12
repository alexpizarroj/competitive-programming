#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    int ms;
    cin >> ms;
    
    string people;
    cin >> people;
    
    for(int ans = 0; ans <= 1000; ans++)
    {
      bool ok = true;
      
      int standing = ans;
      for(int i = 0; i <= ms; i++)
      {
        if (i > standing)
        {
          ok = false;
          break;
        }
        standing += (people[i] - '0');
      }
      
      if (ok)
      {
        cout << "Case #" << test << ": " << ans << '\n';
        break;
      }
    }
  }

  return 0;
}