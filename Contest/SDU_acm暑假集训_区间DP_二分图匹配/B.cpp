#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN=705,MOD=1e9+7;

char str[MAXN];
int len;
int match[MAXN];
long long dp[MAXN][MAXN][3][3];
stack<int> s;

void getmatch()
{
    for(int i=0;i<len;i++)
        if(str[i]=='(')
           s.push(i);
        else{
            match[i]=s.top();
            match[s.top()]=i;
            s.pop();
        }
}

void dfs(int left,int right)
{
    if(left+1==right){
        dp[left][right][0][1]=1;
        dp[left][right][1][0]=1;
        dp[left][right][0][2]=1;
        dp[left][right][2][0]=1;
    }
    else{
        if(match[left]==right){
            dfs(left+1,right-1);
            for(int k=0;k<3;k++)
                for(int l=0;l<3;l++){
                    if(l!=1)
                        dp[left][right][0][1]=(dp[left][right][0][1]+dp[left+1][right-1][k][l])%MOD;
                    if(k!=1)
                        dp[left][right][1][0]=(dp[left][right][1][0]+dp[left+1][right-1][k][l])%MOD;
                    if(l!=2)
                        dp[left][right][0][2]=(dp[left][right][0][2]+dp[left+1][right-1][k][l])%MOD;
                    if(k!=2)
                        dp[left][right][2][0]=(dp[left][right][2][0]+dp[left+1][right-1][k][l])%MOD;
                }
        }
        else{
            int mid=match[left];
            dfs(left,mid);
            dfs(mid+1,right);
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    for(int k=0;k<3;k++)
                        for(int l=0;l<3;l++)
                            if(!(k==1&&l==1)&&!(k==2&&l==2))
                                dp[left][right][i][j]=(dp[left][right][i][j]+dp[left][mid][i][k]*dp[mid+1][right][l][j]%MOD)%MOD;
        }
    }
}

int main()
{
    scanf("%s",str);
    len=strlen(str);
    getmatch();
    memset(dp,0,sizeof(dp));
    dfs(0,len-1);
    long long ans=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ans=(ans+dp[0][len-1][i][j])%MOD;
    printf("%lld",ans);
    return 0;
}
