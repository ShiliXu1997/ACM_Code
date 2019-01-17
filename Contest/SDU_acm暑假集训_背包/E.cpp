#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=3005;

int n;
int a[MAXN],b[MAXN];
long long dp[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]-=i;
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j==1)
                dp[j]+=abs(a[i]-b[j]);
            else
                dp[j]=min(dp[j-1],dp[j]+abs(a[i]-b[j]));
    printf("%lld",dp[n]);
    return 0;
}
