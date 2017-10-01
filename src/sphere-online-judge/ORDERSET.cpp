#include <bits/stdc++.h>
using namespace std;

template <typename T>
class FenwickTree {
 public:
  FenwickTree() {}

  FenwickTree(unsigned int n) { Init(n); }

  T Query(int x) const {
    T result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) result += data[i];
    return result;
  }

  T QueryInterval(int x, int y) const { return Query(y) - Query(x - 1); }

  T QuerySingle(int x) const {
    T result = data[x];
    if (x > 0) {
      int y = (x & (x + 1)) - 1;
      x -= 1;
      while (x != y) {
        result -= data[x];
        x = (x & (x + 1)) - 1;
      }
    }
    return result;
  }

  void Update(int x, T delta) {
    for (int i = x; i < (int)data.size(); i = (i | (i + 1))) data[i] += delta;
  }

  unsigned int size() const { return data.size(); }

  void Init(unsigned int n) { data.assign(n, 0); }

  vector<T> data;
};

void uniquify(vector<int> &vec) {
  sort(begin(vec), end(vec));
  vec.erase(unique(begin(vec), end(vec)), vec.end());
}

int main() {
  int q;
  cin >> q;

  using Command = pair<char, int>;
  vector<Command> cmds;

  vector<int> mp;
  for(int i = 0; i < q; i++) {
    string cmd;
    int arg;
    cin >> cmd >> arg;

    if (cmd == "I" || cmd == "D") {
      mp.push_back(arg);
    }
    cmds.emplace_back(cmd[0], arg);
  }
  uniquify(mp);

  FenwickTree<int> ft(mp.size());
  auto get_element_id = [&mp](int x) {
    size_t result = distance(mp.begin(), lower_bound(begin(mp), end(mp), x));
    return result;
  };

  size_t set_size = 0;
  for(int i = 0; i < q; i++) {
    switch (cmds[i].first) {
      case 'I':
      {
        size_t pos = get_element_id(cmds[i].second);
        int val = ft.QuerySingle(pos);
        if (val == 0) {
          ft.Update(pos, 1);
          set_size += 1;
        }
        break;
      }
      case 'D':
      {
        size_t pos = get_element_id(cmds[i].second);
        int val = ft.QuerySingle(pos);
        if (val == 1) {
          ft.Update(pos, -1);
          set_size -= 1;
        }
        break;
      }
      case 'C':
      {
        const int X = cmds[i].second;
        // Find out how many values smaller than X are there
        size_t pos = get_element_id(X);
        size_t result = 0;
        if (0 < pos && pos < mp.size()) {
          result = ft.Query(pos - 1);
        } else if (pos == mp.size()) {
          result = set_size;
        }
        // Print it
        cout << result << '\n';
        break;
      }
      case 'K':
      {
        const size_t K = cmds[i].second;
        if (K > set_size) {
          cout << "invalid\n";
        } else {
          // Find out which value is the K-th one
          int lo = 0, hi = mp.size() - 1;
          while (lo < hi) {
            int mid = (lo + hi) / 2;
            size_t val = ft.Query(mid);
            if (val >= K) {
              hi = mid;
            } else {
              lo = mid + 1;
            }
          }
          // Print it
          cout << mp[lo] << '\n';
        }
      }
    }
  }

  return 0;
}
