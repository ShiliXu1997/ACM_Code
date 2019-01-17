#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1050,MAXM=500000,INF=0x3f3f3f3f;

struct edge{
    int from,to;
    int dist;
    bool operator < (const edge &another)const{
        return dist<another.dist;
    }
};

int path[MAXN][MAXN];
int ada[MAXN],fa[MAXN];
int n,m;
edge e[MAXM];

int min(const int a,const int b)
{
    return (a<b?a:b);
}

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int kruskal()
{
    sort(e,e+m);
    for(int i=1;i<=n;i++)fa[i]=i;
    int ans=0,cnt=0;
    for(int i=0;i<m;i++){
        int p=findfather(e[i].from);
        int q=findfather(e[i].to);
        if(p!=q){
            fa[q]=p;
            ans+=e[i].dist;
            cnt++;
            if(cnt==n-1)break;
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        m=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&ada[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&path[i][j]);
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++){
                int d=min(path[i][j],path[j][i]);
                e[m].dist=d+ada[i]+ada[j];
                e[m].from=i;
                e[m].to=j;
                m++;
            }
        int ans=kruskal();
        printf("%d\n",ans);
    }
    return 0;
}
