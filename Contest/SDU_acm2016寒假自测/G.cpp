#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=610;
char mes[305];
char dic[MAXN][30];
int dp[305],len[MAXN];

int main()
{
    int W,L;
    scanf("%d %d",&W,&L);
    scanf("%s",mes);
    for(int i=1;i<=W;i++){
        scanf("%s",dic[i]);
        len[i]=strlen(dic[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=L-1;i>=0;i--){
        dp[i]=dp[i+1]+1;
        for(int j=1;j<=W;j++){
            if(L-i>=len[j]){
                int x=i,y=0;
                while(x<=L-1&&y<len[j]){
                    if(mes[x]==dic[j][y])
                        y++;
                    x++;
                }
                if(y==len[j]&&dp[i]>dp[x]+x-i-len[j])
                    dp[i]=dp[x]+x-i-len[j];
            }
        }
    }
    printf("%d",dp[0]);
    return 0;
}
