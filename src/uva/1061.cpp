#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<char> findRhfFactorsPC(string& parent1, string& child) {
  char rhfParent1 = parent1.back(), rhfChild = child.back();
  parent1.pop_back();
  child.pop_back();

  vector<char> result;
  result.push_back('+');
  if (!(rhfParent1 == '-' && rhfChild == '+')) result.push_back('-');
  return result;
}

vector<char> findRhfFactorsPP(string& parent1, string& parent2) {
  char rhfParent1 = parent1.back(), rhfParent2 = parent2.back();
  parent1.pop_back();
  parent2.pop_back();

  vector<char> result;
  if (rhfParent1 == '+' || rhfParent2 == '+') result.push_back('+');
  result.push_back('-');
  return result;
}

string combineMarkers(char marker1, char marker2) {
  if (marker1 == 'O') return string({marker2});
  if (marker2 == 'O') return string({marker1});
  if (marker1 == marker2) return string({marker1});
  if (marker1 < marker2) return string({marker1, marker2});
  return string({marker2, marker1});
}

const vector<pair<string, string>> combinations = {{"AA", "A"}, {"AB", "AB"},
                                                   {"AO", "A"}, {"BB", "B"},
                                                   {"BO", "B"}, {"OO", "O"}};

set<string> findParentMarkers(const string& parent1, const string& child) {
  set<string> result;

  for (auto&& p1 : combinations) {
    if (p1.second != parent1) continue;

    for (auto&& p2 : combinations) {
      // Try every possible parent2

      for (char c1 : p1.first)
        for (char c2 : p2.first) {
          string resultingChild = combineMarkers(c1, c2);
          if (resultingChild != child) continue;

          result.insert(p2.second);
        }
    }
  }

  return result;
}

set<string> findChildMarkers(const string& parent1, const string& parent2) {
  set<string> result;

  for (auto&& p1 : combinations) {
    if (p1.second != parent1) continue;

    for (auto&& p2 : combinations) {
      if (p2.second != parent2) continue;

      for (char c1 : p1.first)
        for (char c2 : p2.first) result.insert(combineMarkers(c1, c2));
    }
  }

  return result;
}

vector<string> solveForParent(string parent1, string child) {
  vector<char> rhfParent2 = findRhfFactorsPC(parent1, child);
  set<string> markers = findParentMarkers(parent1, child);

  vector<string> result;
  for (char rhf : rhfParent2)
    for (string m : markers) {
      m += rhf;
      result.push_back(m);
    }

  return result;
}

vector<string> solveForChild(string parent1, string parent2) {
  vector<char> rhfChild = findRhfFactorsPP(parent1, parent2);
  set<string> markers = findChildMarkers(parent1, parent2);

  vector<string> result;
  for (char rhf : rhfChild)
    for (string m : markers) {
      m += rhf;
      result.push_back(m);
    }

  return result;
}

string stringify(const vector<string>& v) {
  if (v.size() == 0) return "IMPOSSIBLE";
  if (v.size() == 1) return v[0];

  stringstream ss;
  ss << "{" << v[0];
  for (int i = 1; i < (int)v.size(); ++i) ss << ", " << v[i];
  ss << "}";

  return ss.str();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2, s3;
  for (int tc = 1; (cin >> s1 >> s2 >> s3) && s1 != "E"; ++tc) {
    cout << "Case " << tc << ":";

    if (s1 == "?") s1 = stringify(solveForParent(s2, s3));
    if (s2 == "?") s2 = stringify(solveForParent(s1, s3));
    if (s3 == "?") s3 = stringify(solveForChild(s1, s2));

    cout << " " << s1 << " " << s2 << " " << s3 << endl;
  }

  return 0;
}
