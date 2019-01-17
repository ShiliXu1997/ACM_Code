#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

int n;
int a[MAXN];
int dp[MAXN][MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n-1;i++)dp[i][i+1]=0;
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<=j-1;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
        }
    printf("%d",dp[1][n]);
    return 0;
}
