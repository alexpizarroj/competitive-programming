// SillyHook01

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
const int N=1000005;
int c[N][26]; char a[N],b[N];
long long n,m,L,ans;
int main()
{
	scanf("%I64d%I64d%s%s",&n,&m,&a,&b);
	int A=strlen(a),B=strlen(b),G=__gcd(A,B); L=1LL*A*B/G;
	rep(i,A) ++c[i%G][a[i]-97];
	rep(i,B) ans+=c[i%G][b[i]-97];
	printf("%I64d\n",n*A-ans*(n*A/L));
	return 0;
}