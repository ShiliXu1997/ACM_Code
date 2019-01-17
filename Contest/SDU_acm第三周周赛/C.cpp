#define LOCAL
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=755,MAXM=2.9e5,INF=0x3f3f3f3f,EPS=1e-7;

struct edge{
    int from,to;
    double dist;
    bool operator < (const edge &another)const{
        return dist<another.dist+EPS;
    }
};

int n,m,cnt;
int x[MAXN],y[MAXN];
edge e[MAXM];
int fa[MAXM];

double caldist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
//    freopen("output","w",stdout);
#endif
    while(scanf("%d",&n)==1){
        cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&x[i],&y[i]);
            for(int j=1;j<i;j++){
                e[++cnt].from=j;
                e[cnt].to=i;
                e[cnt].dist=caldist(i,j);
            }
        }
        for(int i=1;i<=n;i++)fa[i]=i;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int a,b,p,q;
            scanf("%d %d",&a,&b);
            p=findfather(a);q=findfather(b);
            if(p!=q)fa[q]=p;
        }
        sort(e+1,e+1+cnt);
        double ans=0;
        for(int i=1;i<=cnt;i++){
            int p,q;
            p=findfather(e[i].from);
            q=findfather(e[i].to);
            if(p!=q){
                fa[q]=p;
                ans+=e[i].dist;
            }
        }
        printf("%.2f\n",ans);
    }
	return 0;
}
