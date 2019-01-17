#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

char s[MAXN];
long long dp[MAXN][MAXN];

void dfs(int left,int right)
{
    if(dp[left][right]!=-1)return;
    if(left>=right)
        dp[left][right]=0;
    else{
        if(s[left]=='('&&s[right]==')'||s[left]=='['&&s[right]==']'){
            dfs(left+1,right-1);
            dp[left][right]=dp[left+1][right-1]+2;
        }
        for(int mid=left;mid<right;mid++){
            dfs(left,mid);
            dfs(mid+1,right);
            dp[left][right]=max(dp[left][right],dp[left][mid]+dp[mid+1][right]);
        }
    }
}

int main()
{
    while(scanf("%s",s)==1&&s[0]!='e'){
        memset(dp,-1,sizeof(dp));
        int len=strlen(s);
        for(int i=len-1;i>=0;i--)
            for(int j=i+1;j<=len-1;j++)
                dfs(i,j);
        printf("%lld\n",dp[0][len-1]==-1?0:dp[0][len-1]);
    }
    return 0;
}
