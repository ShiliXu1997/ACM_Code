#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=15,MAXM=4100,MOD=1e8;

int n,m,cnt;
int graph[MAXN],state[MAXM];
int dp[MAXN][MAXM];

bool check(int x)
{
    return !(x>>1&x);
}

bool ok(int a,int b)
{
    return !(a&b);
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(graph,0,sizeof(graph));
    memset(state,0,sizeof(state));
    cnt=0;
    for(int i=0;i<(1<<n);i++)
        if(check(i))state[++cnt]=i;
}

int main()
{
    scanf("%d %d",&m,&n);
    init();
    for(int i=1;i<=m;i++){
        int x;
        for(int j=1;j<=n;j++){
            scanf("%d",&x);
            if(x==1)graph[i]+=1<<(n-j);
        }
    }
    for(int i=1;i<=cnt;i++)
        if((graph[1]&state[i])==state[i])
            dp[1][i]=1;
    for(int i=2;i<=m;i++)
        for(int j=1;j<=cnt;j++)
            if((graph[i]&state[j])==state[j])
                for(int k=1;k<=cnt;k++)
                    if(ok(state[j],state[k])&&(graph[i-1]&state[k])==state[k])
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
    int ans=0;
    for(int i=1;i<=cnt;i++)
        ans=(ans+dp[m][i])%MOD;
    printf("%d\n",ans);
    return 0;
}
