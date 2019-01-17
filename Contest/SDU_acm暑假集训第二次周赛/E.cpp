#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=10002;

int n,k;
int a[MAXN];
bool dp[MAXN][202];

int main()
{
    memset(dp,false,sizeof(dp));
    scanf("%d %d",&n,&k);
    dp[0][k]=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<=2*k-1;j++)
            if(i==1&&dp[i-1][(j-k-a[i])%k+k])
                dp[i][j]=true;
            else
            if(dp[i-1][(j-k+a[i])%k+k]||dp[i-1][(j-k-a[i])%k+k])
                dp[i][j]=true;
    }
    if(dp[n][k])
        printf("Divisible");
    else
        printf("Not divisible");
}
