#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double EPS=1e-8;

int t;
double n,r,p;

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%lf %lf %lf",&n,&r,&p);
        if(n-p>=-EPS){
            printf("Case %d: %d\n",kase,0);
            continue;
        }
        double x=log(p/n)/log((1.0+r/100));
        int ans=ceil(x);
        if(-EPS<=x-(int)x&&x-(int)x<=EPS)ans=int(x);
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
