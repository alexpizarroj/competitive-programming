#include <bits/stdc++.h>
using namespace std;

struct Student
{
  Student(int cid, int idx, int value) 
    : cid(cid), idx(idx), value(value) { }

  int cid, idx, value;
};

bool operator<(const Student &lhs, const Student &rhs)
{
  return (lhs.value < rhs.value);
}

int main() {
  const int kInf = 1000000007;

  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> stu(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> stu[i][j];
      }
      sort(begin(stu[i]), end(stu[i]), greater<int>());
    }
    
    priority_queue<Student, vector<Student>> pq;
    int worst = kInf;
    for(int i = 0; i < n; i++) {
      pq.push(Student(i, 0, stu[i][0]));
      worst = min(worst, stu[i][0]);
    }

    int ans = kInf;
    while (true) {
      Student s = pq.top();
      pq.pop();

      ans = min(ans, s.value - worst);
      if (s.idx == m - 1) {
        break;
      }

      int next_val = stu[s.cid][s.idx + 1];
      worst = min(worst, next_val);
      pq.push(Student(s.cid, s.idx + 1, next_val));
    }

    cout << ans << '\n';
  }
  
  return 0;
}
