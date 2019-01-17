#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=500005;

struct point{
    int val,pos;

    bool operator<(const point &another)const
    {
        return val<another.val;
    }
};

int n;
int id[MAXN],num[MAXN];
point a[MAXN];

int lowbit(int x)
{
    return (x&-x);
}

void modify(int x,int add)
{
    while(x<=n){
        num[x]+=add;
        x+=lowbit(x);
    }
}

int sum(int x)
{
    int ans=0;
    while(x>0){
        ans+=num[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    while(scanf("%d",&n)==1&&n!=0){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].val);
            a[i].pos=i;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
            id[a[i].pos]=i;
        memset(num,0,sizeof(num));
        long long ans=0;
        for(int i=1;i<=n;i++){
            modify(id[i],1);
            ans+=(sum(n)-sum(id[i]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
