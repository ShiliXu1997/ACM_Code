#define LOCAL
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long x[15],ans[10];

int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif LOCAL
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long sum=0;
        for(int j=1;j<=10;j++){
            scanf("%lld",&x[j]);
            sum+=x[j];
        }
        sum/=4;
        sort(x+1,x+1+10);
        memset(ans,0,sizeof(ans));
        ans[3]=sum-x[1]-x[10];
        sort(ans+1,ans+1+5);
        printf("Case %d: ",i);
        for(int j=1;j<=5;j++){
            printf("%lld",ans[j]);
            if(j!=5)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
