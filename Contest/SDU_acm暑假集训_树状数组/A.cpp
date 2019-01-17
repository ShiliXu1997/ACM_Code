#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=15005,MAXM=32005;

int n;
int a[MAXM],ans[MAXN];

int lowbit(int x)
{
    return (x&-x);
}

void modify(int x,int num)
{
    if(x==0)
        a[0]+=num;
    else{
        while(x<=MAXM){
            a[x]+=num;
            x+=lowbit(x);
        }
    }
}

int sum(int x)
{
    int ans=0;
    while(x>0){
        ans+=a[x];
        x-=lowbit(x);
    }
    ans+=a[0];
    return ans;
}

int main()
{
    while(scanf("%d",&n)==1){
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            ans[sum(x)]++;
            modify(x,1);
        }
        for(int i=0;i<=n-1;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
