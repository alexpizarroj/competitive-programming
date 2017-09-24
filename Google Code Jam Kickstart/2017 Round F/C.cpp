#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;

// C-large-practice.in running time: ~ 2m 40s
long double getAnswer_Iterative(int n, long double c1, long double c2, long double c3) {
  long double ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = c1*ans + c2*(n-1) + c3;
  }
  return ans;
}

long double getAnswer_WolframClosedForm(int n, long double c1, long double c2, long double c3) {
  long double pow_c1_n = pow(c1, n);
  long double x = c2 * (pow_c1_n - c1*n + n - 1) + (c1 - 1) * c3 * (pow_c1_n - 1);
  long double y = (c1 - 1) * (c1 - 1);
  return x / y;
}

long double solve() {
  int n, nEdges, nCodejamon;
  cin >> n >> nEdges >> nCodejamon;
  
  vector<vector<int>> fw(n, vector<int>(n, 1000000007));
  for (int i = 0; i < n; ++i) {
    fw[i][i] = 0;
  }
  
  for (int i = 0; i < nEdges; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    u -= 1, v -= 1;
    fw[u][v] = d;
    fw[v][u] = d;
  }
  
  // Floyd-Warshall
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
      }
    }
  }
  
  vector<int> fwRowSum(n, 0);
  int fwFullMatrixSum = 0;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      fwRowSum[i] += fw[i][j];
    }
    
    fwFullMatrixSum += fwRowSum[i];
  }
  
  const long double b1 = ((long double)1.0 / (n-1));
  const long double b2 = fwRowSum[0];
  const long double b3 = b1 * fwFullMatrixSum;
  const long double b4 = -b1;
  const long double b5 = b1*b3;
  const long double b6 = b1*b2;
  
  long double ans;
  //ans = getAnswer_Iterative(nCodejamon, b4, b5, b6);
  ans = getAnswer_WolframClosedForm(nCodejamon, b4, b5, b6);
  
  return ans;
}

int main() {
  int tc;
  
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    cout << "Case #" << i << ": " << fixed << setprecision(10) << solve() << endl;
  }
  
  return 0;
}
