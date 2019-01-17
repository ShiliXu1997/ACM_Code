#include<cstdio>
#include<cmath>
using namespace std;

long long fun(int a,int b,int mod)
{
    long long t=1,base=a;
    while(b!=0){
        if(b&1==1)
            t=t*base%mod;
        base=base*base%mod;
        b=b>>1;
    }
    return t;
}

bool isprime(int k)
{
    int t=(int)sqrt(k);
    for(int i=2;i<=t;i++)
        if(k%i==0)return false;
    return true;
}

int main()
{
    int p,a;
    while(scanf("%d %d",&p,&a)==2&&p!=0){
        if(isprime(p))
            printf("no\n");
        else
            if(fun(a,p,p)==a)
                printf("yes\n");
            else
                printf("no\n");
    }
	return 0;
}
