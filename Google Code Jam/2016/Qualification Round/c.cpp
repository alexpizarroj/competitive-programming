#include <iostream>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  
  for (int tcase = 1; tcase <= tc; ++tcase) {
    cout << "Case #" << tcase << ":\n";
    
    int N, J;
    cin >> N >> J;
    
    if ((N != 16 && N != 32) || (N == 16 && J > 128) || (N == 32 && J > 32768)) {
      cout << "I can't solve this test case\n";
      continue;
    }
    
    const int paircnt = (N - 2) / 2;
    
    for (int i = 0; i < J; ++i) {
      cout << '1';
      for (int j = paircnt-1; j >= 0; --j) {
        int bitval = (i >> j) & 1;
        cout << bitval << bitval;
      }
      cout << "1 3 2 5 2 7 2 9 2 11\n";
    }
  }
  
  return 0;
}

/*
** Reasoning
**
---------------------------------------------------------

x^k + x^k*x
= x^k * (x + 1)

3 2 5 2 7 2 9 2 11

---------------------------------------------------------

15 adjacent pairs to turn off and on

9, 7, 5, 3
381520424476945831628649898810
157775382034845806615042744
4656612873077392578126
617673396283948

10, 8, 6, 4, 2
10000000000000000000000000000001 -> multiple of 11
9903520314283042199192993793     -> multiple of 9
1326443518324400147398657        -> multiple of 7
4611686018427387905              -> multiple of 5
2147483649                       -> multiple of 3

---------------------------------------------------------

7 adjacent pairs to turn off and on

9, 7, 5, 3
205891132094650
4747561509944
30517578126
14348908

10, 8, 6, 4, 2
1000000000000001 -> multiple of 11
35184372088833   -> multiple of 9
470184984577     -> multiple of 7
1073741825       -> multiple of 5
32769            -> multiple of 3

*/
