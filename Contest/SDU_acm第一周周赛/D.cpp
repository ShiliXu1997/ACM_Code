#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1010;
int cash,total;
int n[MAXN],v[MAXN];
int dp[MAXN][MAXN];
bool visited[100010];

int main()
{
    while(scanf("%d %d",&cash,&total)==2){
        for(int i=1;i<=total;i++)
            scanf("%d %d",&n[i],&v[i]);
        memset(visited,false,sizeof(visited));
        memset(dp,0,sizeof(dp));
        visited[0]=true;
        for(int i=1;i<=total;i++)
            if(n[i]>0&&v[i]<=cash)
                for(int j=v[i];j<=cash;j++)
                    if(!visited[j]&&visited[j-v[i]]&&dp[i][j-v[i]]<n[i]){
                        visited[j]=true;
                        dp[i][j]=dp[i][j-v[i]]+1;
                    }
        for(int i=cash;i>=0;i--)
            if(visited[i]){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
