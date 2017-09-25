#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;
const long long inf64 = (long long)inf * inf;

struct Island {
  Island() {}
  long long x, y;
  int id;
};

bool operator<(const Island& lhs, const Island& rhs) {
  if (lhs.y == rhs.y) {
    return lhs.x < rhs.x;
  }
  return lhs.y < rhs.y;
}

struct Bridge {
  long long length;
  int id;
};

bool operator<(const Bridge& lhs, const Bridge& rhs) {
  if (lhs.length == rhs.length) {
    return lhs.id < rhs.id;
  }
  return lhs.length < rhs.length;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 

  int n, m;
  while (cin >> n >> m) {
    vector<Island> islands;
    for(int i = 0; i < n; i++) {
      Island s;
      cin >> s.x >> s.y;
      s.id = i;
      islands.push_back(s);
    }

    for(int i = 0; i < n - 1; i++) {
      long long x = islands[i].x, y = islands[i].y;
      islands[i].x = islands[i + 1].x - y;
      islands[i].y = islands[i + 1].y - x;
    }
    islands.pop_back();

    sort(begin(islands), end(islands));

    set<Bridge> bridges;
    for(int i = 0; i < m; i++) {
      Bridge b;
      cin >> b.length;
      b.id = i + 1;

      bridges.insert(b);
    }

    bool ok = true;
    vector<int> result(n - 1, -1);
    for(int i = 0; i < n - 1; i++) {
      Bridge target = {islands[i].x, 0};
      auto it = bridges.lower_bound(target);

      if (it == bridges.end() || (*it).length > islands[i].y) {
        ok = false;
        break;
      }

      result[islands[i].id] = (*it).id;
      bridges.erase(it);
    }

    if (ok) {
      cout << "Yes\n";
      for(int i = 0; i < n - 1; i++) {
        assert(result[i] != -1);
        cout << result[i] << " ";
      }
      cout << '\n';
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
