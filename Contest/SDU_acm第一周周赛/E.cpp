#include<cstdio>
#include<cstring>
using namespace std;

const int MAXV=305,MAXP=35,INF=1e9;
int dist[MAXV][MAXV],dp[MAXP][MAXV];
int pos[MAXV];

int min(const int a,const int b)
{
    return (a<b?a:b);
}

int main()
{
    int v,p;
    while(scanf("%d %d",&v,&p)==2){
        for(int i=1;i<=v;i++)
            scanf("%d",&pos[i]);
        for(int i=1;i<=v;i++)
            dist[i][i]=0;
        for(int i=1;i<v;i++)
            for(int j=i+1;j<=v;j++)
                dist[i][j]=dist[i][j-1]+pos[j]-pos[(i+j)/2];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=p;i++)
            for(int j=i;j<=v;j++)
                if(i==1)
                    dp[i][j]=dist[1][j];
                else{
                    dp[i][j]=INF;
                    for(int k=i-1;k<j;k++)
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+dist[k+1][j]);
                }
        printf("%d\n",dp[p][v]);
    }
	return 0;
}
