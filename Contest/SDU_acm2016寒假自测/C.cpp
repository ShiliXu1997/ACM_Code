#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e5+10;
bool dp[MAXN];
int sum[MAXN],a[105],c[105];
int n,m;

int main()
{
    while(scanf("%d %d",&n,&m)==2&&n!=0){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        memset(dp,false,sizeof(dp));
        int ans=0;
        dp[0]=true;
        for(int i=1;i<=n;i++){
            memset(sum,0,sizeof(sum));
            for(int j=a[i];j<=m;j++)
                if(!dp[j]&&dp[j-a[i]]&&sum[j-a[i]]<c[i]){
                    dp[j]=true;
                    sum[j]=sum[j-a[i]]+1;
                    ans++;
                }
        }
        printf("%d\n",ans);
    }
	return 0;
}
