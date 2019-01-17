#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105,MAXM=15;

int n,m,cnt;
int graph[MAXN],state[1030],num[1030];
int dp[MAXN][1030][1030];
char s[MAXM];

bool check(int x)
{
    return !((x>>1&x)||(x>>2&x));
}

bool ok(int a,int b)
{
    return !(a&b);
}

void init()
{
    memset(graph,0,sizeof(graph));
    memset(num,0,sizeof(num));
    cnt=0;
    for(int i=0;i<1<<m;i++)
        if(check(i)){
            state[++cnt]=i;
            for(int j=0;j<m;j++)
                if((i>>j)&1)num[cnt]++;
        }
}

int main()
{
    scanf("%d %d",&n,&m);
    init();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=0;j<m;j++)
            if(s[j]=='P')graph[i]=graph[i]^(1<<(m-j-1));
    }
    for(int i=1;i<=cnt;i++)
        if((graph[1]&state[i])==state[i])
            for(int j=1;j<=cnt;j++)
                dp[1][i][j]=num[i];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=cnt;j++)
            if((graph[i]&state[j])==state[j])
                for(int k=1;k<=cnt;k++)
                    if(ok(state[j],state[k])){
                        for(int l=1;l<=cnt;l++)
                            if(ok(state[j],state[l]))
                                dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+num[j]);
                    }
    int ans=0;
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            ans=max(ans,dp[n][i][j]);
    printf("%d\n",ans);
    return 0;
}
