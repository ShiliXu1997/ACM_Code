#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5;

int n;
long long a[MAXN],b[MAXN],cnt[MAXN];
long long dp[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int tot=unique(b+1,b+1+n)-(b+1);
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)cnt[a[i]]++;
    for(int i=1;i<=tot;i++){
        if(i==1)
            dp[i]=b[i]*cnt[b[i]];
        else
        if(b[i]-1>b[i-1])
            dp[i]=dp[i-1]+b[i]*cnt[b[i]];
        else{
            dp[i]=dp[i-2]+b[i]*cnt[b[i]];
            dp[i]=max(dp[i],dp[i-1]);
        }
    }
    printf("%lld",dp[tot]);
    return 0;
}
