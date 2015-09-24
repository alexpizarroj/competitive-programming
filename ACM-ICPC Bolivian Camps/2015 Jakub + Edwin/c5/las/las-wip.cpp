#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<int> random_testcase(int n) {
  srand(time(NULL));
  
  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = (rand() % 100) + 1;
  }
  return result;
}

vector<int> slow_solve(int n, const vector<int>& vec) {
  vector<int> want(n, 0), choice(n , -1);
  
  auto decide = [&](int g) -> int {
    if (choice[g] != -1) {
      want[choice[g]] -= 1;
      choice[g] = -1;
    }
    
    const int le = g, ri = (g + 1) % n;
    int leval = vec[le], rival = vec[ri];
    if (want[le] == 1) { leval /= 2; }
    if (want[ri] == 1) { rival /= 2; }
    
    if (leval > rival) {
      want[le] += 1;
      choice[g] = le;
    } else {
      want[ri] += 1;
      choice[g] = ri;
    }
    
    return choice[g];
  };
  
  bool changed = true;
  while (changed) {
    changed = false;
    for (int g = 0; g < n; g++) {
      int old = choice[g];
      if (old != decide(g)) {
        changed = true;
      }
    }
  }
  
  return choice;
}

int is_fast_solve_ok(const vector<int>& vec, const vector<int>& choice) {
  const int n = vec.size();
  
  for (int i = 0; i < n; i++) {
    int le = i, ri = (i + 1) % n;
    int leval = vec[le], rival = vec[ri];
    
    int bef = (i - 1 + n) % n;
    if (choice[bef] == le) {
      leval /= 2;
    }
    if (choice[ri] == ri) {
      rival /= 2;
    }
    
    int dec = -1;
    if (leval > rival) {
      dec = le;
    } else if (rival > leval) {
      dec = ri;
    }
    
    if (dec != -1 && choice[i] != dec) {
      return i;
    }
  }
  
  return -1;
}

vector<int> solve(int n, const vector<int>& preview, bool autofix = true) {
  vector<int> vec(n);
  auto it = min_element(begin(preview), end(preview));
  int min_pos = distance(begin(preview), it);
  for (int i = 0, j = min_pos; i < n; ++i, j = (j + 1) % n) {
    vec[i] = preview[j];
  }
  
  vector<ii> inter;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (i == n || vec[i] < (long long)vec[i - 1] * 2) {
      inter.push_back(make_pair(last, i - 1));
      last = i;
    }
  }
  
  const int m = inter.size();
  vector<int> choice(n);
  vector<bool> one_sized_used_next(n, false);
  for (int i = 0; i < m; i++) {
    const ii& p = inter[i];
    const ii& p_next = inter[(i + 1) % m];
    int psz = p.second - p.first + 1;
    int pnsz = p_next.second - p_next.first + 1;
    
    if (psz == 1) {
      if (pnsz == 1) {
          choice[p.first] = p.first;
      } else {
        int fnext = (p.first + 1) % n;
        if (vec[fnext] >= vec[p.first]) {
          choice[p.first] = fnext;
          one_sized_used_next[p.first] = true;
        } else {
          choice[p.first] = p.first;
        }
        choice[p.first] = (vec[p.first] > vec[fnext] ? p.first : fnext);
      }
    } else { // if (psz >= 2)
      for (int j = p.first; j < p.second; j++) {
        choice[j] = j + 1;
      }
      if (pnsz == 1) {
        choice[p.second] = p.second;
      } else {
        int next_last = (p.second + 1) % n;
        int le = vec[p.second] / 2, ri = vec[next_last];
        choice[p.second] = (le > ri ? p.second : next_last);
      }
    }
  }
  
  for (int i = 0; i < m; i++) {
    const ii& p = inter[i];
    const ii& p_next = inter[(i + 1) % m];
    int psz = p.second - p.first + 1;
    int pnsz = p_next.second - p_next.first + 1;
    
    if (psz == 1 && pnsz == 1 && one_sized_used_next[p_next.first]) {
      if (vec[p_next.first] > vec[p.first]) {
        choice[p.first] = p_next.first;
      }
    }
  }
  
  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    int prev_i = (i - min_pos + n) % n;
    int val = (choice[prev_i] + min_pos) % n;
    result[i] = val;
  }
  
  cout << "INFO\n";
  cout << "Idx:";
  for (int i = 0; i < n; i++) {
    cout << setw(3) << i;
  }
  cout << endl;
  cout << "Vec:";
  for (int x : vec) {
    cout << setw(3) << (x / 2);
  }
  cout << endl;
  cout << "Cho:";
  for (int x : choice) {
    cout << setw(3) << x;
  }
  cout << endl << "end of test case" << endl;
  
  if (autofix && is_fast_solve_ok(preview, result) != -1) {
    result = slow_solve(n, preview);
  }
  
  return result;
}

void test() {
  while (true) {
    vector<int> rtc = random_testcase(5);
    vector<int> ret = solve(rtc.size(), rtc, false);
    int ans = is_fast_solve_ok(rtc, ret);
    if (ans != -1) {
      cout << "Found counter case" << endl;;
      for (int i = 0; i < (int)rtc.size(); i++) {
        cout << (i > 0 ? " " : "") << rtc[i];
      }
      cout << "\nPosition " << ans << " is suboptimal" << endl;
      break;
    }
  }
}

int main() {
  //test();
  
  int n;
  while (cin >> n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
      vec[i] *= 2;
    }
    
    vector<int> ans = solve(n, vec, false);
    
    for (int i = 0; i < n; i++) {
      cout << (i > 0 ? " " : "") << (ans[i] + 1);
    }
    cout << endl;
    cout << is_fast_solve_ok(vec, ans) << endl;
  }
  return 0;
}