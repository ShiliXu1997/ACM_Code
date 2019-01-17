#include<cstdio>
using namespace std;

const long long MAXN=25,MOD=1e9+7;

int n;
long long s;
long long f[MAXN];

long long qpow(long long a,long long b)
{
    long long ans=1;
    while(b!=0){
        if(b&1==1)ans=ans*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans;
}

long long comb(long long n,long long m)
{
    if(n<m)return 0;
    if(n-m<m)m=n-m;
    long long numerator=1,denominator=1;
    for(int i=0;i<m;i++){
        numerator=numerator*(n-i)%MOD;
        denominator=denominator*(i+1)%MOD;
    }
    return numerator*qpow(denominator,MOD-2)%MOD;
}

long long lucas(long long n,long long m)
{
    if(m==0)return 1;
    return comb(n%MOD,m%MOD)*lucas(n/MOD,m/MOD)%MOD;
}

int main()
{
    scanf("%d %lld",&n,&s);
    for(int i=1;i<=n;i++)scanf("%lld",&f[i]);
    long long ans=0;
    for(int i=0;i<(1<<n);i++){
        long long sum=s,flag=1;
        for(int j=0;j<n;j++)
            if(i&(1<<j)){
                sum-=(f[j+1]+1);
                flag=-flag;
            }
        if(sum>=0)ans=(ans+lucas(sum+n-1,n-1)*flag)%MOD;
    }
    printf("%lld\n",(ans+MOD)%MOD);
    return 0;
}
