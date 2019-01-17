#include<cstdio>
using namespace std;

const int MAXN=100;

int n;
long long f[MAXN];

void func(int x)
{
    f[x]=(x-1)*(f[x-2]+f[x-1]);
}

int main()
{
    f[2]=1;f[3]=2;
    for(int i=4;i<MAXN;i++)func(i);
    while(scanf("%d",&n)==1){
        printf("%lld\n",f[n]);
    }
    return 0;
}
