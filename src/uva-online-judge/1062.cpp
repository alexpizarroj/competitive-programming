#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string containers;
  for (int tc = 1; cin >> containers && containers != "end"; ++tc) {
    vector<stack<char>> stacks;

    for (char ch : containers) {
      int best_stack = stacks.size();
      char best_stack_top = 'Z' + 1;

      for (int i = 0; i < (int)stacks.size(); ++i) {
        if (stacks[i].top() >= ch && stacks[i].top() <= best_stack_top) {
          best_stack = i;
          best_stack_top = stacks[i].top();
        }
      }

      if (best_stack == (int)stacks.size()) stacks.push_back(stack<char>());
      stacks[best_stack].push(ch);
    }

    cout << "Case " << tc << ": " << stacks.size() << endl;
  }

  return 0;
}
