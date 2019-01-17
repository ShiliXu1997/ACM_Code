#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=110,MAXM=6000,INF=0x3f3f3f3f;

struct edge{
    int from,to;
    int cost;
    bool operator < (const edge &another)const{
        return cost<another.cost;
    }
};

int n,m;
int fa[MAXN],visited[MAXM];
edge e[MAXM];

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int min(const int a,const int b)
{
    return (a<b?a:b);
}

int kruskal()
{
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int p,q;
        p=findfather(e[i].from);
        q=findfather(e[i].to);
        if(p!=q){
            fa[q]=p;
            ans+=e[i].cost;
            visited[++cnt]=i;
        }
        if(cnt==n-1)break;
    }
    return ans;
}

int sectree()
{
    int ans=INF,cnt,sum;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++)fa[j]=j;
        cnt=0;sum=0;
        for(int j=1;j<=m;j++)
            if(j!=visited[i]){
                int p,q;
                p=findfather(e[j].from);
                q=findfather(e[j].to);
                if(p!=q){
                    fa[q]=p;
                    sum+=e[j].cost;
                    cnt++;
                }
                if(cnt==n-1){
                    ans=min(ans,sum);
                    break;
                }
            }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].cost);
        sort(e+1,e+1+m);
        int firmintree,secmintree;
        firmintree=kruskal();
        secmintree=sectree();
        printf("%d %d\n",firmintree,secmintree);
    }
    return 0;
}
