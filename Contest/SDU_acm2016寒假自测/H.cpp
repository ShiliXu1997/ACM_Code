#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=400;
long long gra[MAXN][MAXN],sum[MAXN][MAXN];

long long max(const long long a,const long long b)
{
    return (a>b?a:b);
}

int main()
{
    int n;
    memset(gra,0,sizeof(gra));
    memset(sum,0,sizeof(sum));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            scanf("%lld",&gra[i][j]);
            if(j==1)
                sum[i][j]=gra[i][j]+sum[i-1][j];
            else
            if(j==i)
                sum[i][j]=gra[i][j]+sum[i-1][j-1];
            else
                sum[i][j]=gra[i][j]+max(sum[i-1][j-1],sum[i-1][j]);
        }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,sum[n][i]);
    printf("%lld",ans);
	return 0;
}
