#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
  int baseEnergy, n;
  cin >> baseEnergy >> n;
  
  vector<int> teams(n);
  for (int& x: teams) cin >> x;
  sort(begin(teams), end(teams));
  
  int ans = 0;
  
  int honor = 0;
  int energy = baseEnergy;
  int left = 0, right = n - 1;
  
  while (true) {
    // Beat all the fuckers
    bool wonSome = false;
    while (left <= right && energy > teams[left]) {
      honor += 1;
      energy -= teams[left];
      left += 1;
      
      wonSome = true;
      ans = max(honor, ans);
    }
    
    if (!wonSome) break;
    
    // Recruit all the fuckers
    while (right > left && energy <= teams[left] && honor > 0) {
      energy += teams[right];
      honor -= 1;
      right -= 1;
      
      ans = max(honor, ans);
    }
  }
  
  return ans;
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    cout << "Case #" << i << ": " << solve() << endl;
  }
  return 0;
}
