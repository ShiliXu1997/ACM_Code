#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=60010;
const double EPS=1e-8,PI=3.1415926535,G=9.8;

int t,h,v;
double y,ans;

double func(double x)
{
    double time,s;
    time=(v*sin(x)+sqrt(v*v*sin(x)*sin(x)+2*G*h))/G;
    s=v*cos(x)*time;
    return s;
}

double trisearch(const double left,const double right)
{
    double l=left,r=right;
    for(int i=1;i<=100;i++){
        double lmid=l+(r-l)/3,rmid=r-(r-l)/3;
        if(func(lmid)-func(rmid)<=EPS)
            l=lmid;
        else
            r=rmid;
    }
    return func(l);
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&h,&v);
        printf("%.2f\n",trisearch(0,PI/2));
    }
    return 0;
}
