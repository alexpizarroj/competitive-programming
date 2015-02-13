#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
  int s, e;       // Interval covered by this node
  int son[2];     // Children of this node
  int sum, min;   // Node data
};

struct SegTree
{
  vector<Node> T;

  SegTree(const vector<int> &a)
  {
    const int N = a.size();
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    n.sum = n.min = 0;
    
    T.reserve(4*N);
    T.push_back(n);
    Init(0, a);
  }

  void Init(int u, const vector<int> &a)
  {
    Node &n = T[u];
    if (n.e - n.s == 1)
    {
      n.sum = a[n.s];
      n.min = n.sum;
      return; 
    }

    int mid = (n.s + n.e) / 2;
    for(int i = 0; i < 2; i++)
    {
      Node c(n);
      if (i == 0)
        c.e = mid;
      else
      {
        c.son[0] = -1;
        c.s = mid;
      }
      n.son[i] = T.size();
      T.push_back(c);
      Init(n.son[i], a);
    }

    n.sum = T[n.son[0]].sum + T[n.son[1]].sum;
    n.min = min(T[n.son[0]].min, T[n.son[0]].sum + T[n.son[1]].min);
  }

  void Update(int u, int pos)
  {
    Node &n = T[u];
    if (n.e <= pos || n.s > pos)
      return;

    if (n.e - n.s == 1)
    {
      n.sum *= -1;
      n.min = n.sum;
      return;
    }

    Update(n.son[0], pos);
    Update(n.son[1], pos);
    n.sum = T[n.son[0]].sum + T[n.son[1]].sum;
    n.min = min(T[n.son[0]].min, T[n.son[0]].sum + T[n.son[1]].min);
  }

  pair<int, int> Query()
  {
    return make_pair(T[0].sum, T[0].min);
  }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, tc = 1;
  while (cin >> n)
  {
    string s;
    cin >> s;

    vector<int> a(s.size());
    for(int i = 0; i < n; i++)
    {
      a[i] = (s[i] == '(' ? 1 : -1);
    }
    SegTree st(a);

    int m;
    cin >> m;
    cout << "Test " << (tc++) << ":\n";
    while (m--)
    {
      int x;
      cin >> x;
      if (x == 0)
      {
        pair<int, int> res = st.Query();
        cout << (!res.first && !res.second ? "YES" : "NO") << "\n";
        continue;
      }
      st.Update(0, x-1);
    }
  }

  return 0;
}