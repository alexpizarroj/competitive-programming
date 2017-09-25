#include <iostream>
#include <cstring>
using namespace std;
int dp[1000010];
int cnt[1000010];
int solve(int u){
    int &ans=dp[u];
    if(ans!=-1)return ans;
    ans=1;
    //cerr<<u<<" mi number "<<endl;
    int cpy=u;
    int op=0;
    while(cpy<1000000){
        cpy+=u;
        if(cpy>=1000010)break;
        if(!cnt[cpy])continue;
       // cerr<<"le cpy "<<cpy<<endl;
        op=max(op,solve(cpy));

    }
  //  cerr<<"para "<<u<<" "<<ans<<" "<<op<<endl;
    ans+=op;
   // cerr<<ans<<endl;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0,u;i<n;i++){
        cin>>u;
        cnt[u]++;
    }
    int ans=0;
    for(int i=2;i<1000010;i++){
        if(cnt[i]){ans=max(ans,solve(i));}
    }
  //  for(int i=2;i<=24;i++)cout<<dp[i]<<" ";
   // cout<<endl;
    cout<<ans+cnt[1];
    return 0;
}
