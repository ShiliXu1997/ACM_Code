#include<cstdio>
using namespace std;

int fun(int a,int b,int mod)
{
    int t=1,base=a;
    while(b!=0){
        base=base%mod;
        if(b&1==1)
            t=t*base%mod;
        base=base*base%mod;
        b=b>>1;
    }
    return t;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int sum=0,m,h;
        scanf("%d %d",&m,&h);
        while(h--){
            int a,b;
            scanf("%d %d",&a,&b);
            sum=(sum+fun(a,b,m))%m;
        }
        printf("%d\n",sum);
    }
	return 0;
}

