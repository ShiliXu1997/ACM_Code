#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=40005;

int w,h,n;
int x[MAXN],y[MAXN];

int max(const int a,const int b)
{
    return (a>b?a:b);
}

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    scanf("%d %d %d",&w,&h,&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&x[i],&y[i]);
    x[0]=0;y[0]=0;
    x[n+1]=w+1;y[n+1]=h+1;
    sort(x,x+n+1);
    int maxx=0,maxy=0;
    for(int i=0;i<=n;i++)
        maxx=max(maxx,x[i+1]-x[i]-1);
    sort(y,y+n+1);
    for(int i=0;i<=n;i++)
        maxy=max(maxy,y[i+1]-y[i]-1);
    printf("%d",maxx*maxy);
    return 0;
}
close
