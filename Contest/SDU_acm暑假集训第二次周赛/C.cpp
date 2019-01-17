#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105,MAXM=5000,INF=0x3f3f3f3f;

struct edge{
    int from,to;
    int dist;
    bool operator<(const edge &another)const
    {
        return dist<another.dist;
    }
};

int t,n,m;
int fa[MAXN];
edge e[MAXM];
bool used[MAXM];

void init()
{
    for(int i=1;i<=n;i++)fa[i]=i;
}

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int kruskal(int x)
{
    int cnt=0,ans=0;
    if(x==0){
        init();
        memset(used,false,sizeof(used));
        for(int i=1;i<=m;i++){
            int p,q;
            p=findfather(e[i].from);
            q=findfather(e[i].to);
            if(p!=q){
                fa[q]=p;
                ans+=e[i].dist;
                used[i]=true;
                cnt++;
                if(cnt==n-1)break;
            }
        }
        return ans;
    }
    else{
        init();
        for(int i=1;i<=m;i++){
            if(i==x)continue;
            int p,q;
            p=findfather(e[i].from);
            q=findfather(e[i].to);
            if(p!=q){
                fa[q]=p;
                ans+=e[i].dist;
                cnt++;
                if(cnt==n-1)break;
            }
        }
        if(cnt==n-1)
            return ans;
        else
            return INF;
    }
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].dist);
        sort(e+1,e+1+m);
        int min1=kruskal(0),min2=INF;
        for(int i=1;i<=m;i++)
            if(used[i])min2=min(min2,kruskal(i));
        printf("%d %d\n",min1,min2);
    }
    return 0;
}
