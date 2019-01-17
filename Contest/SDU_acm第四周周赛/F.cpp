#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=1010;

double x[MAXN],y[MAXN],r[MAXN];

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,cnt=0;
        double s;
        scanf("%d %lf",&n,&s);
        for(int i=1;i<=n;i++){
            scanf("%lf %lf %lf",&x[i],&y[i],&r[i]);
            for(int j=1;j<=i-1;j++){
                double d=dist(x[i],y[i],x[j],y[j]);
                if(d-r[i]-r[j]<=s)
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
