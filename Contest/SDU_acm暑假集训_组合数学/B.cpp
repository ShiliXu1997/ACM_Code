#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

long long n,k;

int main()
{
    scanf("%lld %lld",&n,&k);
    long long ans=0,a=(long long)sqrt(k),b=k/a;
    for(long long i=a;i>1;i--){
        long long s=k/i,e=k/(i-1);
        if(e>n)e=n;
        if(s>n)break;
        ans+=(k%(s+1)+k%e)*(e-s)/2;
    }
    for(long long i=1;i<=b&&i<=n;i++)ans+=k%i;
    if(n>k)ans+=(n-k)*k;
    printf("%lld",ans);
    return 0;
}
