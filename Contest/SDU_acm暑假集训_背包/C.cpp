#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

int n;
int a[MAXN];
int dp[MAXN][3];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    if(a[1]==0){
        dp[1][0]=0;
        dp[1][1]=0;
        dp[1][2]=0;
    }
    if(a[1]==1){
        dp[1][0]=0;
        dp[1][1]=0;
        dp[1][2]=1;
    }
    if(a[1]==2){
        dp[1][0]=0;
        dp[1][1]=1;
        dp[1][2]=0;
    }
    if(a[1]==3){
        dp[1][0]=0;
        dp[1][1]=1;
        dp[1][2]=1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==0){
            dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
            dp[i][1]=dp[i][0];
            dp[i][2]=dp[i][0];
        }
        if(a[i]==1){
            dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
            dp[i][1]=dp[i][0];
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
        }
        if(a[i]==2){
            dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=dp[i][0];
        }
        if(a[i]==3){
            dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
        }
    }
    printf("%d",n-max(max(dp[n][0],dp[n][1]),dp[n][2]));
    return 0;
}
