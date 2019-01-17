#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5;

int n;
int a[MAXN];

int lowbit(int x)
{
    return (x&-x);
}

void modify(int x,int num)
{
    while(x<=n){
        a[x]+=num;
        x+=lowbit(x);
    }
}

int sum(int x)
{
    int ans=0;
    while(x>0){
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    while(scanf("%d",&n)==1&&n!=0){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            modify(a,1);
            modify(b+1,-1);
        }
        for(int i=1;i<=n;i++){
            if(i!=1)printf(" ");
            printf("%d",sum(i));
        }
        printf("\n");
    }
    return 0;
}
