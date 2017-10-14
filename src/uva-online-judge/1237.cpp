#include <iostream>
#include <vector>
using namespace std;

struct DbEntry {
  string maker;
  int lowest, highest;

  bool ContainsPrice(int price) const {
    return lowest <= price && price <= highest;
  }
};

string FindUniqueMaker(const vector<DbEntry>& db, int price) {
  int id = -1;

  for (int i = 0; i < (int)db.size(); ++i) {
    if (!db[i].ContainsPrice(price)) continue;

    if (id == -1) {
      id = i;
      continue;
    }

    id = -1;
    break;
  }

  return (id == -1 ? "UNDETERMINED" : db[id].maker);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    if (tc > 1) cout << '\n';

    int num_entries;
    cin >> num_entries;

    vector<DbEntry> db(num_entries);
    for (auto&& entry : db) cin >> entry.maker >> entry.lowest >> entry.highest;

    int num_queries;
    cin >> num_queries;

    for (int i = 0; i < num_queries; ++i) {
      int price;
      cin >> price;
      cout << FindUniqueMaker(db, price) << '\n';
    }
  }

  return 0;
}
