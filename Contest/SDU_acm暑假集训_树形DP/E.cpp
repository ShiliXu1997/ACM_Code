#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5,MAXM=1e6+5;
const long long INF=0x7fffffffffffffff;

struct edge{
    int to;
    int next;
};

int kase,n,m,cnt;
int head[MAXN];
bool visited[MAXN];
long long num[MAXN];
long long tot,ans;
edge e[MAXN*2];

void addedge(int from,int to)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
}

long long dfs(int u)
{
    visited[u]=true;
    long long sum=num[u];
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        if(visited[v])continue;
        long long num=dfs(v);
        sum+=num;
    }
    long long diff=sum-(tot-sum);
    if(diff<0)diff=-diff;
    ans=min(ans,diff);
    return sum;
}

int main()
{
    kase=0;
    while(scanf("%d %d",&n,&m)==2&&n!=0&&m!=0){
        cnt=0,tot=0;
        memset(head,0,sizeof(head));
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++){
            scanf("%lld",&num[i]);
            tot+=num[i];
        }
        for(int i=1;i<=m;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            addedge(from,to);
            addedge(to,from);
        }
        ans=INF;
        dfs(1);
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
