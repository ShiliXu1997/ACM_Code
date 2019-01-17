#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5,INF=0x3f3f3f3f;

int n,k;
int x[MAXN];

bool func(int num)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        sum=sum+upper_bound(x+1,x+1+n,x[i]+num)-x-1-i;
    if(sum>=k)
        return true;
    else
        return false;
}

int binsearch(const int left,const int right)
{
    int l=left,r=right;
    while(l<r){
        int mid=(l+r)>>1;
        if(func(mid))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

int main()
{
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++)scanf("%d",&x[i]);
        sort(x+1,x+1+n);
        k=(n*(n-1)/2+1)/2;
        printf("%d\n",binsearch(0,x[n]-x[1]));
    }
    return 0;
}
