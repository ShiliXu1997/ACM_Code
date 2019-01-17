#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=10010;
const double EPS=1e-9;

int n,k;
double l[MAXN];

bool func(double x)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=(int)(l[i]/x);
    return (sum>=k);
}

double binsearch(const double left,const double right)
{
    double l=left,r=right;
    while(fabs(r-l)>EPS){
        double mid=(l+r)/2;
        if(func(mid))
            l=mid;
        else
            r=mid;
    }
    return r;
}

int main()
{
    double sum=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&l[i]);
        sum+=l[i];
    }
    double ans=binsearch(0,sum/k);
    printf("%.2f\n",(double)floor(ans*100)/100);
    return 0;
}
