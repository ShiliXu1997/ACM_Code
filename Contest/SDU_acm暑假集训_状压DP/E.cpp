#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=12,INF=0x3f3f3f3f;

int n,m;
int bit[MAXN];
int path[MAXN][MAXN],num[60000][MAXN],dp[60000][MAXN];

void init()
{
    bit[1]=1;
    for(int i=2;i<=11;i++)
        bit[i]=3*bit[i-1];
    for(int i=0;i<bit[11];i++){
        int x=i;
        for(int j=1;j<=10;j++){
            num[i][j]=x%3;
            x/=3;
        }
    }
}

int main()
{
    init();
    while(scanf("%d %d",&n,&m)==2){
        memset(path,0x3f,sizeof(path));
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[bit[i]][i]=0;
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            path[a][b]=min(path[a][b],c);
            path[b][a]=path[a][b];
        }
        int ans=INF;
        for(int i=0;i<bit[n+1];i++){
            bool flag=true;
            for(int j=1;j<=n;j++){
                if(num[i][j]==0)flag=false;
                if(dp[i][j]==INF)continue;
                for(int l=1;l<=n;l++){
                    if(l==j||num[i][l]>=2||path[j][l]==INF)continue;
                    dp[i+bit[l]][l]=min(dp[i+bit[l]][l],dp[i][j]+path[j][l]);
                }
            }
            if(flag){
                for(int j=1;j<=n;j++)
                    ans=min(ans,dp[i][j]);
            }
        }
        if(ans==INF)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
