#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=102,MAXM=5000;

struct edge{
    int from,to;
    int dist;
    bool operator<(const edge &another)const
    {
        return dist<another.dist;
    }
};

int n,m,ans;
int fa[MAXN];
edge e[MAXM];

int findfather(const int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int main()
{
    while(scanf("%d %d",&m,&n)==2&&m!=0){
        for(int i=1;i<=m;i++)
            scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].dist);
        sort(e+1,e+1+m);
        ans=0;
        int cnt=0;
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=m;i++){
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
            printf("%d\n",ans);
        else
            printf("?\n");
    }
    return 0;
}
