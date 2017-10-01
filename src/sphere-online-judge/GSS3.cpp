#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

const int inf = 1000000007;

struct Node
{
  int s, e;                     // Interval covered by this node
  int son[2];                   // Children of this node
  int prefix, suffix, sum, val; // Data

  Node() {}

  Node(int a) : prefix(-inf), suffix(-inf), sum(0), val(-inf) { }

  void UpdateFromChildren(const Node &le, const Node &ri)
  {
    //assert(son[0] != -1 && son[1] != -1);
    sum = le.sum + ri.sum;
    prefix = max(le.prefix, le.sum + ri.prefix);
    suffix = max(ri.suffix, ri.sum + le.suffix);
    val = max(le.suffix + ri.prefix, max(le.val, ri.val));
  }

  void UpdateFromValue(int x)
  {
    //assert(son[0] == -1 && son[1] == -1);
    prefix = suffix = sum = val = x;
  }
};

struct SegTree
{
  vector<Node> T;

  SegTree(const vector<int> &a)
  {
    const int N = a.size();
    Node n(0);
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    
    T.reserve(4*N);
    T.push_back(n);
    Init(0, a);
  }

  void Init(int u, const vector<int> &a)
  {
    Node &n = T[u];
    if (n.e - n.s == 1)
    {
      n.UpdateFromValue(a[n.s]);
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
    n.UpdateFromChildren(T[n.son[0]], T[n.son[1]]);
  }

  void Update(int u, int pos, int val)
  {
    Node &n = T[u];
    if (n.e <= pos || n.s > pos)
      return;

    if (n.e - n.s == 1)
    {
      n.UpdateFromValue(val);
      return;
    }

    Update(n.son[0], pos, val);
    Update(n.son[1], pos, val);
    n.UpdateFromChildren(T[n.son[0]], T[n.son[1]]);
  }

  Node Query(int u, int le, int ri)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return Node(0);

    if (n.s == le && n.e == ri)
      return n;

    Node res, int0, int1;
    int0 = Query(n.son[0], le, min(T[n.son[0]].e, ri));
    int1 = Query(n.son[1], max(T[n.son[1]].s, le), ri);
    res.UpdateFromChildren(int0, int1);
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  while (cin >> n)
  {
    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];

    SegTree s(a);
    int m;
    cin >> m;
    while (m--)
    {
      int t, x, y;
      cin >> t >> x >> y;
      if (t == 1)
      {
        int ans = s.Query(0, x-1, y).val;
        cout << ans << "\n";
        continue;
      }
      s.Update(0, x-1, y);
    }
  }

  return 0;
}