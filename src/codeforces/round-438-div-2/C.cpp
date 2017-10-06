// http://codeforces.com/problemset/problem/868/C

#include <bits/stdc++.h>
using namespace std;

int firstCommonValue(const vector<vector<int>>& sets) {
  int n = sets.size();
  if (n == 0) return 0;
  
  vector<int> idx(n, 0);
  while (true) {
    bool shouldExit = false;
    int minValue = 1000000007;
    
    for (int i = 0; i < n; ++i) {
      if (idx[i] >= (int)sets[i].size()) {
        shouldExit = true;
        break;
      }
      
      int value = sets[i][idx[i]];
      if (value < minValue) minValue = value;
    }
    
    if (shouldExit) break;
    
    int nAdvanced = 0;
    for (int i = 0; i < n; ++i) {
      if (sets[i][idx[i]] == minValue) {
        nAdvanced += 1;
        idx[i] += 1;
      }
    }
    
    if (nAdvanced == n) return sets[0][idx[0]-1];
  }
  
  return -1;
}

bool isValidSolution(const set<int>& P, const vector<vector<int>>& C) {
  const int n = P.size();
  if (n == 0) return false;
  
  for (int i = 0; i < (int)C.size(); ++i) {
    int nSeenProblems = n;
    
    for (int p : P) {
      bool found = false;
      for (int j = 0; j < (int)C[i].size(); ++j) {
        if (C[i][j] == p) {
          found = true;
          break;
        }
      }
      
      if (found) nSeenProblems -= 1;
    }
    
    if (2 * nSeenProblems > n) return false;
  }
  
  return true;
}

bool rec(const vector<vector<int>>& C, int idx, const set<int>& problemSet) {
  if (idx == (int)C.size()) return isValidSolution(problemSet, C);
  
  if (rec(C, idx+1, problemSet)) return true;
  
  for (int i = 0; i < (int)C[idx].size(); ++i) {
    set<int> nextProblemSet = problemSet;
    nextProblemSet.insert(C[idx][i]);
    if (rec(C, idx+1, nextProblemSet)) return true;
  }
  
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  while (cin >> n >> k) {
    auto newProblemsForTeam = vector<vector<int>>(k, vector<int>());
    
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        if (x == 0) newProblemsForTeam[j].push_back(i);
      }
    }
    
    auto newProblemsSubsetForTeam = vector<vector<int>>(k, vector<int>());
    
    for (int i = 1; i < (1 << k); ++i) {
      vector<vector<int>> selectedTeams;
      for (int j = 0; j < k; ++j) {
        if (!(i & (1 << j))) continue;
        selectedTeams.push_back(newProblemsForTeam[j]);
      }
      
      int value = firstCommonValue(selectedTeams);
      if (value == -1) continue;
      
      for (int j = 0; j < k; ++j) {
        if (!(i & (1 << j))) continue;
        newProblemsSubsetForTeam[j].push_back(value);
      }
    }
    
    auto emptyProblemSet = set<int>();
    
    auto ans = rec(newProblemsSubsetForTeam, 0, emptyProblemSet);
    
    cout << (ans ? "Yes" : "No") << endl;
  }
  
  return 0;
}
