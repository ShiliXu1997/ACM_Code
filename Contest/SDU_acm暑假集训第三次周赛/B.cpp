#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105,INF=0x3f3f3f3f;

char s[MAXN],t[MAXN];
int dp[MAXN][MAXN];
int ans[MAXN];

int main()
{
    while(scanf("%s %s",s,t)==2){
        memset(dp,0x3f,sizeof(dp));
        int n=strlen(t);
        for(int i=0;i<=n-1;i++){
            dp[i][i]=1;
            dp[i+1][i]=0;
        }
        for(int i=n-2;i>=0;i--)
            for(int j=i+1;j<=n-1;j++){
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++)
                    if(t[i]==t[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
            }
        for(int i=0;i<=n-1;i++){
            ans[i]=dp[0][i];
            if(s[i]==t[i]){
                if(i==0)
                    ans[i]=0;
                else
                    ans[i]=ans[i-1];
            }
            for(int j=0;j<i;j++)
                ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
        }
        printf("%d\n",ans[n-1]);
    }
    return 0;
}
