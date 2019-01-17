#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=60010;
const double EPS=1e-8,INF=0x3f3f3f3f;

int n;
int x[MAXN],v[MAXN];
double y,ans;

bool func(double time)
{
    double ll,rr,radius=time*v[1];
    ll=x[1]-radius;
    rr=x[1]+radius;
    for(int i=2;i<=n;i++){
        double left,right,radius=time*v[i];
        left=x[i]-radius;
        right=x[i]+radius;
        ll=max(ll,left);
        rr=min(rr,right);
        if(rr-ll<EPS)return false;
    }
    return true;
}

double binsearch(const double left,const double right)
{
    double l=left,r=right;
    for(int i=1;i<=200&&r-l>EPS;i++){
        double mid=(l+r)/2;
        if(!func(mid))
            l=mid;
        else
            r=mid;
    }
    return l;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("%f",binsearch(0,INF));
    return 0;
}
