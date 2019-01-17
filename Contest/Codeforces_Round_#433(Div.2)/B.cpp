#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,k;

int main()
{
    scanf("%lld %lld",&n,&k);
    if(n==1||k==0||n==k)
        printf("0 0\n");
    else
        printf("1 %lld\n",min(n-k,k*2));
    return 0;
}
