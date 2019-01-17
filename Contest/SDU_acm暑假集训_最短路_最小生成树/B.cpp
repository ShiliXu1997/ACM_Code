#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=1000,MAXM=50000;
const double EPS=1e-8;

struct edge{
    int from,to;
    double dist;
    bool operator<(const edge &another)const
    {
        return dist<another.dist;
    }
};

int t,n,m;
double x[MAXN],y[MAXN];
int fa[MAXN];
edge e[MAXM];

int findfather(const int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

double caldist(const int i,const int j)
{
    double ans=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    return ans;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==0)
            printf("oh!\n");
        else{
            m=0;
            scanf("%lf %lf",&x[1],&y[1]);
            for(int i=2;i<=n;i++){
                scanf("%lf %lf",&x[i],&y[i]);
                for(int j=1;j<i;j++){
                    double d=caldist(i,j);
                    if(d-10.0>-EPS&&d-1000.0<EPS){
                        e[++m].from=j;
                        e[m].to=i;
                        e[m].dist=d;
                    }
                }
            }
            sort(e+1,e+1+m);
            for(int i=1;i<=m;i++)fa[i]=i;
            int cnt=0;
            double ans=0;
            for(int i=1;i<=m;i++){
                int p,q;
                p=findfather(e[i].from);
                q=findfather(e[i].to);
                if(p!=q){
                    fa[q]=p;
                    ans=ans+e[i].dist;
                    cnt++;
                    if(cnt==n-1)break;
                }
            }
            if(cnt==n-1)
                printf("%.1f\n",ans*100);
            else
                printf("oh!\n");
        }
    }
    return 0;
}
