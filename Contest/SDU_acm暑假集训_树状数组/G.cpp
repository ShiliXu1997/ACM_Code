#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=200005;

struct node{
    long long num;
    int id;

    bool operator<(const node &another)const
    {
        if(num==another.num)return id<another.id;
        return num<another.num;
    }
};

int n,k;
long long a[MAXN];
node b[MAXN];

int lowbit(int x)
{
    return (x&-x);
}

void modify(int x,int num)
{
    if(x==0){
        a[x]+=(long long)num;
        return;
    }
    while(x<=n){
        a[x]+=(long long)num;
        x+=lowbit(x);
    }
}

long long sum(int x)
{
    long long ans=a[0];
    while(x>0){
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    scanf("%d %d",&n,&k);
    b[0].num=0;b[0].id=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        b[i].num=b[i-1].num+(long long)(x-k);
        b[i].id=i;
    }
    sort(b,b+1+n);
    long long cnt=0;
    memset(a,0,sizeof(a));
    for(int i=0;i<=n;i++){
        if(b[i].id>0)cnt+=sum(b[i].id-1);
        modify(b[i].id,1);
    }
    printf("%lld\n",cnt);
    return 0;
}
