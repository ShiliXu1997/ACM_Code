#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105,MAXM=5005;

struct edge{
    int from,to;
    int dist;
    bool operator<(const edge &another)const
    {
        return dist<another.dist;
    }
};

int t,n,m,ans,sum;
int fa[MAXN];
edge e[MAXM];
bool used[MAXM];

void init()
{
    for(int i=1;i<=n;i++)fa[i]=i;
}

int findfather(const int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

bool kruskal(const int num)
{
    init();
    int cnt=0;
    sum=0;
    if(num==0){
        for(int i=1;i<=m;i++){
            int p,q;
            p=findfather(e[i].from);
            q=findfather(e[i].to);
            if(p!=q){
                fa[q]=p;
                used[i]=true;
                cnt++;
                sum+=e[i].dist;
                if(cnt==n-1)break;
            }
        }
    }
    else{
        for(int i=1;i<=m;i++)
            if(i!=num){
                int p,q;
                p=findfather(e[i].from);
                q=findfather(e[i].to);
                if(p!=q){
                    fa[q]=p;
                    cnt++;
                    sum+=e[i].dist;
                    if(cnt==n-1)break;
                }
            }
    }
    return (cnt==n-1);
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].dist);
        sort(e+1,e+1+m);
        memset(used,false,sizeof(used));
        if(kruskal(0))ans=sum;
        bool flag=true;
        for(int i=1;i<=m;i++)
            if(used[i]){
                if(kruskal(i)&&sum==ans){
                    flag=false;
                    break;
                }
            }
        if(flag)
            printf("%d\n",ans);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
