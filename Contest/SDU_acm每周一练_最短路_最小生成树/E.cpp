#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=30,MAXM=100;

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

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int kruskal()
{
    sort(e,e+m);
    int ans=0,cnt=0;
    for(int i=0;i<n;i++)fa[i]=i;
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
    while(scanf("%d",&n)==1&&n!=0){
        m=0;
        for(int i=0;i<n-1;i++){
            char ch[5];
            int t,way;
            scanf("%s %d",&ch,&t);
            for(int j=1;j<=t;j++){
                scanf("%s %d",&ch,&way);
                e[m].from=i;
                e[m].to=ch[0]-'A';
                e[m].dist=way;
                m++;
            }
        }
        int ans=kruskal();
        printf("%d\n",ans);
    }
    return 0;
}
