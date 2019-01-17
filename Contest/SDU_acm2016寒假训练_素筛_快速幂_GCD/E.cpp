#include<cstdio>
using namespace std;

long long x,y;

long long extgcd(long long a,long long b)
{
    if(b==0){
        x=1;y=0;
        return a;
    }
    else{
        long long d,t;
        d=extgcd(b,a%b);
        t=x;x=y;
        y=t-a/b*y;
        return d;
    }
}

int main()
{
    int X,Y,m,n,L;
    scanf("%d %d %d %d %d",&X,&Y,&m,&n,&L);
    int d=extgcd(n-m,L);
    if((X-Y)%d!=0)
        printf("Impossible");
    else{
        int r=L/d;
        int ans=((X-Y)/d*x%r+r)%r;
        printf("%d",ans);
    }
	return 0;
}
