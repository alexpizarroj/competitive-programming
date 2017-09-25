#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
  int s, e;       // Interval covered by this node
  int son[2];     // Children of this node
  int val, lazy;  // Node info + Data to propagate
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
    n.val = n.lazy = 0;
    
    T.reserve(4*N);
    T.push_back(n);
    Init(0, a);
  }

  void Init(int u, const vector<int> &a)
  {
    Node &n = T[u];
    if (n.e - n.s == 1)
    {
      n.val = a[n.s];
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
    n.val = min(T[n.son[0]].val, T[n.son[1]].val);
  }

  void Update(int u, int le, int ri, int val)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return;

    if (n.s == le && n.e == ri)
    {
      n.lazy += val;
      n.val += val;
      return;
    }

    PushLazy(u);
    if (le < T[n.son[0]].e)
    {
      Update(n.son[0], le, min(T[n.son[0]].e, ri), val);
      Update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    }
    else
    {
      Update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    }
    n.val = min(T[n.son[0]].val, T[n.son[1]].val);
  }

  void PushLazy(int u)
  {
    Node &n = T[u];
    if (n.lazy == 0)
      return;

    for(int i = 0; i < 2; i++)
      if (n.son[i] != -1)
      {
        T[n.son[i]].val  += n.lazy;
        T[n.son[i]].lazy += n.lazy;
      }
    n.lazy = 0;
  }

  int Query(int u, int le, int ri)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return 1000000007;

    if (n.s == le && n.e == ri)
      return n.val;

    PushLazy(u);
    int res = Query(n.son[0], le, min(T[n.son[0]].e, ri));
    res = min(res, Query(n.son[1], max(T[n.son[1]].s, le), ri));
    return res;
  }

  void PrintTree()
  {
    for(int i = 0; i < (int)T.size(); i++)
    {
      const Node &n = T[i];
      cout << n.s << " " << n.e << " " << n.val << " " << n.lazy << endl;
    }
    cout << endl;
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

    vector<int> a(s.size() + 1);
    for(int i = 1; i <= n; i++)
    {
      a[i] = a[i-1] + (s[i-1] == '(' ? 1 : -1);
      //cout << a[i] << " \n"[i == n];
    }

    SegTree st(a);
    //st.PrintTree();

    int m;
    cin >> m;
    cout << "Test " << (tc++) << ":\n";
    while (m--)
    {
      int x;
      cin >> x;
      if (x == 0)
      {
        int a = st.Query(0, 1, n+1), b = st.Query(0, n, n+1);
        cout << (a >= 0 && b == 0 ? "YES" : "NO") << "\n";
      }
      else
      {
        char c = s[x-1];
        int val = (c == '(' ? -2 : 2);
        s[x-1] = (c == '(' ? ')' : '(');
        st.Update(0, x, n+1, val);
        //st.PrintTree();
      }
    }
  }

  return 0;
}