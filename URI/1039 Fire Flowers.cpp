#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int r1, x1, y1, r2, x2, y2;
  while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    int dr = r1 - r2;
    int dd = dx*dx + dy*dy;
    int rr = dr*dr;
    
    if (dd <= rr && r1 >= r2) {
      puts("RICO");
    } else {
      puts("MORTO");
    }
  }
}
