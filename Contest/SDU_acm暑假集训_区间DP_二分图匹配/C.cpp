#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105,INF=0x3f3f3f3f;

int t,n;
int a[MAXN];
int dp[MAXN][MAXN];

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i>j)
                    dp[i][j]=0;
                else
                    dp[i][j]=INF;
        for(int i=n;i>=1;i--)
            for(int j=i;j<=n;j++)
                if(i==j)
                    dp[i][j]=1;
                else{
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                    for(int k=i;k<=j-1;k++)
                        if(a[k]==a[j])
                            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);

                }
        printf("Case %d: %d\n",kase,dp[1][n]);
    }
    return 0;
}
