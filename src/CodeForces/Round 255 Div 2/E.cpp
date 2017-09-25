#include <bits\stdc++.h>
using namespace std;

typedef long long i64;
const i64 mod = 1000000009;
vector<i64> fib(300005);

i64 Fnext(i64 a, i64 b, int k)
{
  if (k == 0)
    return a;
  i64 res = (a * fib[k-1]) + (b * fib[k]);
  res %= mod;
  return res;
}

i64 Fsum(i64 a, i64 b, int k)
{
  i64 res = (Fnext(a, b, k + 1) - b) % mod;
  if (res < 0)
    res += mod;
  return res;
}

struct Node
{
  int s, e;       // Interval covered by this node
  int son[2];     // Children of this node
  i64 sum, a, b;  // Node info + Data to propagate
};

struct SegTree
{
  vector<Node> T;

  SegTree(int N)
  {
    Node n;
    n.s = 0, n.e = N;
    n.a = n.b = n.sum = 0;
    n.son[0] = n.son[1] = -1;
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

  void Update(int u, int le, int ri, i64 a, i64 b)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return;

    if (n.s == le && n.e == ri)
    {
      n.a = (n.a + a) % mod;
      n.b = (n.b + b) % mod;
      return;
    }

    if (le < T[n.son[0]].e)
    {
      Update(n.son[0], le, min(T[n.son[0]].e, ri), a, b);

      i64 new_a, new_b;
      new_a = Fnext(a, b, T[n.son[0]].e - le);
      new_b = Fnext(a, b, T[n.son[0]].e - le + 1);
      Update(n.son[1], max(T[n.son[1]].s, le), ri, new_a, new_b);
    }
    else
    {
      Update(n.son[1], max(T[n.son[1]].s, le), ri, a, b);
    }
    n.sum = (n.sum + Fsum(a, b, ri - le)) % mod;
  }

  void PushLazy(int u)
  {
    Node &n = T[u];
    if (n.a == 0 && n.b == 0)
      return;

    n.sum = (n.sum + Fsum(n.a, n.b, n.e - n.s)) % mod;
    for(int i = 0; i < 2; i++)
    {
      if (n.son[i] != -1)
      {
        i64 a = (i ? Fnext(n.a, n.b, T[n.son[0]].e - n.s) : n.a);
        i64 b = (i ? Fnext(n.a, n.b, T[n.son[0]].e - n.s + 1) : n.b);
        T[n.son[i]].a = (T[n.son[i]].a + a) % mod;
        T[n.son[i]].b = (T[n.son[i]].b + b) % mod;
      }
    }
    n.a = n.b = 0;
  }

  i64 Query(int u, int le, int ri)
  {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri)
      return 0;

    PushLazy(u);
    if (n.s == le && n.e == ri)
      return n.sum;

    i64 res = 0;
    res += Query(n.son[0], le, min(T[n.son[0]].e, ri));
    res += Query(n.son[1], max(T[n.son[1]].s, le), ri);
    res %= mod;
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  fib[0] = 0, fib[1] = 1;
  for(int i = 2; i < (int)fib.size(); i++)
    fib[i] = (fib[i-1] + fib[i-2]) % mod;
  
  int n, m;
  while (cin >> n >> m)
  {
    vector<i64> A(n + 1);
    for(int i = 1; i <= n; i++)
    {
      int value;
      cin >> value;
      A[i] = (A[i-1] + value) % mod;
    }

    SegTree s(n + 1);
    while (m--)
    {
      int t, l, r;
      cin >> t >> l >> r;

      if (t == 1)
      {
        s.Update(0, l, r+1, 1, 1);
      }
      else
      {
        i64 ans = (A[r] - A[l-1] + s.Query(0, l, r+1)) % mod;
        if (ans < 0)
          ans += mod;
        cout << ans << '\n';
      }
    }
  }

  return 0;
}