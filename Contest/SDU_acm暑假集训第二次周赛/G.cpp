#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=2005;

int n;
int v[MAXN];
long long dp[MAXN][MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(j+i-n>=1)dp[i][j]=max(dp[i][j],dp[i-1][j]+v[j+i-n]*i);
            if(j+1<=n)dp[i][j]=max(dp[i][j],dp[i-1][j+1]+v[j+1]*i);
        }
    long long ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dp[n][i]);
    printf("%lld",ans);
    return 0;
}
