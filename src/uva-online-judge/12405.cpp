#include <iostream>
#include <string>
using namespace std;

int MinNumberOfScarecrows(const string& field) {
  int num_placed = 0;

  for (int i = 0; i < (int)field.size(); ++i) {
    if (field[i] == '.') {
      num_placed += 1;
      i += 2;
    }
  }

  return num_placed;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    int n;
    cin >> n;

    string field;
    cin >> field;

    cout << "Case " << tc << ": " << MinNumberOfScarecrows(field) << '\n';
  }

  return 0;
}
