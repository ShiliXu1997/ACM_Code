#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=1005;

struct buyer{
    int x,b;
    bool operator<(const buyer &another)const
    {
        return x<another.x;
    }
};

int n,v,origin;
buyer a[MAXN];
long long sum[MAXN];
long long dp[MAXN][MAXN][2];

int main()
{
    while(scanf("%d %d %d",&n,&v,&origin)==3){
        for(int i=1;i<=n;i++)scanf("%d %d",&a[i].x,&a[i].b);
        sort(a+1,a+1+n);
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i].b;
        for(int i=1;i<=n;i++){
            dp[i][i][0]=sum[n]*abs(origin-a[i].x);
            dp[i][i][1]=sum[n]*abs(origin-a[i].x);
        }
        for(int l=2;l<=n;l++)
            for(int i=1;i<=n-l+1;i++){
                int j=i+l-1;
                dp[i][j][0]=min(dp[i+1][j][0]+(sum[n]-sum[j]+sum[i])*(a[i+1].x-a[i].x),dp[i+1][j][1]+(sum[n]-sum[j]+sum[i])*(a[j].x-a[i].x));
                dp[i][j][1]=min(dp[i][j-1][0]+(sum[n]-sum[j-1]+sum[i-1])*(a[j].x-a[i].x),dp[i][j-1][1]+(sum[n]-sum[j-1]+sum[i-1])*(a[j].x-a[j-1].x));
            }
        long long ans=min(dp[1][n][0]*v,dp[1][n][1]*v);
        printf("%lld\n",ans);
    }
    return 0;
}
