#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e5+5,MAXD=1005;

int cash,n;
int num[MAXD],den[MAXD];
bool dp[MAXN];

int main()
{
    while(scanf("%d %d",&cash,&n)==2){
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(int i=1;i<=n;i++)
            scanf("%d %d",&num[i],&den[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=num[i];j*=2){
                int vasum=j*den[i];
                for(int k=cash;k>=vasum;k--)
                    if(dp[k-vasum])dp[k]=true;
                num[i]-=j;
            }
            int vasum=num[i]*den[i];
            for(int k=cash;k>=vasum;k--)
                if(dp[k-vasum])dp[k]=true;
        }
        for(int i=cash;i>=0;i--)
            if(dp[i]){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
