#include <bits/stdc++.h>
using namespace std;

using SparseRow = map<int, int>;
using SparseMatrix = map<int, SparseRow>;

void PrintSparseMatrix(const SparseMatrix& matrix, int m, int n) {
  cout << m << " " << n << '\n';

  for (int i = 1; i <= m; ++i) {
    auto row_it = matrix.find(i);

    if (row_it == matrix.end()) {
      cout << "0\n\n";
      continue;
    }

    const SparseRow& row = row_it->second;

    cout << row.size();
    for (auto&& kvp : row) cout << " " << kvp.first;
    cout << '\n';

    bool preprend_space = false;
    for (auto&& kvp : row) {
      cout << (preprend_space ? " " : "") << kvp.second;
      preprend_space = true;
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  while (cin >> m >> n) {
    SparseMatrix matrix;

    for (int i = 1; i <= m; ++i) {
      int r;
      cin >> r;

      vector<int> indices(r);
      for (int k = 0; k < r; ++k) cin >> indices[k];

      for (int k = 0; k < r; ++k) {
        int value;
        cin >> value;

        int j = indices[k];
        matrix[j][i] = value;
      }
    }

    PrintSparseMatrix(matrix, n, m);
  }

  return 0;
}