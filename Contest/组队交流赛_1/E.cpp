#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

int n;
long long m[MAXN][MAXN];
long long sum[MAXN];

int main()
{
    scanf("%d",&n);
    memset(sum,0,sizeof(sum));
    long long tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%lld",&m[i][j]);
            sum[i]+=m[i][j];
            tot+=m[i][j];
        }
    if(n==1)
        printf("1\n");
    else{
        tot/=(n-1);
        for(int i=1;i<=n;i++)m[i][i]=tot-sum[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++)
                printf("%lld ",m[i][j]);
            printf("%lld\n",m[i][n]);
        }
    }
    return 0;
}
