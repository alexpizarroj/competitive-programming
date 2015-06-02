#include <bits/stdc++.h>
using namespace std;

const bool kEnglish = false, kFrench = true;
const int kInf = 1000000007;

void uniquify(vector<int>& vec) {
  sort(begin(vec), end(vec));
  vec.erase(unique(begin(vec), end(vec)), end(vec));
}

bool bit_at(int mask, int i) {
  return (mask >> i) & 1;
}

struct Solver {
  vector<string> sentences;

  void read_input() {
    int n;
    cin >> n;
    cin.ignore(1);

    sentences.reserve(n);
    for(int i = 0; i < n; i++) {
      string line;
      getline(cin, line);
      sentences.push_back(line);
    }
  }

  int run(const vector<vector<int>>& st, const int smask) {
    vector<int> eng, fre;

    for(int i = 0; i < (int)st.size(); i++) {
      if (bit_at(smask, i) == kEnglish) {
        eng.insert(end(eng), begin(st[i]), end(st[i]));
      } else {
        fre.insert(end(fre), begin(st[i]), end(st[i]));
      }
    }

    uniquify(eng);
    uniquify(fre);

    vector<int> result(eng.size() + fre.size());
    auto it = set_intersection(begin(eng), end(eng), begin(fre), end(fre),
      begin(result));

    int ans = distance(result.begin(), it);

    return ans;
  }

  void solve(int cur_tc, int* solve_return) {
    const int n = sentences.size();

    map<string, int> strid;
    vector<string> idstr;

    vector<vector<int>> st(n, vector<int>());
    for(int i = 0; i < n; i++) {
      const string& line = sentences[i];

      stringstream ss(line);
      string word;
      while (ss >> word) {
        if (strid.count(word) == 0) {
          int new_id = strid.size();
          strid.insert(make_pair(word, new_id));
          idstr.push_back(word);
        }

        int id = strid[word];
        st[i].push_back(id);
      }

      uniquify(st[i]);
    }

    assert(strid.size() == idstr.size());

    const int n_results = (1 << (n - 2));
    vector<int> results(n_results);

    int result = kInf;
    for(int i = 0, mask = 0; mask < n_results; ++i, ++mask) {
      int smask = (mask << 2) + 2;
      int cand = run(st, smask);
      result = min(result, cand);
    }

    *solve_return = result;

    string output = "Finished running #" + to_string(cur_tc) + "\n";
    cerr << output;
  }
};

int main() {
  int tc;
  cin >> tc;

  vector<Solver> cases(tc);
  vector<thread> jobs;
  vector<int> results(tc);

  for(int i = 0; i < tc; i++) {
    cases[i].read_input();
    jobs.emplace_back(&Solver::solve, cases[i], i + 1, &results[i]);
  }

  for(int i = 0; i < tc; i++) {
    jobs[i].join();
  }

  for(int tt = 1; tt <= tc; tt++) {
    cout << "Case #" << tt << ": " << results[tt-1] << '\n';
  }

  return 0;
}
