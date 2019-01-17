#include<cstdio>
#include<cstring>
using namespace std;

int c,g;
int position[25],weight[25];
int dp[25][15005];

int main()
{
    scanf("%d %d",&c,&g);
    for(int i=1;i<=c;i++)
        scanf("%d",&position[i]);
    for(int i=1;i<=g;i++)
        scanf("%d",&weight[i]);
    memset(dp,0,sizeof(dp));
    dp[0][7500]=1;
    for(int i=1;i<=g;i++)
        for(int j=0;j<=15000;j++)
            for(int k=1;k<=c;k++)
                if(dp[i-1][j]>0)dp[i][j+position[k]*weight[i]]+=dp[i-1][j];
    printf("%d",dp[g][7500]);
    return 0;
}
