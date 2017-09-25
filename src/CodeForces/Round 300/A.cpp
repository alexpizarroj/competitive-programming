#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  while (cin >> s)
  {
    const int n = s.size();
    bool ok = false;

    for(int i = 1; i < n; i++)
    {
      for(int j = 0; j + i <= n; j++)
      {
        string result;
        if (j > 0)
        {
          result += s.substr(0, j);
        }
        if (j + i < n)
        {
          result += s.substr(j + i, n - j - i);
        }
        if (result == "CODEFORCES")
        {
          ok = true;
        }
      }
    }

    cout << (ok ? "YES": "NO") << '\n';
  }

  return 0;
}