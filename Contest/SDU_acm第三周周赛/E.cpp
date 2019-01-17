#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e5+100;

int n;
long long t,maximum;
long long a[MAXN],dp[MAXN];

long long max(const long long x,const long long y)
{
    return (x>y?x:y);
}

int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    maximum=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&t);
        maximum=max(maximum,t);
        a[t]++;
    }
    dp[1]=a[1];
    for(int i=2;i<=maximum;i++)
        dp[i]=max(dp[i-1],dp[i-2]+a[i]*i);
    printf("%lld\n",dp[maximum]);
	return 0;
}
