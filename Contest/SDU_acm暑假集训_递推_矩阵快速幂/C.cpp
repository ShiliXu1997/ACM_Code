#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=55;

int n,a,b;
long long ans[MAXN][MAXN];

int main()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=50;i++)ans[i][i]=1;
    for(int j=1;j<=50;j++)
        for(int i=j-1;i>=1;i--)ans[i][j]=ans[i+1][j]+ans[i+2][j];
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        printf("%lld\n",ans[a][b]);
    }
    return 0;
}
