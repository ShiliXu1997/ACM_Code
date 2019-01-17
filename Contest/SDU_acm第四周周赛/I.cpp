#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=10010;

int n;
double x[MAXN],y[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double total=0;
        scanf("%lf %lf",&x[1],&y[1]);
        for(int i=2;i<=n;i++){
            scanf("%lf %lf",&x[i],&y[i]);
            total+=(x[i-1]*y[i]-x[i]*y[i-1]);
        }
        total+=(x[n]*y[1]-x[1]*y[n]);
        total/=2;
        total=fabs(total);
        printf("%.2f\n",total);
    }
    return 0;
}
