#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=600,INF=0x3f3f3f3f;

int n;
int a[MAXN];
int dp[MAXN][MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)dp[i][i]=1;
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++){
            int mintime=INF;
            for(int k=i;k<j;k++)
                mintime=min(mintime,dp[i][k]+dp[k+1][j]);
            if(a[i]==a[j]){
                mintime=min(mintime,dp[i+1][j-1]);
                if(i+1==j)mintime=1;
            }
            dp[i][j]=min(dp[i][j],mintime);
        }
    printf("%d",dp[1][n]);
    return 0;
}
