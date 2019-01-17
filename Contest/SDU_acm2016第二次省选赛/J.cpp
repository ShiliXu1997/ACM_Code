#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1050;

int value[MAXN];
int dp[MAXN][MAXN];

int max(const int a,const int b)
{
    return (a>b?a:b);
}

int deepsearch(int left,int right)
{
    if(left>right)
        return 0;
    if(dp[left][right]==0){
        int takeleft,takeright;
        if(value[left+1]>=value[right])
            takeleft=deepsearch(left+2,right)+value[left];
        else
            takeleft=deepsearch(left+1,right-1)+value[left];
        if(value[left]>=value[right-1])
            takeright=deepsearch(left+1,right-1)+value[right];
        else
            takeright=deepsearch(left,right-2)+value[right];
        dp[left][right]=max(takeleft,takeright);
    }
    return dp[left][right];
}

int main()
{
    int n,cnt=0;
    while(scanf("%d",&n)==1&&n!=0){
        memset(dp,0,sizeof(dp));
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&value[i]);
            sum+=value[i];
        }
        int sum1,sum2;
        sum1=deepsearch(1,n);
        sum2=sum-sum1;
        int ans=sum1-sum2;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++cnt,ans);
    }
    return 0;
}
