#include <bits\stdc++.h>
using namespace std;

struct Node
{
  int s, e;       // Interval covered by this node
  int son[2];     // Children of this node
  int sum;        // Data

  void UpdateFromChildren(const Node &le, const Node &ri)
  {
    sum = le.sum + ri.sum;
  }

  void UpdateFromValue(int x)
  {
    sum = x;
  }
};

struct SegTree
{
  vector<Node> T;

  SegTree(int N, int start_value)
  {
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    n.sum = start_value;
    
    T.reserve(4*N);
    T.push_back(n);
    Init(0);
  }

  void Init(int u)
  {
    Node &n = T[u];
    if (n.e - n.s == 1)
    {
      // Starting value is already set
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
      Init(n.son[i]);
    }
    n.UpdateFromChildren(T[n.son[0]], T[n.son[1]]);
  }

  void Update(int u, int pos, int val)
  {
    Node &n = T[u];
    if (n.e <= pos || n.s > pos)
      return;

    if (n.e - n.s == 1)
    {
      n.sum = val;
      return;
    }

    Update(n.son[0], pos, val);
    Update(n.son[1], pos, val);
    n.UpdateFromChildren(T[n.son[0]], T[n.son[1]]);
  }

  int Query(int u, int le, int ri)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return 0;

    if (n.s == le && n.e == ri)
      return n.sum;

    int res = Query(n.son[0], le, min(T[n.son[0]].e, ri));
    res += Query(n.son[1], max(T[n.son[1]].s, le), ri);
    return res;
  }
};

vector<int> GetIndex(const vector<int> &p)
{
  vector<int> ans(p.size());
  SegTree st(p.size(), 0);
  for(int i = (int)p.size() - 1; i >= 0; i--)
  {
    ans[i] = st.Query(0, 0, p[i]);
    st.Update(0, p[i], 1);
  }
  return move(ans);
}

vector<int> GetIndexesSum(const vector<int> &p, const vector<int> &q)
{
  vector<int> ans(p.size());
  int radix = 1, carry = 0;
  for(int i = (int)p.size() - 1; i >= 0; i--)
  {
    int value = (p[i] + q[i] + carry);
    ans[i] = value % radix;
    carry = value / radix;
    radix += 1;
  }
  return move(ans);
}

int QueryPos(const SegTree &st, int sum)
{
  const vector<Node> &T = st.T;
  Node n = T[0];
  while (n.e - n.s > 1)
  {
    if (T[n.son[0]].sum >= sum)
    {
      n = T[n.son[0]];
    }
    else
    {
      sum -= T[n.son[0]].sum;
      n = T[n.son[1]];
    }
  }
  return n.s;
}

vector<int> GetPermFromIndex(const vector<int> &pval)
{
  vector<int> ans(pval.size());
  SegTree st(pval.size(), 1);
  for(int i = 0; i < (int)pval.size(); i++)
  {
    ans[i] = QueryPos(st, pval[i] + 1);
    st.Update(0, ans[i], 0);
  }
  return move(ans);
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  while (cin >> n)
  {
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++)
      cin >> p[i];
    for(int i = 0; i < n; i++)
      cin >> q[i];

    vector<int> pval, qval;
    pval = GetIndex(p);
    qval = GetIndex(q);

    vector<int> resval;
    resval = GetIndexesSum(pval, qval);
    
    vector<int> res;
    res = GetPermFromIndex(resval);

    for(int x : res)
      cout << x << " ";
    cout << "\n";
  }
  
  return 0;
}
