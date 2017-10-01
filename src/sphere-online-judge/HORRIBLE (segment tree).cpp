#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class TreeNode
{
public:
  TreeNode() : val(0), add(0), leaf(false) { }
  long long val, add;
  bool leaf;
};

class SegmentTree
{
public:
  SegmentTree() {}

  SegmentTree(int n)
  {
    Init(n);
  }

  SegmentTree(const vector<int> &arr)
  {
    Init(arr);
  }

  void Init(int n)
  {
    this->N = n;
    this->T.assign(4*N+5, TreeNode());
    vector<int> a(N, 0);
    Init(0, N-1, 0, a);
  }
  
  void Init(const vector<int> &arr)
  {
    this->N = arr.size();
    this->T.assign(4*N+5, TreeNode());
    Init(0, N-1, 0, arr);
  }

  void UpdateRange(int i, int j, int delta)
  {
    UpdateRange(0, N-1, 0, i, j, delta);
  }

  TreeNode Query(int i, int j)
  {
    return Query(0, N-1, 0, i, j);
  }
  
private:
  vector<TreeNode> T;
  int N;

  void Init(int b, int e, int node, const vector<int> &a)
  {
      if(b == e)
      {
        T[node].val = a[b];
        T[node].leaf = true;
      }
      else
      {
          int mid = (b + e)/2, le = 2*node+1, ri = 2*node+2;
          Init(b, mid, le, a);
          Init(mid+1, e, ri, a);
          T[node].val = T[le].val + T[ri].val;
      }
  }

  void UpdateRange(int b, int e, int node, int i, int j, int delta)
  {
    if (j < b || i > e)
      return;

    // cout << b << " " << e << " " << node << " " << i << " " << j <<
    //   " " << delta << endl;

    if (i <= b && e <= j)
    {
      if (T[node].leaf == false)
        T[node].add += delta;
      T[node].val += (long long )(e-b+1) * delta;
      return;
    }
    
    PushLazy(node, b, e);
    int mid = (b + e)/2, le = 2*node+1, ri = 2*node+2;
    UpdateRange(b,     mid, le, i, j, delta);
    UpdateRange(mid + 1, e, ri, i, j, delta);
    T[node].val = T[le].val + T[ri].val;
  }

  TreeNode Query(int b, int e, int node, int i, int j)
  {
      // cout << "Q: " << b << " " << e << " " << node << " "
      //   << i << " " << j << endl;

      if(i <= b && e <= j)
        return T[node];
      
      PushLazy(node, b, e);
      int mid = (b + e) / 2, le = 2*node + 1, ri = 2*node + 2;
      TreeNode ret;
      
      if(j <= mid)
        ret = Query(b, mid, le, i, j);
      else if(mid < i)
        ret = Query(mid + 1, e, ri, i, j);
      else
      {
          TreeNode ret1, ret2;
          ret1 = Query(b, mid, le, i, j);
          ret2 = Query(mid + 1, e, ri, i, j);
          ret.val = ret1.val + ret2.val;
      }
      return ret;
  }

  void PushLazy(int node, int b, int e)
  {
    if (T[node].add == 0)
      return;

    int mid = (b + e)/2;
    int son[2] = {2*node+1, 2*node+2};

    T[son[0]].val += T[node].add * (mid - b + 1);
    if (T[son[0]].leaf == false)
      T[son[0]].add += T[node].add;

    T[son[1]].val += T[node].add * (e - mid);
    if (T[son[1]].leaf == false)
      T[son[1]].add += T[node].add;

    T[node].add = 0;
  }
};


int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, c;
    cin >> n >> c;
    SegmentTree s(n + 1);
    while (c--)
    {
      int kind, p, q;
      cin >> kind >> p >> q;
      if (kind == 0)
      {
        int value;
        cin >> value;
        s.UpdateRange(p, q, value);
      }
      else
      {
        cout << s.Query(p, q).val << endl;
      }
    }
  }
  
  return 0;
}

