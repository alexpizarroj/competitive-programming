#include <cstdio>
#include <cstring>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)

const int cstMax = 3*100000+100;
int parent[cstMax], label[cstMax];

int find(int u)
{
    if ( parent[u] != u ) parent[u] = find(parent[u]);
    return parent[u];
}

int main()
{
    int n, m, l, r, x, u;
    
    while ( ~scanf("%d %d", &n, &m) )
    {
        fupi(i, 1, n+1) parent[i] = i;
        memset(label, 0, sizeof label);
        while ( m-- )
        {
            scanf("%d %d %d", &l, &r, &x);
            u = find(l);
            while ( u < x )
            {
                label[u] = x;
                parent[u] = u+1;
                u = find(u);
            }
            u = find(x + 1);
            while ( u <= r )
            {
                label[u] = x;
                parent[u] = u+1;
                u = find(u);
            }
        }
        
        printf("%d", label[1]);
        fupi(i, 2, n) printf(" %d", label[i]);
        puts("");
    }
    
    return 0;
}
