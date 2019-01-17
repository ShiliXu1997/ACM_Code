#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=5e5+5,INF=0x3f3f3f3f;

int n,k,ans;
int c[MAXN];

bool func_1(int x)
{
    int sum=0,i=1;
    while(c[i]<x&&i<=n){
        sum+=x-c[i++];
        if(sum>k)return false;
    }
    if(sum<=k)return true;
}

bool func_2(int x)
{
    int sum=0,i=n;
    while(c[i]>x&&i>=1){
        sum+=c[i--]-x;
        if(sum>k)return false;
    }
    if(sum<=k)return true;
}

int binsearch_1(const int left,const int right)
{
    int l=left,r=right;
    while(l<r){
        int mid=(l+r)>>1;
        if(func_1(mid))
            l=mid;
        else
            r=mid-1;
        if(l+1==r)
            if(func_1(r))
                l=r;
            else
                r=l;
    }
    return l;
}

int binsearch_2(const int left,const int right)
{
    int l=left,r=right;
    while(l<r){
        int mid=(l+r)>>1;
        if(func_2(mid))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    sort(c+1,c+1+n);
    if(k==0)
        ans=c[n]-c[1];
    else
        ans=binsearch_2(c[1],c[n])-binsearch_1(c[1],c[n]);
    if(ans>0)
        printf("%d",ans);
    else{
        long long sum=0;
        for(int i=1;i<=n;i++)sum+=c[i];
        if(sum%n==0)
            ans=0;
        else
            ans=1;
        printf("%d",ans);
    }
    return 0;
}
