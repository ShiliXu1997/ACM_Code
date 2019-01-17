#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005;

int t,n,k;
int a[MAXN];

bool ok(long long x)
{
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=min(x,(long long)a[i]);
    return sum>=x*k;
}

long long binsearch(long long left,long long right)
{
    long long l=left,r=right;
    while(l+1<r){
        long long mid=(l+r)/2;
        if(ok(mid))
            l=mid;
        else
            r=mid-1;
    }
    if(ok(r))
        return r;
    else
        return l;
}

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%d %d",&n,&k);
        long long sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        long long ans=binsearch(0,sum/k);
        printf("Case %d: %lld\n",kase,ans);
    }
    return 0;
}
