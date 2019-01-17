#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=105,MAXM=5000,INF=0x3f3f3f3f;

struct edge{
    int from,to;
    int dist;
    bool operator < (const edge &another)const{
        return dist<another.dist;
    }
};

int n,m;
int fa[MAXN];
edge e[MAXM];

int min(const int a,const int b)
{
    return (a<b?a:b);
}

int max(const int a,const int b)
{
    return (a>b?a:b);
}

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int kruskal(int st)
{
    int ans=0,cnt=0,maxe=0,mine=INF;
    bool flag=false;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=st;i<=m;i++){
        int p,q;
        p=findfather(e[i].from);
        q=findfather(e[i].to);
        if(p!=q){
            fa[q]=p;
            maxe=max(maxe,e[i].dist);
            mine=min(mine,e[i].dist);
            cnt++;
        }
        if(cnt==n-1){
            flag=true;
            break;
        }
    }
    if(flag)
        ans=maxe-mine;
    else
        ans=-1;
    return ans;
}

int main()
{
    while(scanf("%d %d",&n,&m)==2&&(n!=0||m!=0)){
        for(int i=1;i<=m;i++)
            scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].dist);
        sort(e+1,e+1+m);
        int ans=INF;
        for(int i=1;i<=m-n+2;i++){
            int sum=kruskal(i);
            if(sum!=-1)ans=min(ans,sum);
        }
        if(ans!=INF)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
