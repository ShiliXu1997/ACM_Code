#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=55,INF=0x3f3f3f3f;

int l,n;
int pos[MAXN];
int dp[MAXN][MAXN];

int main()
{
    while(scanf("%d",&l)==1&&l!=0){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&pos[i]);
        pos[0]=0;pos[n+1]=l;
        memset(dp,0x3f,sizeof(dp));
        for(int i=n;i>=0;i--)
            for(int j=i+1;j<=n+1;j++){
                if(i+1==j)
                    dp[i][j]=0;
                else{
                    int len=pos[j]-pos[i];
                    for(int k=i+1;k<=j-1;k++)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+len);
                }
            }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);
    }
    return 0;
}
