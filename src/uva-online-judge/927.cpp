#include <iostream>
#include <vector>
using namespace std;

long long EvaluatePolinomial(const vector<int>& poli, int x) {
  long long res = poli[0], curval = 1;
  for (int i = 1; i < (int)poli.size(); ++i) {
    curval *= x;
    res += curval * poli[i];
  }
  return res;
}

long long FindValue(const vector<int>& poli, int d, int k) {
  int n = 0, num_seen_values = 0;

  while (true) {
    n += 1;

    long long span_size = (long long)n * d;
    if (num_seen_values + span_size >= k) return EvaluatePolinomial(poli, n);
    num_seen_values += span_size;
  }

  return -1;  // Should never happen
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int poli_degree;
    cin >> poli_degree;

    vector<int> poli(poli_degree + 1);
    for (int i = 0; i <= poli_degree; ++i) cin >> poli[i];

    int d, k;
    cin >> d >> k;

    cout << FindValue(poli, d, k) << endl;
  }

  return 0;
}
