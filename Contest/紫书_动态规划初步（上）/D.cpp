#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=102,MAXM=12;
const long long INF=0x3f3f3f3f3f3f3f3f;

int m,n;
int gra[MAXM][MAXN];
long long dp[MAXM][MAXN];
string route[MAXM][MAXN];

void dfs(int deep,int r)
{
    if(dp[r][deep]!=INF||deep==n-1)return;
    bool flag_up=false,flag_down=false;
    for(int i=0;i<=2;i++){
        string tmp=string(1,(char)(r+'0'));
        int nextrow=r+i-1;
        if(nextrow==-1){
            nextrow=m-1;
            flag_up=true;
        }
        if(nextrow==m){
            nextrow=0;
            flag_down=true;
        }
        dfs(deep+1,nextrow);
        if(dp[r][deep]>=gra[r][deep]+dp[nextrow][deep+1]){
            if(dp[r][deep]>gra[r][deep]+dp[nextrow][deep+1]){
                dp[r][deep]=gra[r][deep]+dp[nextrow][deep+1];
                route[r][deep]=tmp+route[nextrow][deep+1];
            }
            else{
                if(flag_up&&(nextrow==r||dp[nextrow][deep+1]<dp[r][deep+1])||flag_down)
                    route[r][deep]=tmp+route[nextrow][deep+1];
            }
        }
    }
}

void print_route(int i,int j)
{
    int len=route[i][j].length();
    for(int index=0;index<len;index++){
        printf("%d",route[i][j][index]-'0'+1);
        if(index!=len-1)printf(" ");
    }
    printf("\n");
}

int main()
{
    while(scanf("%d %d",&m,&n)==2){
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&gra[i][j]);
                if(j==n-1){
                    dp[i][j]=gra[i][j];
                    route[i][j]=string(1,(char)(i+'0'));
                }
            }
        long long ans=INF;
        for(int i=0;i<m;i++){
            dfs(0,i);
            ans=min(ans,dp[i][0]);
        }
        for(int i=0;i<m;i++)
            if(dp[i][0]==ans){
                print_route(i,0);
                printf("%lld\n",ans);
                break;
            }
    }
    return 0;
}
