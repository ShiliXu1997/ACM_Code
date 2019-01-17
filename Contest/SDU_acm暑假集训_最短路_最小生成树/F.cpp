#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN=1e5+5,MAXM=2e6+5;

struct edge{
    int from,to;
    int dist;
    int next;
};

int n,m,cnt;
int fa[MAXN],dist[MAXN],head[MAXN];
bool visited[MAXN];
edge e[MAXM];
queue<int> q;

int findfather(const int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

void addedge(int from,int to,int dist)
{
    cnt++;
    e[cnt].from=from;
    e[cnt].to=to;
    e[cnt].dist=dist;
    e[cnt].next=head[from];
    head[from]=cnt;
}

void bfs(int x)
{
    memset(dist,0,sizeof(dist));
    memset(visited,false,sizeof(visited));
    dist[x]=0;visited[x]=true;
    q.push(x);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].next){
            if(!visited[e[i].to]){
                if(dist[e[i].to]<dist[u]+e[i].dist)
                    dist[e[i].to]=dist[u]+e[i].dist;
                q.push(e[i].to);
                visited[e[i].to]=true;
            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&n,&m)==2){
        memset(head,0,sizeof(head));
        for(int i=1;i<=n;i++)fa[i]=i;
        cnt=0;
        bool flag=true;
        for(int i=1;i<=m;i++){
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            if(m>=n)
                flag=false;
            else{
                addedge(a,b,w);
                addedge(b,a,w);
                int p,q;
                p=findfather(a);
                q=findfather(b);
                if(p!=q)
                    fa[q]=p;
                else
                    flag=false;
            }
        }
        if(!flag)
            printf("YES\n");
        else{
            int ans,farthest;
            for(int i=1;i<=n;i++)
                if(fa[i]==i){
                    ans=0;
                    bfs(i);
                    for(int j=1;j<=n;j++)
                        if(dist[j]>ans){
                            ans=dist[j];
                            farthest=j;
                        }
                    bfs(farthest);
                    ans=0;
                    for(int j=1;j<=n;j++)
                        ans=max(ans,dist[j]);
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}
