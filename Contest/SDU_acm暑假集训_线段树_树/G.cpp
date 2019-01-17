#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=10005;

struct edge{
    int to,next;
};

int t,n,cnt,p1,p2;
int fa[MAXN],head[MAXN];
bool visited[MAXN];
edge e[MAXN];

void addedge(int from,int to)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
    fa[to]=from;
}

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

void dfs(int f,int u)
{
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        dfs(u,v);
    }
    if(u==p1&&visited[p2]){
        printf("%d\n",findfather(p2));
        return;
    }
    if(u==p2&&visited[p1]){
        printf("%d\n",findfather(p1));
        return;
    }
    visited[u]=true;
    fa[u]=f;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)fa[i]=i;
        cnt=0;
        memset(visited,false,sizeof(visited));
        memset(head,0,sizeof(head));
        int a,b;
        for(int i=1;i<=n-1;i++){
            scanf("%d %d",&a,&b);
            addedge(a,b);
        }
        scanf("%d %d",&p1,&p2);
        int root;
        for(int i=1;i<=n;i++)
            if(fa[i]==i){
                root=i;
                break;
            }
        for(int i=1;i<=n;i++)fa[i]=i;
        dfs(0,root);
    }
    return 0;
}
