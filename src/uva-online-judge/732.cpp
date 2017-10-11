#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const bool kPush = true, kPop = false;

class Solution {
 public:
  Solution(const string& source, const string& target) {
    source_ = source;
    target_ = target;
  }

  vector<vector<bool>> FindAll() {
    result_.clear();

    stack<char> st;
    vector<bool> solution;
    rec(st, solution, 0, 0);

    return result_;
  }

 private:
  string source_, target_;
  vector<vector<bool>> result_;

  void rec(stack<char>& st, vector<bool>& solution, int src_pos, int dst_pos) {
    if (dst_pos == (int)target_.size()) {
      result_.emplace_back(solution);
    }

    // Consider pushing
    if (src_pos < (int)source_.size()) {
      st.push(source_[src_pos]);
      solution.push_back(kPush);

      rec(st, solution, src_pos + 1, dst_pos);

      solution.pop_back();
      st.pop();
    }

    // Consider popping
    if (st.size() > 0 && st.top() == target_[dst_pos]) {
      char popped_char = st.top();
      st.pop();
      solution.push_back(kPop);

      rec(st, solution, src_pos, dst_pos + 1);

      solution.pop_back();
      st.push(popped_char);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string source, target;
  while (cin >> source >> target) {
    Solution s(source, target);
    auto arrangements = s.FindAll();

    cout << "[\n";
    for (auto&& arr : arrangements) {
      for (int i = 0; i < (int)arr.size(); ++i) {
        if (i > 0) cout << " ";
        cout << (arr[i] == kPush ? "i" : "o");
      }
      cout << '\n';
    }
    cout << "]\n";
  }

  return 0;
}