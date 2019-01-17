#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=200005;

struct edge{
    int to,next;
};

int n,cnt;
int a[MAXN],head[MAXN],ans[MAXN];
edge e[MAXN*2];

void addedge(int from,int to)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
}

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

void dfs(int fa,int u,int d,bool mes)
{
    int p,q;
    p=gcd(d,a[u]);
    ans[u]=max(ans[u],p);
    if(!mes){
        q=gcd(d,0);
        ans[u]=max(ans[u],q);
    }
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        if(v==fa)continue;
        if(!mes){
            dfs(u,v,p,false);
            if(p!=d)dfs(u,v,q,true);
        }
        else
            dfs(u,v,p,true);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    cnt=0;
    for(int i=1;i<=n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    memset(ans,0,sizeof(ans));
    dfs(0,1,0,false);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
