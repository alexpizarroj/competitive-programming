#include <bits\stdc++.h>
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

  SegTree(int N)
  {
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    n.val = n.lazy = 0;
    
    T.reserve(4*N);
    T.push_back(n);
    Init(0);
  }

  void Init(int u)
  {
    Node &n = T[u];
    if (n.e - n.s == 1)
      return; 
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
  }

  void Update(int u, int le, int ri, int val)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return;

    if (n.s == le && n.e == ri)
    {
      n.lazy |= val;
      return;
    }

    if (le < T[n.son[0]].e)
    {
      Update(n.son[0], le, min(T[n.son[0]].e, ri), val);
      Update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    }
    else
    {
      Update(n.son[1], max(T[n.son[1]].s, le), ri, val);
    }
    n.val |= val;
  }

  void PushLazy(int u)
  {
    Node &n = T[u];
    if (n.lazy == 0)
      return;

    n.val |= n.lazy;
    for(int i = 0; i < 2; i++)
      if (n.son[i] != -1)
        T[n.son[i]].lazy |= n.lazy;
    n.lazy = 0;
  }

  int Query(int u, int le, int ri)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return 0;

    PushLazy(u);
    if (n.s == le && n.e == ri)
      return n.val;

    int res = Query(n.son[0], le, min(T[n.son[0]].e, ri));
    res |= Query(n.son[1], max(T[n.son[1]].s, le), ri);
    return res;
  }
};

struct Constraint
{
  int le, ri, val;
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m;
  while (cin >> n >> m)
  {
    vector<Constraint> C(m);
    for(int i = 0; i < m; i++)
    {
      Constraint &c = C[i];
      cin >> c.le >> c.ri >> c.val;
      c.le -= 1;
    }

    SegTree s(n);  
    for(int i = 0; i < m; i++)
        s.Update(0, C[i].le, C[i].ri, C[i].val);

    const int kMaxBits = 17;
    vector< vector<int> > B(n, vector<int>(kMaxBits, -1));
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
      a[i] = s.Query(0, i, i+1);
      B[i][0] = a[i];
    }

    for(int j = 1; j <= kMaxBits; j++)
      for(int i = 0; i + (1<<j) <= n; i++)
        B[i][j] = B[i][j-1] & B[i+(1<<(j-1))][j-1];

    bool good = true;
    for(int i = 0; i < m; i++)
    {
      int pos = C[i].le, len = C[i].ri - C[i].le;
      int res = 2147483647;
      for(int j = kMaxBits-1; j >= 0; j--)
        if ((1<<j) <= len)
        {
          res &= B[pos][j];
          pos += (1<<j);
          len -= (1<<j);
        }
      if (res != C[i].val)
      {
        good = false;
        break;
      }
    }

    if (good)
    {
      cout << "YES" << endl;
      for(int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n-1];
    }
    else
      cout << "NO" << endl;
  }

  return 0;
}