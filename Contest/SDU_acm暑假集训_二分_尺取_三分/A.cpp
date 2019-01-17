#include<cstdio>
#include<cmath>
using namespace std;

const double EPS=1e-8;

int t;
double y,ans;

bool func(double x)
{
    double sum=8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
    if(sum-y>=EPS)
        return false;
    else
        return true;
}

bool binsearch(const double left,const double right)
{
    double l=left,r=right;
    for(int i=1;i<=120;i++){
        double mid=(l+r)/2;
        if(func(mid))
            l=mid;
        else
            r=mid;
    }
    if(fabs(l)<=EPS||fabs(l-right)<EPS)
        return false;
    else{
        ans=l;
        return true;
    }
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&y);
        if(binsearch(0,100))
            printf("%.4f\n",ans);
        else
            printf("No solution!\n");
    }
    return 0;
}
