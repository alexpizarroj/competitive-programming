#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)

int card_used[100005];
bool makeable[100005];

int main()
{
    int cards[105], sol[105], n, m, actualw, idealw, wanted;
    bool used[105];
    
    while ( ~scanf("%d", &actualw) )
    {
        scanf("%d", &n);
        idealw = 0;
        fupi(i,1,n) scanf("%d", cards+i), idealw += cards[i];
        wanted = idealw - actualw;
        
        // Solve for basic solution
        memset(card_used, -1, sizeof card_used), card_used[0] = 0;
        fupi(c,1,n) for(int i = wanted; i >= cards[c]; --i)
        {
            if ( card_used[i-cards[c]]!=-1 && card_used[i]==-1 ) card_used[i]=c;
        }
        
        if ( card_used[wanted] != -1 )
        {
            bool uniq = true;
           
            // Construct basic solution and mark used cards
            m = 0;
            memset(used, 0, sizeof used);
            while ( card_used[wanted] != 0 )
            {
                int c = card_used[wanted];
                sol[m++] = c, used[c] = true, wanted -= cards[c];
            }
            sort(sol, sol+m);
            
            // Determine reachable combinations WITHOUT using solution cards
            memset(makeable, 0, sizeof makeable);
            wanted = idealw - actualw, makeable[0] = true;
            fupi(c,1,n) if ( !used[c] ) for(int i = wanted; i >= cards[c]; --i)
            {
                if ( makeable[i-cards[c]] ) makeable[i] = true;
            }
            
            // Determine solution uniqueness
            int sum = 0;
            fup(i,0,m)
            {
                sum += cards[sol[i]];
                if ( makeable[ cards[sol[i]] ] || makeable[sum] )
                {
                    puts("-1");
                    uniq = false;
                    break;
                }
            }
            
            // Print solution, if unique
            if ( uniq ) 
            {
                fup(i,0,m) 
                {
                    if ( i > 0 ) printf(" ");
                    printf("%d", sol[i]);
                }
                puts("");
            }
        } else puts("0");
    }
    
    return 0;
}
