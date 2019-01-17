#include<cstdio>
using namespace std;

const int MAXN=1050,INF=0x3f3f3f3f;

int max(const int a,const int b)
{
    return (a>b?a:b);
}

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        ans=max(ans,x);
    }
    printf("%d\n",ans);
    return 0;
}
