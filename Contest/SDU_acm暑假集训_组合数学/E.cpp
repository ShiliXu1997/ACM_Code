#include<cstdio>
using namespace std;

const int MAXK=1e6+5,MOD=1e9+7;

int t;
long long n,m,k;
long long inverse[MAXK],C[MAXK];

long long qpow(long long a,long long b)
{
    long long ans=1;
    while(b!=0){
        if(b&1==1)ans=(ans*a)%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans;
}

void getinverse()
{
    for(long long i=1;i<MAXK;i++)
        inverse[i]=qpow(i,MOD-2);
}

void init(long long n)
{
    C[0]=1;
    for(long long i=1;i<=k;i++)
        C[i]=C[i-1]*(n-i+1)%MOD*inverse[i]%MOD;
}

long long comb(long long n,long long m)
{
    if(n<m)return 0;
    if(n-m<m)m=n-m;
    long long numerator=1,denominator=1;
    for(long long i=0;i<m;i++){
        numerator=numerator*(n-i)%MOD;
        denominator=denominator*(i+1)%MOD;
    }
    return numerator*qpow(denominator,MOD-2)%MOD;
}

int main()
{
    getinverse();
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%lld %lld %lld",&n,&m,&k);
        init(k);
        long long ans=0,flag=1;
        for(long long i=k;i>=1;i--){
            ans=(ans+flag*i*qpow(i-1,n-1)%MOD*C[i]%MOD+MOD)%MOD;
            flag=-flag;
        }
        ans=ans*comb(m,k)%MOD;
        printf("Case #%d: %lld\n",kase,ans);
    }
    return 0;
}
