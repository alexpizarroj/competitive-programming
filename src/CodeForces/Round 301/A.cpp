#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  string a, b;
  cin >> a >> b;
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x = a[i] - '0', y = b[i] - '0';
    ans += min((y - x + 10) % 10, (x - y + 10) % 10);
  }
  cout << ans << '\n';
  
  return 0;
}
