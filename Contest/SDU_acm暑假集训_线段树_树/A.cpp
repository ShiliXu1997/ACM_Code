#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=50005;

struct node{
    int maxone,minone;
};

int n,q;
int a[MAXN];
node dp[MAXN][20];

int query(int l,int r)
{
    int ans,k=log(r-l+1)/log(2),maximum,minimum;
    maximum=max(dp[l][k].maxone,dp[r-(1<<k)+1][k].maxone);
    minimum=min(dp[l][k].minone,dp[r-(1<<k)+1][k].minone);
    ans=maximum-minimum;
    return ans;
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int k=log(n)/log(2);
    for(int j=0;j<=k;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            if(j==0){
                dp[i][j].maxone=a[i];
                dp[i][j].minone=a[i];
                continue;
            }
            dp[i][j].maxone=max(dp[i][j-1].maxone,dp[i+(1<<(j-1))][j-1].maxone);
            dp[i][j].minone=min(dp[i][j-1].minone,dp[i+(1<<(j-1))][j-1].minone);
        }
    }
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",query(a,b));
    }
    return 0;
}
