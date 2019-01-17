#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=10005;

long long t,n;

long long solve(long long n)
{
    long long ans=0;
    for(int i=1;i<=n;i++){
         ans+=(n-i+1)*(n-i+2)/2;
         if(n>=2*i)ans+=(n-2*i+1)*(n-2*i+2)/2;
    }
    return ans;
}

int main()
{
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",solve(n));
    }
    return 0;
}
