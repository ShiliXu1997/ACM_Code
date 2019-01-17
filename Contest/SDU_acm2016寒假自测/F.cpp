#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=9300;
int dp[25][MAXN];
int pos[25],w[25];

int main()
{
    int C,G;
    scanf("%d %d",&C,&G);
    for(int i=1;i<=C;i++)
        scanf("%d",&pos[i]);
    for(int i=1;i<=G;i++)
        scanf("%d",&w[i]);
    memset(dp,0,sizeof(dp));
    dp[0][4650]=1;
    for(int i=1;i<=G;i++)
        for(int j=0;j<=MAXN;j++)
            if(dp[i-1][j]>0)
                for(int k=1;k<=C;k++)
                    dp[i][j+pos[k]*w[i]]+=dp[i-1][j];
    printf("%d",dp[G][4650]);
	return 0;
}
