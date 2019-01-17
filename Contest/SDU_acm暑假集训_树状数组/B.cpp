#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5;

int n;
long long a[MAXN],s[MAXN];

int lowbit(int x)
{
    return (x&-x);
}

void modify(int x,int num)
{
    int add=x*num;
    while(x<MAXN){
        a[x]+=num;
        s[x]+=add;
        x+=lowbit(x);
    }
}

long long num(int x)
{
    long long ans=0;
    while(x>0){
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}

long long sum(int x)
{
    long long ans=0;
    while(x>0){
        ans+=s[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    scanf("%d",&n);
    long long ans=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        modify(x,1);
        ans+=(num(n)-num(x))*x;
        ans+=(sum(n)-sum(x));
    }
    printf("%lld\n",ans);
    return 0;
}
